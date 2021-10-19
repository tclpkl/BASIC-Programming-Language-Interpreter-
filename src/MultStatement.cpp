// MultStatement.cpp:
#include "MultStatement.h"

MultStatement::MultStatement(std::string variableName, std::string var_to_mult)
        : m_variableName(variableName), m_var_to_mult(var_to_mult) {
    // Multiplying by variable
    mult_var = true;
}

MultStatement::MultStatement(std::string variableName, int value_to_mult)
        : m_variableName(variableName), m_value_to_mult(value_to_mult) {
    // Multiplying by integer
    mult_var = false;
}

void MultStatement::execute(ProgramState* state, std::ostream& outf) {
    // Value of variable to change
    int curr_value = state->get_value(m_variableName);
    int mult;

    // Finding if multiplying variable or int
    if (mult_var) {
        mult = state->get_value(m_var_to_mult);
    } else {
        mult = m_value_to_mult;
    }

    // Updating variable with new value
    state->update_var_values(m_variableName, curr_value * mult);

    // Updating program counter by 1
    state->update_program_counter();

    return;
}
