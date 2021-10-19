// MultStatement.h

#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "Statement.h"

class MultStatement : public Statement {
private:
    // Variable to change
    std::string m_variableName;
    // Variable to multply
    std::string m_var_to_mult;
    // Integer to multiply
    int m_value_to_mult;
    // Checking if multiplying by variable or integer
    bool mult_var;

public:
    // Constructor for multiplying variable
    MultStatement(std::string variableName, std::string var_to_mult);
    // Constructor for multiplying integer
    MultStatement(std::string variableName, int value_to_mult);

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif