// ProgramState.cpp

#include "ProgramState.h"

#include <iostream>
#include <sstream>
#include <string>

// Constructor for ProgramState
ProgramState::ProgramState(int numLines) : m_numLines(numLines) {
    // Initializing program counter
    program_counter = 1;
}

// Returning program_counter
int ProgramState::program_line() { return program_counter; }

// Returning num of lines of program
int ProgramState::return_numLines() { return m_numLines; }

// Updating program_counter by 1
void ProgramState::update_program_counter() { program_counter += 1; }

// Setting program counter to anny line
void ProgramState::set_program_counter(int value) { program_counter = value; }

// Pushing line number onto stack
void ProgramState::stack_push(int value) {
    // Adds element to top
    line_num_stack.push(value);
    return;
}

// Popping line number from stack
int ProgramState::stack_pop() {
    // Checking if stack is alr empty
    if (line_num_stack.empty()) {
        // If popping when stack empty, then terminate
        program_counter = 0;
        return -1;
    }

    // Store line number to return to
    int line_to_return = line_num_stack.top();

    // Popping the value from stack
    line_num_stack.pop();

    // Returns the line number to return to
    return line_to_return;
}

// Updating Map variable's value or instantiating variable with value
void ProgramState::update_var_values(std::string var_name, int var_value) {

    // If key doesn't exist, creates key with value
    if (!map_vars_values.count(var_name)) {
        map_vars_values[var_name] = var_value;
    }
    // If key exists, updates value
    else {
        map_vars_values[var_name] = var_value;
    }

    return;
}

// Gets value of variable
int ProgramState::get_value(std::string var_name) {
    // If variable doesn't exist, instantiates it as 0
    if (!map_vars_values.count(var_name)) {
        map_vars_values[var_name] = 0;
    }

    // Returns value of variable that is key in map
    return map_vars_values[var_name];
}

// Returns string of "variable val" for all variables
std::string ProgramState::print_all() {
    // Creating stringstream to store variables and values
    std::stringstream ss;
    // Iterates through map
    for (map_it = map_vars_values.begin(); map_it != map_vars_values.end(); map_it++) {
        // Puts into ss "VAR VALUE"
        ss << map_it->first << " " << map_it->second << std::endl;
    }
    // Returns whole thing as string
    return ss.str();
}
