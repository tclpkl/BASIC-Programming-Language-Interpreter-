// DivStatement.h

#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "Statement.h"

class DivStatement : public Statement {
private:
    // Variable to change
    std::string m_variableName;
    // Variable to diide
    std::string m_var_to_div;
    // Integer to divide
    int m_value_to_div;
    // Checking if dividing variable or integer
    bool div_var;

public:
    // Constructor for dividing variable
    DivStatement(std::string variableName, std::string var_to_div);
    // Constructor for dividing integer
    DivStatement(std::string variableName, int value_to_div);

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif