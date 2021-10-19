// ProgramState.h
//
// CS 104 / Fall 2021
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a BASIC program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// We've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED
#include <iterator>
#include <map>
#include <stack>

class ProgramState {
public:
    ProgramState(int numLines);

    // You'll need to add a variety of methods here.  Rather than trying to
    // think of what you'll need to add ahead of time, add them as you find
    // that you need them.

    int program_line();
    int return_numLines();
    void update_program_counter();
    void set_program_counter(int value);
    void stack_push(int value);
    int stack_pop();
    void update_var_values(std::string var_name, int var_value);
    int get_value(std::string var_name);
    std::string print_all();

private:
    int m_numLines;

    int program_counter;

    // Stack for keeping track of line numbers
    std::stack<int> line_num_stack;

    // Map for keeping track of variables and values
    std::map<std::string, int> map_vars_values;

    // Iterator for map
    std::map<std::string, int>::iterator map_it;
};

#endif
