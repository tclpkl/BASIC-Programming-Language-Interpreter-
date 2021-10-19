
// DivStatement.cpp:
#include "DivStatement.h"

#include <math.h>

DivStatement::DivStatement(std::string variableName, std::string var_to_div)
        : m_variableName(variableName), m_var_to_div(var_to_div) {
    // Dividing by variable
    div_var = true;
}

DivStatement::DivStatement(std::string variableName, int value_to_div)
        : m_variableName(variableName), m_value_to_div(value_to_div) {
    // Divding by integer
    div_var = false;
}

void DivStatement::execute(ProgramState* state, std::ostream& outf) {
    // Value of variable to change
    int curr_value = state->get_value(m_variableName);
    double div;

    // Finding if dividing variable or int
    if (div_var) {
        div = state->get_value(m_var_to_div);
    } else {
        div = m_value_to_div;
    }

    // Checking if div is 0
    if (div == 0) {
        outf << "Divide by zero exception";
        state->set_program_counter(0);
        return;
    }

    // Updating variable with new value
    state->update_var_values(m_variableName, int(floor(curr_value / div)));

    // Updating program counter by 1
    state->update_program_counter();

    return;
}
