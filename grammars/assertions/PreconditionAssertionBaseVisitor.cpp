
// Generated from ../grammars/assertions/PreconditionAssertion.g4 by ANTLR 4.13.2

#include "ensemble.hpp"
#include "boost_clean.hpp"
#include "include/experiments.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include "PreconditionAssertionBaseVisitor.h"
#include "antlr4-runtime.h"
#include <cassert>
#include <vector>


using namespace std;

struct CanonState {
    std::vector<int> qvars;      // QList
    std::vector<double> row;     // Row
    std::vector<int> cvars;      // BList
    std::string bitstring;       // BINARYSTRING
};

class PreconVisitor : public PreconditionAssertionBaseVisitor {
    void check_qvars(const vector<int> &qvars) {
        assert (qvars.size() == this->num_qvars);
        // check they are sorted and are sequential
        assert (qvars[0] == 0);
        for (int i = 1; i < qvars.size(); i++) {
            assert (qvars[i]-1 == qvars[i-1]);
        }
    }

    void check_row(const vector<double> &row) {
        // cout << "num qvars: " << this->num_qvars << endl;
        // cout << "row: " << row.size() << endl;
        // for (auto e : row) {
        //     cout << e << " ";
        // }
        // cout << endl;
        assert (row.size() == pow(2, this->num_qvars));
    }

    void check_bitstring(const string &bitstring) {
        assert(bitstring.size() == this->num_cvars);
    }

    void check_cvars(const vector<int> &cvars) {
        // assert (cvars.size() == this->num_cvars);
        // assert (cvars[0] == 0);
        // for (int i = 1; i < cvars.size(); i++) {
        //     assert (cvars[i]-1 == cvars[i-1]);
        // }
    }
public:

    int num_qvars;
    int num_cvars;
    int precision;
    unordered_map<int, int> embedding;
    PreconVisitor(int _num_qvars, int _num_cvars, int _precision, const unordered_map<int, int> &embedding_) : num_qvars(_num_qvars), num_cvars(_num_cvars), precision(_precision), embedding(embedding_) {};
    // Visit the top-level assertion
    antlrcpp::Any visitPrecon_assertion(
        PreconditionAssertionParser::Precon_assertionContext *ctx
    ) override
    {
        assert(this->num_qvars > 0);
        assert(this->num_cvars > 0);
        return visit(ctx->distribution_assertion());
    }

    // Extract all single distributions
    antlrcpp::Any visitDistribution_assertion(
        PreconditionAssertionParser::Distribution_assertionContext *ctx
    ) override
    {
        std::vector<Polygon<double>> polygons; // each vector in this vector is a polygon
        for (auto sd : ctx->polygon_assertion()) {
            auto temp_e = std::any_cast<Polygon<double>>(visitPolygon_assertion(sd));
            polygons.push_back(
                temp_e
            );
        }
        return polygons;
    }

    antlrcpp::Any visitPolygon_assertion(PreconditionAssertionParser::Polygon_assertionContext *ctx) override {
        Polygon<double> polygon;
        for (auto sd : ctx->single_distribution()) {
            auto temp = std::any_cast<Ensemble<double>>(visitSingle_distribution(sd));
            polygon.corners.push_back(make_shared<Ensemble<double>>(temp));
        }
        return polygon;
    }

    cpp_int get_true_basis(const int &basis) {
        unordered_map<int, int> logical_to_value;
        for (auto p : this->embedding) {
            if (basis & (1 << p.first)) {
                logical_to_value[p.first] = 1;
            } else {
                logical_to_value[p.first] = 0;
            }
        }

        cpp_int result = 0;
        for (auto p : this->embedding) {
            if (logical_to_value[p.first]) {
                cpp_int one = 1;
                result += (one << p.second);
            }
        }
        return result;
    }

    // Build one distribution
    antlrcpp::Any visitSingle_distribution(
        PreconditionAssertionParser::Single_distributionContext *ctx
    ) override
    {

        Ensemble<double> ensemble(this->precision);

        for (auto clause : ctx->canon_clause()) {
            auto entry =
                std::any_cast<std::pair<CanonState,double>>(visitCanon_clause(clause));
            this->check_qvars(entry.first.qvars);
            this->check_bitstring(entry.first.bitstring);
            this->check_cvars(entry.first.cvars);
            this->check_row(entry.first.row);
            shared_ptr<QuantumState> qs = make_shared<QuantumState>(Experiment::get_qubits_used(this->embedding), this->precision);
            qs->sparse_vector.clear();
            for (int i = 0; i < entry.first.row.size(); i++) {
                if (entry.first.row[i] != 0) {
                    qs->insert_amplitude(get_true_basis(i), complex<double>(entry.first.row[i], 0));
                }
            }

            shared_ptr<ClassicalState> cs = make_shared<ClassicalState>();
            for (int i = 0; i < entry.first.bitstring.size(); i++) {
                if (entry.first.bitstring.at(i) == '1') {
                    cs = cs->write(i, true);
                } else {
                    assert(entry.first.bitstring.at(i) == '0');
                }

            }

            shared_ptr<HybridState> hybrid_state = make_shared<HybridState>(qs, cs);
            ensemble.add_prob(hybrid_state, entry.second);
        }

        return ensemble;
    }

    // Each canon clause: P(state) = p
    antlrcpp::Any visitCanon_clause(
        PreconditionAssertionParser::Canon_clauseContext *ctx
    ) override
    {
        CanonState st = std::any_cast<CanonState>(visitCanon_state(ctx->canon_state()));
        double prob = std::stod(ctx->REALNUM()->getText());
        return std::make_pair(st, prob);
    }

    //
    //   '[' QList ']' '=' Row
    //   'and'
    //   '[' BList ']' '=' BINARYSTRING
    antlrcpp::Any visitCanon_state(
        PreconditionAssertionParser::Canon_stateContext *ctx
    ) override
    {
        CanonState st;
        // Quantum
        st.qvars = parseQList(ctx->qList());
        st.row = parseRow(ctx->row());

        // Classics
        st.cvars = parseBList(ctx->bList());
        assert(ctx->BINARYSTRING()->getText().size() > 0);
        assert(ctx->BINARYSTRING()->getText().at(0) == 'b');
        st.bitstring = ctx->BINARYSTRING()->getText().substr(1);
        return st;
    }

private:
    // Parse QIDs list
    std::vector<int> parseQList(
        PreconditionAssertionParser::QListContext *q
    ) {
        std::vector<int> out;
        for (auto id : q->QID()) {
            string s_id = id->getText();
            assert(s_id.size() > 1);
            out.push_back(std::stoi(s_id.substr(1)));
        }
        return out;
    }

    // Parse classical IDs list
    std::vector<int> parseBList(
        PreconditionAssertionParser::BListContext *b
    ) {
        std::vector<int> out;
        for (auto id : b->CID()) {
            string s_id = id->getText();
            assert(s_id.size() > 1);
            out.push_back(std::stoi(s_id.substr(1)));
        }
        return out;
    }

    // Parse Row = [ 0.1 , 0.9 ]
    std::vector<double> parseRow(
        PreconditionAssertionParser::RowContext *r
    ) {
        std::vector<double> vals;
        for (auto n : r->REALNUM()) {
            vals.push_back(std::stod(n->getText()));
        }
        return vals;
    }
};


