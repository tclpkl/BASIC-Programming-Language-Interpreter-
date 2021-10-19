// PrintAllStatement.h
#ifndef PRINTALL_STATEMENT_INCLUDED
#define PRINTALL_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class PrintAllStatement : public Statement {
public:
    PrintAllStatement();

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif
