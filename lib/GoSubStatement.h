// GoSubStatement.h

#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class GoSubStatement : public Statement {
private:
    // Line to go to
    int m_go_to_line;

public:
    GoSubStatement(int go_to_line);

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif