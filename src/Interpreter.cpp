// Interpreter.cpp
#include "AddStatement.h"
#include "DivStatement.h"
#include "EndStatement.h"
#include "GoSubStatement.h"
#include "GotoStatement.h"
#include "IfThenStatement.h"
#include "LetStatement.h"
#include "MultStatement.h"
#include "PrintAllStatement.h"
#include "PrintStatement.h"
#include "ReturnStatement.h"
#include "Statement.h"
#include "SubStatement.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns a vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement*>& program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement* parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);

int main() {
    cout << "Enter BASIC program file name: ";
    string filename;
    getline(cin, filename);
    ifstream infile(filename.c_str());
    if (!infile) {
        cout << "Cannot open " << filename << "!" << endl;
        return 1;
    }
    interpretProgram(infile, cout);
}

void parseProgram(istream& inf, vector<Statement*>& program) {
    program.push_back(NULL);

    string line;
    while (!inf.eof()) {
        getline(inf, line);
        if (line == "") {
            continue;
        }
        program.push_back(parseLine(line));
    }
}

Statement* parseLine(string line) {
    Statement* statement;
    stringstream ss;
    string type;
    string var;
    int val;
    int line_num;

    ss << line;
    ss >> line_num;
    ss >> type;

    if (type == "LET") {
        ss >> var;
        ss >> val;
        // Note:  Because the project spec states that we can assume the file
        //	  contains a syntactically legal program, we know that
        //	  any line that begins with "LET" will be followed by a space
        //	  and then a variable and then an integer value.
        statement = new LetStatement(var, val);
    }

    // Incomplete;  TODO:  Finish this function!

    if (type == "END" || type == ".") {
        statement = new EndStatement();
    }

    if (type == "PRINT") {
        // Storing variable to print
        ss >> var;
        statement = new PrintStatement(var);
    }

    if (type == "PRINTALL") {
        statement = new PrintAllStatement();
    }

    if (type == "ADD") {
        // Storing variable to change
        ss >> var;
        string to_be_added;
        // Storing value to be added
        ss >> to_be_added;
        // Checking if to_be_added is var or int and using correct constructor
        if (isdigit(to_be_added[0]) || isdigit(to_be_added[1])) {
            statement = new AddStatement(var, stoi(to_be_added));
        } else {
            statement = new AddStatement(var, to_be_added);
        }
    }

    if (type == "SUB") {
        // Storing variable to change
        ss >> var;
        string to_be_subtracted;
        // Storing value to be subtracted
        ss >> to_be_subtracted;
        // Checking if to_be_subtracted is var or int and using correct constructor
        if (isdigit(to_be_subtracted[0]) || isdigit(to_be_subtracted[1])) {
            statement = new SubStatement(var, stoi(to_be_subtracted));
        } else {
            statement = new SubStatement(var, to_be_subtracted);
        }
    }

    if (type == "MULT") {
        // Storing variable to change
        ss >> var;
        string to_be_multiplied;
        // Storing value to be multiplied
        ss >> to_be_multiplied;
        // Checking if to_be_multiplied is var or int and using correct constructor
        if (isdigit(to_be_multiplied[0]) || isdigit(to_be_multiplied[1])) {
            statement = new MultStatement(var, stoi(to_be_multiplied));
        } else {
            statement = new MultStatement(var, to_be_multiplied);
        }
    }

    if (type == "DIV") {
        // Storing variable to be change
        ss >> var;
        string to_be_divided;
        // Storing value to be divided
        ss >> to_be_divided;
        // Checking if to_be_divided is var or int and using correct constructor
        if (isdigit(to_be_divided[0]) || isdigit(to_be_divided[1])) {
            statement = new DivStatement(var, stoi(to_be_divided));
        } else {
            statement = new DivStatement(var, to_be_divided);
        }
    }

    if (type == "GOTO") {
        // Storing line number to go to
        ss >> line_num;
        statement = new GotoStatement(line_num);
    }

    if (type == "IF") {
        // Storing variable to compare
        ss >> var;
        string ope;
        // Storing operator being used
        ss >> ope;
        // Storing value to compare to
        ss >> val;
        // Storing then
        string then;
        ss >> then;
        // Storing line number to go to
        ss >> line_num;
        statement = new IfThenStatement(var, ope, val, line_num);
    }

    if (type == "GOSUB") {
        // Storing line number to go to
        ss >> line_num;
        statement = new GoSubStatement(line_num);
    }

    if (type == "RETURN") {
        statement = new ReturnStatement();
    }

    return statement;
}

void interpretProgram(istream& inf, ostream& outf) {
    vector<Statement*> program;
    parseProgram(inf, program);

    // Incomplete;  TODO:  Finish this function!

    // Instantiating programstate object dynamically
    ProgramState* state = new ProgramState(program.size() - 1);

    // Execute functions while program_line != 0 and program vector not at index 0
    while (program[state->program_line()] != NULL) {
        // Execute the correct line of Statement in program vector
        program[state->program_line()]->execute(state, outf);
    }

    // Iterating through vector of dynamically allocated statements and deleting
    for (long unsigned int i = 1; i < program.size(); i += 1) {
        delete program[i];
    }

    // Deleting ProgramState
    delete state;
}
