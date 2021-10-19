// IfThenStatement.cpp

#include "IfThenStatement.h"

IfThenStatement::IfThenStatement(std::string var, std::string ope, int value, int go_to_line)
        : variableName(var), m_ope(ope), m_value(value), m_go_to_line(go_to_line) {}

void IfThenStatement::execute(ProgramState* state, std::ostream& outf) {
    // If checking less than
    if (m_ope == "<") {
        // Does nothing if greater than or equal to
        if (state->get_value(variableName) >= m_value) {
            return;
        }
    }

    // If checking less than or equal to
    if (m_ope == "<=") {
        // Does nothing if greater than
        if (state->get_value(variableName) > m_value) {
            return;
        }
    }

    // If checking greater than
    if (m_ope == ">") {
        // Does nothing if less than or equal to
        if (state->get_value(variableName) <= m_value) {
            return;
        }
    }

    // If chhecking greater than or equal to
    if (m_ope == ">=") {
        // Does nothing if less than
        if (state->get_value(variableName) < m_value) {
            return;
        }
    }

    // If checking equality
    if (m_ope == "=") {
        // Does nothing if not equal
        if (state->get_value(variableName) != m_value) {
            return;
        }
    }

    // If checking not equal
    if (m_ope == "<>") {
        // Does nothing if equal
        if (state->get_value(variableName) == m_value) {
            return;
        }
    }

    // Checks line to go to is not less than 1 or greater than largest line
    if (m_go_to_line <= 0 || m_go_to_line >= state->return_numLines()) {
        std::cout << state->return_numLines();
        outf << "Illegal jump instruction" << std::endl;
        state->set_program_counter(0);
        return;
    }

    // Changes program counter to line to go to
    state->set_program_counter(m_go_to_line);

    return;
}
