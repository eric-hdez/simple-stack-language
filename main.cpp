#include "interpreter.h"

#include <fstream>
#include <iostream>
#include <string>

int main (int argc, char **argv) {
    if (argc < 2) {
        std::cerr << __FILE__ << ": No file provided for execution" << std::endl;
        exit(1);
    }

    std::ifstream file (argv[1]);
    std::string program;
    if (file.is_open() ) {
        while (file.good()) {
            file >> program;
        }
    }

    Interpreter interpreter;
    interpreter.execute(program);
    return 0;
}