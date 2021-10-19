// IfThenStatement.h

#ifndef IFTHEN_STATEMENT_INCLUDED
#define IFTHHEN_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class IfThenStatement : public Statement {
private:
    // Variable to compare
    std::string variableName;
    // Comparison operator
    std::string m_ope;
    // Value to be compared
    int m_value;
    // Line to go to
    int m_go_to_line;

public:
    IfThenStatement(std::string var, std::string ope, int value, int go_to_line);

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif