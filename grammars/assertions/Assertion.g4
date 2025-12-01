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
    | 'P' '(' states_assertion ')' '>=' REALNUM  # symbolic_prob
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
    :  qList  '=' row # qterm
    |  bList  '=' BINARYSTRING # bterm
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
CID  : 'x' [0-9]+ ;
QID : 'q' [0-9]+ ;
WS : [ \t\r\n]+ -> skip ;

