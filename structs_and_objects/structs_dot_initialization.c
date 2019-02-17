#include <stdlib.h>
#include <stdio.h>

// Declaration of struct Car class.
struct Car {
  char color;
  char* make;
  char* model;
  int num_doors;
  int num_wheels;
  char transmission;
};


int main(void)
{
    // Initialization of an object mycar of type struct Car.
    // Similar to braced-initialization, aka aggregate initialization.
    // You set the object equal to a braced initializer list,
    // and within it you specify the .data_members and their initial values.
    // .color = 'C',
    // Separate them with commas just like enum values.
    // Use the dot . member access operator to explicitly specify that you are assigning the data members of the new
    // mycar object.
    // Just like a regular braced initialization list, don't forget to put a ; semicolon at the end!
    // This syntax somewhat resembles the definition of a struct syntax.
    struct Car mycar = {
        .color = 'C',
	.make  = "Nissan",
	.model = "Leaf",
	.num_doors  = 4,
	.num_wheels = 4,
	.transmission = 'A'
    };

    // Regular braced-initialization, aka aggregate initialization:
    // You still have the braces with the semicolon ; at the end.
    // All the values are still separated by commas.
    // The only difference is that now without explicitly specifying which data members get assigned which values,
    // we now need to put the values in the order that the data members are declared in the class definition.
    struct Car yourcar = {
        'W',
	"Ford",
	"Focus",
	4,
	4,
	'A'
    };

    // The plus of using . dot initialization over regular braced-initialization aka aggregate initialization,
    // is that you can put the data member initializers in any order, and it still works!
    // Say you know that struct x contains these four fields, but you don't know in which order exactly are they declared.
    // So you can't use regular aggregate initialization here, especially if you cannot afford to guess (critical system code).
    // Now you can specify the data member initializers in any order and be sure of that, because you know that it will work.
    struct Car anothercar = {
	.model = "Power",
	.num_wheels = 4,
	.num_doors  = 2,
        .color = 'R',
	.transmission = 'M',
	.make  = "Ferrari"
    };

    // Yes, C doesn't care about whitespace
    // Adjacent string literals (separated by only whitespace) are concatenated in C.
    // I put them on new lines in the code to explicitly show that they ARE printed on newlines in the stdout.
    printf("My car is a %s %s\n"
           "Color: %c\n"
	   "with %d doors, %d wheels\n"
	   "and %c transmission.\n",     mycar.make, mycar.model, mycar.color,
	                                 mycar.num_doors, mycar.num_wheels, mycar.transmission);

    printf("Your car is a %s %s\n"
           "Color: %c\n"
	   "with %d doors, %d wheels\n"
	   "and %c transmission.\n",     yourcar.make, yourcar.model, yourcar.color,
	                                 yourcar.num_doors, yourcar.num_wheels, yourcar.transmission);

    printf("Another car is a %s %s\n"
           "Color: %c\n"
	   "with %d doors, %d wheels\n"
	   "and %c transmission.\n",     anothercar.make, anothercar.model, anothercar.color,
	                                 anothercar.num_doors, anothercar.num_wheels, anothercar.transmission);

    return 0;
}
