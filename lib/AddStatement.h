// AddStatement.h

#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "Statement.h"

class AddStatement : public Statement {
private:
    // Storing variable to change
    std::string m_variableName;
    // Storing variable to add
    std::string m_var_to_add;
    // Storing integer to add
    int m_value_to_add;
    // Checking if adding variable or integer
    bool adding_var;

public:
    // Constructor for adding variable
    AddStatement(std::string variableName, std::string value_to_add);
    // Constructor for adding integer
    AddStatement(std::string variableName, int value_to_add);

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif