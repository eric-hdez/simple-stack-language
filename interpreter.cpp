#include "interpreter.h"
#include <iostream>

/*
    executes the interpreter on the program string by resolving one token
    at a time

    program: the stack language program being executed
*/
void Interpreter::execute(std::string program) {
    for (char token: program) {
        try {
            this->resolve_token(token);
        } catch (UnexpectedTokenException e) {
            std::cerr << e.what() << ": " << token << std::endl; 
            exit(1);
        }
    }
}

/*
    resolves a token from the stack language program being interpreted or
    throws an exception if it is not valid

    token: the token being evaluated
*/
void Interpreter::resolve_token(char token) {
    if ((token == ' ' || token == ' ') && !this->strmode) {
        return;
    } else if (!(this->binops.find(token) == this->binops.end())) {
        this->binop_handler(token);
    } else if (!(this->unops.find(token) == this->unops.end())) {
        this->unop_handler(token);
    } else if (isdigit(token) || this->strmode) {
        this->stack.push(this->strmode ? int(token) : token - '0');
    } else {
        throw UnexpectedTokenException();
    }
}

/*
    executes a binary operator from the stack language on the top two
    elements of the stack

    op: operation being performed
*/
void Interpreter::binop_handler(char op) {
    int rval = this->safe_pop();
    int lval = this->safe_pop();
    (this->*binops[op])(lval, rval);
}

/*
    executes a unary operator from the stack language on the top two
    elements of the stack

    op: operation being performed
*/
void Interpreter::unop_handler(char op) {
    (this->*unops[op])();
}

/*
    performs a safe pop, returning 0 if the pop would otherwise produce
    undefined behavior
*/
int Interpreter::safe_pop() {
    if (this->stack.empty()) {
        return 0;
    }

    return this->stack.pop();
}
