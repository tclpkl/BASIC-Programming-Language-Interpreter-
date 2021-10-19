// EndStatement.h
#ifndef END_STATEMENT_INCLUDED
#define END_STATEMENT_INCLUDED

#include "Statement.h"

class EndStatement : public Statement {
public:
    EndStatement();

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif
