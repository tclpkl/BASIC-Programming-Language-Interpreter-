// EndStatement.cpp

#include "EndStatement.h"

EndStatement::EndStatement() {}

void EndStatement::execute(ProgramState* state, std::ostream& outf) {
    // Setting program counter to 0 so while program in interpretprogram terminates
    state->set_program_counter(0);
    return;
}
