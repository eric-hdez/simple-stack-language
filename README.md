# basic-stack-language

## Basic Stack Language:

- @             : terminate the program
- +, -, *, /, % : operators, with top as rval, next to top as lval 
- $             : pop and discard top of stack
- :             : copy top of stack and push it
- .             : pop and print top of stack
- ,             : pop and print the ascii character of the top of stack
- ""            : string mode, push each char onto stack as ascii "aaa" -> [97, 97, 97]
- \             : swap top two elements of the stack

- ignore white spaces
- attempting to access the top of the stack when it is empty returns or pushes a 0
- swap on a 1 element stack [1] -> [1, 0]

