// AddStatement.cpp:
#include "AddStatement.h"

AddStatement::AddStatement(std::string variableName, std::string var_to_add)
        : m_variableName(variableName), m_var_to_add(var_to_add) {
    // Adding variable
    adding_var = true;
}

AddStatement::AddStatement(std::string variableName, int value_to_add)
        : m_variableName(variableName), m_value_to_add(value_to_add) {
    // Adding integer
    adding_var = false;
}

void AddStatement::execute(ProgramState* state, std::ostream& outf) {
    // Value of variable to change
    int curr_value = state->get_value(m_variableName);
    int add;

    // Finding if adding variable or int
    if (adding_var) {
        add = state->get_value(m_var_to_add);
    } else {
        add = m_value_to_add;
    }

    // Updating variable with new value
    state->update_var_values(m_variableName, curr_value + add);

    // Updating program counter by 1
    state->update_program_counter();

    return;
}
