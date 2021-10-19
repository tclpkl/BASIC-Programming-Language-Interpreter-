// PrintAllStatement.cpp

#include "PrintAllStatement.h"

PrintAllStatement::PrintAllStatement() {}

void PrintAllStatement::execute(ProgramState* state, std::ostream& outf) {
    // Putting into ostream string of all variables and values
    outf << state->print_all();

    // Updates program counter by 1
    state->update_program_counter();
    return;
}
