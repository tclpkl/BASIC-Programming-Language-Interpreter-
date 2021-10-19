// LetStatement.cpp:
#include "LetStatement.h"

LetStatement::LetStatement(std::string variableName, int value) : m_variableName(variableName), m_value(value) {}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void LetStatement::execute(ProgramState* state, std::ostream& outf) {
    // TODO
    // Updates variable with value passed in
    state->update_var_values(m_variableName, m_value);

    // Updates program counter by 1
    state->update_program_counter();

    return;
}
