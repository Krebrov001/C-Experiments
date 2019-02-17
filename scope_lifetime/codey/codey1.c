// A function declaration (prototype in this case because the formal parameters are specified)
// tells the compiler:
// This function, should I decide to use it, has the following formal parameters and return type.
// I am under no obligation to use it however.
// This is just auxiliary information for the compiler.
// The preprocessor doesn't care about it because it does not start with a preprocessor directive #
// The assembler doesn't see it, because function declarations take up no space in the assembly code.
int add_five(int a);
int add_six(int a);
int add_seven(int a);
int add_eight(int a);
int add_nine(int a);
int add_ten(int a);
int add_eleven(int a);
int add_twelve(int a);

int add_five(int a)
{
  return a + 5;
}

int main() {
  int barber = 10;
  barber = add_five(barber);
}
