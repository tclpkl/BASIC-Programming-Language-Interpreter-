// SubStatement.h

#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED

#include "Statement.h"

class SubStatement : public Statement {
private:
    // Variable to change
    std::string m_variableName;
    // Variable to subtract
    std::string m_var_to_subtract;
    // Integer to subtract
    int m_value_to_subtract;
    // Checking if subtracting variable or integer
    bool subtracting_var;

public:
    // Constructor for subtracting variable
    SubStatement(std::string variableName, std::string var_to_subtract);
    // Constructor for subtracting integer
    SubStatement(std::string variableName, int value_to_subtract);

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif