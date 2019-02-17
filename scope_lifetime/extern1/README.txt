Link to original source:
https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files

This illustrates how to properly declare and use global variables
so that they are shared between multiple translation units.

If a global variable is intended to be used only in one translation unit,
then it should be declared as static, in the corresponding *.c file.
Other translation units cannot see the static global variable.
There is no need to put the static global variable in a header file.

On the other hand,
if a global variable is intended to be used in two or more translation units
then it should be declated (not defined) as extern, and that declaration
should be placed in a header file (as file3.h illustates).

Any source files that need to use the global variable should include this
header file, containing the extern declaration of the global variable.
That extends the scope of the global variable into that particular
translation unit.

Only one source file should have an explicit definition of the global
variable. That source file should also include the header file with
the declaration of the global variable, for consistency checking the
declaration against the definition.

Any code inside a source file, including inside the body of a function,
should not have its own extern declaration of the global variable.
If that source file needs to use the global variable, it simply includes
the header file containing the extern declaration of the global variable.

This technique works reliably and everywhere.
The header declaring the global_variable is included in every source file
that uses it, including the one that defines it.
This ensures that everything is self-consistent.

Similar rules apply to functions.
Function declarations/prototypes should be in a separate header file.
Any source file that needs to call the functions should not create
its own declarations of those functions, but rather, just include the
header file with the function declarations.
If a source file uses only some of the functions declared in the header,
the other extra declarations won't take up space in the executable.
They are just information to help the compiler recognize valid calls to
those functions, should the source file decide to use them.
Only a single source file should define a particular function.
Even though a definition is an implicit declaration, that source file
which defines the function should also include the header declaring that
function. This allows the compiler to check the signatures of the
declaration and the definition for consistency.
