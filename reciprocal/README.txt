How to Compile and link C and C++ program
=========================================

$ gcc -c main.c // Compile the C program, it create main.o file.

$ g++ -c reciprocal.cpp // Similar to C it create reciprocal.o of C++ file.

// use -I to include header files from specific locations.
$ g++ -c -I ../include  reciprocal.cpp


$ g++ -c reciprocal.cpp


// Remove the assertion check on the production checkout and compile without
// assertion check.

$ g++ -c -D NDEBUG reciprocal.cpp
