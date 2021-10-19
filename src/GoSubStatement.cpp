// GoSubStatement.cpp

#include "GoSubStatement.h"

GoSubStatement::GoSubStatement(int go_to_line) : m_go_to_line(go_to_line) {}

void GoSubStatement::execute(ProgramState* state, std::ostream& outf) {
    // Checks line to go to is not less than 1 or greater than largest line
    if (m_go_to_line <= 0 || m_go_to_line >= state->return_numLines()) {
        outf << "Illegal jump instruction" << std::endl;
        state->set_program_counter(0);
        return;
    }

    // Pushing current line onto stack for return statement to pop
    state->stack_push(state->program_line());

    // Setting program counter to line to go to
    state->set_program_counter(m_go_to_line);

    return;
}
