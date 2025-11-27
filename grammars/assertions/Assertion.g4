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
    : dis_not_expr # conv_simple_case
    | dis_not_expr '+' dis_not_expr # conv_complex_case
    ;

// NOT has highest precedence
dis_not_expr
    : '!' dis_not_expr # dis_not
    | '(' distribution_assertion ')' # dis_assertion
    | probability_term '>=' REALNUM # dis_prob_assertion
    ;

// probability term
probability_term
    : 'P' '(' states_assertion ')' # symbolic_prob
    | REALNUM # concrete_prob
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
    : '[' bList ']' # list_b_vars
    | BINARYSTRING # bin_str
    ;

quantum_term
    : '[' qList ']' # list_q_vars
    | row # quantum_state
    ;

// matrices
row : '[' REALNUM (',' REALNUM)* ']';

// Binary list
bList : CID (',' CID)* ;

// Quantum list
qList : QID (',' QID)* ;


// Lexer rules (uppercase usually)
BINARYSTRING: ( '0' | '1' )+;
REALNUM : [0-9]+ ('.' [0-9]+)?;
CID  : 'x' [0-9]* ;
QID : 'q' [0-9]* ;
WS : [ \t\r\n]+ -> skip ;

