# Postfixer
Translates math expressions from infix to postfix notation using syntax-
directed translation. Written in C11.

I decided to make this as I learn more about compilers. [The dragon book](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools) uses a 
infix-to-postfix translator as a way to immediately implement some of the
theory under parsing, so I figured I'd do one as well to learn the theory and practice
my C.

The translator can only handle single-digit decimal numbers and the addition,
subtraction, multiplication, and division operators. I didn't see a need to go
all out since it wouldn't help me learn the theory any further.

## Output
When the program is executed, this is the output:
```
infix expression: 9*5+2/8-3 
postfix expression: 95*2+8/3-
```
