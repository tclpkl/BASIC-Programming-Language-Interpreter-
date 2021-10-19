// PrintStatement.cpp:
#include "PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName) : m_variableName(variableName) {}

void PrintStatement::execute(ProgramState* state, std::ostream& outf) {
    // Printing out integer value of variable
    outf << state->get_value(m_variableName) << std::endl;

    // Updates program counter by 1
    state->update_program_counter();
    return;
}
