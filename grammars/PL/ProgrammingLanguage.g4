grammar ProgrammingLanguage;
// antlr4 -Dlanguage=Cpp -visitor ./grammars/PL/ProgrammingLanguage.g4
// Parser rules
language : program EOF ;


program
    : SKIPKW                               # Skip
    | classical_statement                   # Classical
    | UNITARY LPAREN LBRACKET qlist RBRACKET RPAREN  # Unitary
    | program SEMICOLON program             # Seq
    | IF LPAREN CID RPAREN LBRACE program RBRACE
      ELSE LBRACE program RBRACE            # If
    | program PERCENT REALNUM PERCENT program # Prob
    ;


classical_statement
    : CID ':=' '0'                                # AssignZero
    | CID ':=' '1'                                # AssignOne
    | CID ':=' CID                                # AssignCopy
    | CID ':=' MEASURE LPAREN QID RPAREN          # AssignMeasure
    ;

MEASURE : 'measure' ;
SKIPKW : 'skip';
SEMICOLON : ';';
IF : 'if';
ELSE : 'else';
LPAREN : '(';
RPAREN : ')';
LBRACE : '{';
RBRACE : '}';
LBRACKET : '[';
RBRACKET : ']';
PERCENT : '%';

// Quantum list
qlist : QID (',' QID)* ;
WS : [ \t\r\n]+ -> skip ;
UNITARY: 'X' | 'CX' | 'H';
REALNUM : [0-9]+ ('.' [0-9]+)?;
CID  : 'x' [0-9]+ ;
QID : 'q' [0-9]+ ;