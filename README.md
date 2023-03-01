# lang-gch2l

DISCLAIMER: This project is mainly for educational purposes. 


This repository contains the Generic Concatenative High Level Language project.
This programming language is ispired by multiple similar programming languages, namely:
  - FORTH
  - Basic
  - LISP
  - UNIX Shell (*sh)
  
The purpose of this language is rather general, giving users up to a complete interface with the Linux kernel.
The language has multiple "editions", providing different capabilities.
The language should at least interface with basic I/O of any system (using C standard functions).
And at most send UDP/IP requests, mount filesystems and manage administrative tasks like any Shell could do.
Not all utilities should be built into the language, but only the basic system functions (provided as interface or instruction).


The language inner working is fairly simple. Instead of having a complex structure or syntax, it uses a concatenative approach.
For instance, one may think of function application like this: a(b(c)), or a->b->c. In this language, it works like this: a b c.
A program is the application of functions (procedures or instructions), constituing computation.
The program can be provided as a stream of characters (naming functions or data), which should be interpreted or compiled given a language implementation.
A user defined function or procedure is simply a sub-program or stream. This stream can be analyzed and executed inside of the main program.
Languages functions, user defined procedures or any other kind of variable is stored in a Dictionary.
Dictionary entries can be entered, deleted or modified. Data can be retreived from the dictionary too. Such operation is mostly done implicitly inside an "update".
A language "update" is defined as the evaluation of a word in a stream. Such evaluable word designates built-in functions.
