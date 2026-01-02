grammar PreconditionAssertion;

precon_assertion : distribution_assertion EOF ;


distribution_assertion
    :  polygon_assertion ('or' polygon_assertion)*;

polygon_assertion
    : single_distribution ('+' single_distribution)*;

single_distribution
    : canon_clause ('and' canon_clause)*;

canon_clause
    : 'P(' canon_state ')' '=' REALNUM ;

canon_state
    : '[' qList ']' '=' row 'and' '[' bList ']' '=' BINARYSTRING ;

row : '[' REALNUM (',' REALNUM)* ']';

// Binary list
bList : CID (',' CID)* ;

// Quantum list
qList : QID (',' QID)* ;
BINARYSTRING: ( '0' | '1' )+;
REALNUM : [0-9]+ ('.' [0-9]+)?;
CID  : 'x' [0-9]* ;
QID : 'q' [0-9]* ;
WS : [ \t\r\n]+ -> skip ;
