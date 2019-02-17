// This file should be included into test2.c
// This demonstrates the concept of a translation unit in C,
// which is a preprocessed source code file with all the included files
// in it.
// When this variable gets included into test2.c, it becomes the same as
// a global variable declared/defined in test2.c, hence there is no
// need to use extern.
//
// extern is used only when a variable is defined in another source code
// file other than the one in which it is used/decalared.
//
// The scope of a variable, or a function is inside of its own translation unit.
// The individual source code files do not matter.
// The preprocessor combines multiple files (a source file and several header files)
// into one translation unit, which is then read by the compiler!
int other_variable = 8;

// This is a function declaration/prototype.
// It is included into the file test2.c
// Function declarations are extern by default.
// It means that the function is defined in another file.
// The definition for say_hello() is in test1.c
// A function declaration allows the compiler to recognise valid function calls,
// even if the function is defined elsewhere.
// It opens up the scope of that function into the translation unit which it
// happens to be included into.
extern void say_hello();

// Similarly, a variable declaration allows the compiler to
// recognize valid uses of that variable,
// and not complain that a variable is used without a definition.
// The definition resides in another translation unit,
// and the variable declaration extends the scope of the variable to be
// inside another translation unit.
