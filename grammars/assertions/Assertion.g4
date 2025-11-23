grammar Assertion;

// Parser rules
assertion : distribution_assertion EOF ;

// distribution assertions
distribution_assertion
    : dis_or_expr
    ;

// OR has lowest precedence
dis_or_expr
    : dis_and_expr ('or' dis_and_expr)*;

// AND has medium precedence
dis_and_expr
    : dis_conv_expr ('and' dis_conv_expr)*;

dis_conv_expr
    : dis_not_expr ('+' dis_not_expr)*;

// NOT has highest precedence
dis_not_expr
    : '!' dis_not_expr
    | '(' distribution_assertion ')'
    | probability_term RP REALNUM;

// probability term
probability_term
    : 'P' '(' states_assertion ')'
    | REALNUM
    ;

// states assertion
states_assertion
    : states_or_expr
    ;

states_or_expr
    : states_and_expr ('or' states_and_expr)*   # or_expr
    ;

states_and_expr
    : states_not_expr ('and' states_not_expr)*  # and_expr
    ;

states_not_expr
    : '!' states_not_expr               # not_expr
    | quantum_term '=' quantum_term           # QCompare
    | binary_term '=' binary_term           # BCompare
    | '(' states_assertion ')'           # Parens
    ;

binary_term
    : '[' BList ']'          
    | BINARYSTRING
    ;

quantum_term
    : '[' QList ']'
    | Row
    ;

// matrices
matrix : '[' Row (',' Row)* ']';
Row : '[' REALNUM (',' REALNUM)* ']';


// binary strings


// Binary list
BList : CID (',' CID)* ;

// Quantum list
QList : QID (',' QID)* ;


// Lexer rules (uppercase usually)

RP : '=' | '>' | '>=' | '<=';
ROP: MOP | '/';
MOP : '+' | '-' | '*';
REALNUM : [0-9]+ ('.' [0-9]+)?;
CID  : 'x' [0-9]* ;
QID : 'q' [0-9]* ;
INT : [0-9]+ ;

