// SubStatement.cpp:
#include "SubStatement.h"

SubStatement::SubStatement(std::string variableName, std::string var_to_subtract)
        : m_variableName(variableName), m_var_to_subtract(var_to_subtract) {
    // Subtracting variable
    subtracting_var = true;
}

SubStatement::SubStatement(std::string variableName, int value_to_subtract)
        : m_variableName(variableName), m_value_to_subtract(value_to_subtract) {
    // Subtracting integer
    subtracting_var = false;
}

void SubStatement::execute(ProgramState* state, std::ostream& outf) {
    // Value of variable to change
    int curr_value = state->get_value(m_variableName);
    int subtract;

    // Finding if subtracting variable or int
    if (subtracting_var) {
        subtract = state->get_value(m_var_to_subtract);
    } else {
        subtract = m_value_to_subtract;
    }

    // Updating variable with new value
    state->update_var_values(m_variableName, curr_value - subtract);

    // Updating program counter by 1
    state->update_program_counter();

    return;
}
