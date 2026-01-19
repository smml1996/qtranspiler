grammar Assertion;

// Parser rules
assertion : distribution_assertion EOF ;

// distribution assertions
distribution_assertion
    : dis_or_expr
    ;

//// OR has lowest precedence
dis_or_expr
    : dis_and_expr ('or' dis_and_expr)*;
//
//// AND has medium precedence
dis_and_expr
    : dis_conv_expr ('and' dis_conv_expr)*;

dis_conv_expr
    : dis_not_expr ('+' dis_not_expr)*
    ;

//// NOT has highest precedence
dis_not_expr
    : '!' dis_not_expr # dis_not
    | dis_atom # dis_not_atom
    ;

dis_atom
    : '(' distribution_assertion ')' # dis_assertion
    | prob_term RELOP prob_term # atom_terminal
    ;

prob_term
    : 'Tr' '(' qTerm2 ')'  # trace_prob
    | 'P' '(' states_assertion ')'  # symbolic_prob
    | REALNUM # const_prob
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
    | states_atom # states_atom_rule
    ;

states_atom
    :  qList  '=' qTerm2 # qterm
    |  bList  '=' BINARYSTRING # bterm
    ;

qTerm2
    : vector                          # vectorTerm
    | matrix MUL vector               # matrixVectorTerm
    ;

// A vector can be a qList, a numeric row, or a ket row
vector
    : qList                           # qVarVector
    | row                             # numericVector
    ;

// matrices
row : '[' complexNumber (',' complexNumber)* ']';

complexNumber
    : realPart imagPart?              # complexRealImag;

realPart
    : SIGN? REALNUM
    ;

imagPart
    : SIGN? REALNUM? 'i'
    ;

matrix
    : '[[' row ';' row (';' row)* ']]';

// Binary list
bList : CID (',' CID)* ;

// Quantum list
qList : QID (',' QID)* ;


// Lexer rules (uppercase usually)
MUL : '*' | '·';
RELOP: '>=' | '<=' | '=' | '<' | '>' ;
SIGN : [+-];
REALNUM : [0-9]+ ('.' [0-9]+)?;
BINARYSTRING: 'b'( '0' | '1' )+;
CID  : 'x' [0-9]+ ;
QID : 'q' [0-9]+ ;
WS : [ \t\r\n]+ -> skip ;

