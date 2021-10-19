// ReturnStatement.cpp

#include "ReturnStatement.h"

ReturnStatement::ReturnStatement() {}

void ReturnStatement::execute(ProgramState* state, std::ostream& outf) {
    // Finds line to return to
    int line = state->stack_pop();

    // Sets program counter to line to return to
    // Adds 1 so goes to line after GOSUB
    state->set_program_counter(line + 1);

    return;
}
