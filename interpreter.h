#include "stack.h"

#include <iostream>
#include <map>
#include <string>

#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

struct UnexpectedTokenException : public std::exception {
public:
	const char * what () const throw ()
    {
    	return "Unexpected token encountered";
    }
};

class Interpreter {
private:
    typedef void (Interpreter::*binopfunc)(int, int);
    typedef void (Interpreter::*unopfunc)(void);

    // interpreter stack and string mode indicator
    Stack<int> stack;
    bool strmode;

    // interpreter map of operator str to their functions
    std::map<char, Interpreter::binopfunc> binops {
        {'+', &Interpreter::add},
        {'-', &Interpreter::sub},
        {'*', &Interpreter::mul},
        {'/', &Interpreter::div},
        {'\\', &Interpreter::swap}
    };
    std::map<char, Interpreter::unopfunc> unops {
        {'.', &Interpreter::print},
        {':', &Interpreter::copy},
        {'@', &Interpreter::terminate},
        {'$', &Interpreter::discard},
        {'\"', &Interpreter::stringmode}
    };

    // binary operators
    void add(int lval, int rval) { this->stack.push(lval + rval); }
    void sub(int lval, int rval) { this->stack.push(lval - rval); }
    void mul(int lval, int rval) { this->stack.push(lval * rval); }
    void div(int lval, int rval) { this->stack.push(lval / rval); }
    void swap(int second, int first) { this->stack.push(first); this->stack.push(second); }

    // unary operators
    void print() { std::cout << this->safe_pop() << " "; }
    void copy() { this->stack.push(this->stack.peek()); }
    void terminate() { exit(0); }
    void discard() { this->safe_pop(); }
    void stringmode() { this->strmode = !this->strmode; }
    int safe_pop();

    // the guts of the machine 
    void resolve_token(char token);
    void binop_handler(char op);
    void unop_handler(char op);

public:
    Interpreter(): strmode(false) {}
    void execute(std::string program);
};

#endif