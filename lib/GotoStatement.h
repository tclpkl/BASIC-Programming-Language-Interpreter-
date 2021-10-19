// GotoStatement.h

#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class GotoStatement : public Statement {
private:
    // Line to go to
    int m_go_to_line;

public:
    GotoStatement(int go_to_line);

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif