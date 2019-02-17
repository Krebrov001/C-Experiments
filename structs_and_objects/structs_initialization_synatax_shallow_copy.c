/*
 * https://www.youtube.com/watch?v=GusRctYVI4U&list=PL3C47C530C457BACD&index=26
 */

#include <stdio.h>   // C standard input/output - for printf()
#include <stdlib.h>  // C standard library      - for atoi(), EXIT_SUCCESS
#include <string.h>  // C string library        - for strncpy()

#define PRINT_VALUE(x) printf("%s : %d\n", #x, x)

#define PRINT_STRING(x) printf("%s : %s\n", #x, x)

int main(int argc, char** argv) {

  /* struct point { int x; int y; } is a data type */
  struct point {
    int x;
    int y;
  };

  /* struct point1 { int x; int y; } is a data type
     data_type point_object;
     point_object is a struct point1
   */
  struct point1 {
    int x;
    int y;
  } point_object;

  /* typedef turns the p3d into a stamp for a struct point3D
     typedef data_type p3d;
   */
  typedef struct point3D {
    int x;
    int y;
    int z;
  } p3d;

  /* simple structure member access by dot operator */
  /* I am using the point_object defined earlier when the
     struct point1 data type was defined */
  point_object.x = atoi(argv[1]);
  point_object.y = atoi(argv[2]);
  PRINT_VALUE(point_object.x);
  PRINT_VALUE(point_object.y);

  printf("\n");

  /* We can also define a struct point object like so:
     data_type p1;
   */
  struct point p1;
  p1.x = 10;
  p1.y = 18;
  PRINT_VALUE(p1.x);
  PRINT_VALUE(p1.y);

  printf("\n");

  /* initialization of structure */
  /* p2 is a p3d, which is a struct point3D, or a struct with 3 fields.
     data_type p2 = {field1, field2, field3};
   */
  p3d p2 = {1, 2, 3};
  PRINT_VALUE(p2.x);
  PRINT_VALUE(p2.y);
  PRINT_VALUE(p2.z);

  printf("\n");

  /* shallow copy, does a field-by-field copy */
  /* you can use = assignment operator to do a shallow copy
     on structs in C. */
  p3d p_copy = p2;
  PRINT_VALUE(p_copy.x);
  PRINT_VALUE(p_copy.y);
  PRINT_VALUE(p_copy.z);

  printf("\n");

  /* magic_struct is now a stamp for a struct
     with an int field and an int* field */
  /* typedef data_type magic_struct; */
  typedef struct
  {
    int a;
    int* b;
  } magic_struct;

  int magic_number = 4;

  magic_struct str1;
  str1.a = 2;
  str1.b = &magic_number;

  PRINT_VALUE(str1.a);
  PRINT_VALUE(str1.b);
  PRINT_VALUE(*(str1.b));

  printf("\n");

  /* creates a shallow copy of str1, into str2 */
  magic_struct str2 = str1;

  PRINT_VALUE(str2.a);
  PRINT_VALUE(str2.b);
  PRINT_VALUE(*(str2.b));

  printf("\n");

  *(str2.b) = 5;
  printf("changing the int via a shallow copy\n");

  PRINT_VALUE(str1.a);
  PRINT_VALUE(str1.b);
  PRINT_VALUE(*(str1.b));

  printf("\n");

  PRINT_VALUE(str2.a);
  PRINT_VALUE(str2.b);
  PRINT_VALUE(*(str2.b));

  printf("\n");

  PRINT_VALUE(&str1);
  PRINT_VALUE(&str2);

  printf("\n");

  /* nested struct: a struct containing other structs inside of it */
  struct line {
    struct point p1;
    struct point p2;
  };

  /* nested structure initialization */
          /* { {p1.x, p1.y}, {p2.x, p2.y} }; */
  struct line l1 = { {1, 2}, {3, 4} };

  PRINT_VALUE(l1.p1.x);
  PRINT_VALUE(l1.p1.y);
  PRINT_VALUE(l1.p2.x);
  PRINT_VALUE(l1.p2.y);

  printf("\n");

  /* create a nested structure l2, but assign member fields indiviually */
  struct line l2;
  l2.p1.x = 1;
  l2.p1.y = 2;
  l2.p2.x = 3;
  l2.p2.y = 4;

  PRINT_VALUE(l2.p1.x);
  PRINT_VALUE(l2.p1.y);
  PRINT_VALUE(l2.p2.x);
  PRINT_VALUE(l2.p2.y);

  printf("\n");

  /* alternative way to typedef a struct,
     not directly at the struct definition,
     but farther down in the code. */
  /* struct point is our data type */
  /* typedef data_type point_t; */
  typedef struct point point_t;
  point_t anotherpoint = {5, 6};

  point_t* ptr2point = &anotherpoint;

  /* how do you access the field of a struct
     from a pointer to that struct? */
  PRINT_VALUE((*ptr2point).x);
  PRINT_VALUE(ptr2point->y);

  printf("\n");

  /* enum { ... } is a data type,
     of an enumerated type with a possible set of values. */
  /* typedef data_type stars; */
  typedef enum {
    one_stars = 1,
    two_stars,
    three_stars,
    four_stars,
    five_stars
  } stars;

  /* enumerated constants in an enum automatically start counting
     at 0. To make them start counting at 1, or any other number,
     you must explicitly assign the desired first number to the first
     enumerated constant, or possible value, of the enumerated type. */

  /* the name/tag directly after the struct is optional */
  /* struct { ... } is a data type,
     of a structure having variables of different data types. */
  /* typedef data_type book; */
  /* Without the typedef, book would have been an object of that struct
     type. With the typedef, book is now a "stamp" for that
     struct data type. */
  typedef struct {
    char name[20];
    char author[20];
    int num_pages;
    stars rating;
  } book;

  /* An object of the struct type is created. */
  book b1;

  /* strncpy(char* dest, const char* source, size_t n); */
  strncpy(b1.name,   "Aryan History",   sizeof(b1.name) - 1);
  strncpy(b1.author, "Anatoliy Klesov", sizeof(b1.author) - 1);
  /* We cannot do the following: */
  /*
  b1.author = "Anatoliy Klesov";
  */
  /* error: assignment to expression with array type */
  /* A char array (C-string) can only be assigned a string literal
     at initialization, where it is declared.
     Here we are attempting to assign a string literal to a char array,
     not at its initialization, which is an error.
     The author C-string gets declared/defined when the object of the
     struct type is created.
     Can you use a constructor, in C++, to initialize a
     C-string data member?
     That is a question worth investigating.
     Because the above = assignment operator does not work,
     we have to use strcpy() if we want to change the contents of a
     char array after it had already been declared/defined.
   */

  b1.num_pages = 234;
  /* In the C programming language, you cannot have a variable name,
     an enumerated constant, or any other identifier as 5_stars.
     This is because 5_stars begins with a numerical char.
     The compiler reads this as a numerical literal, then
     it gets confused because there is a _stars part after the 5.
     invalid suffix "_stars" on integer constant
     In the C programming language, an identifier cannot start with
     a numerical char. The numberical char can be anywhere inside
     the identifier except at the beginning.
     In C and C++, and identifier can only begin with an alphanumeric
     char or an _.
   */
  b1.rating = five_stars;

  PRINT_STRING(b1.name);
  PRINT_STRING(b1.author);
  PRINT_VALUE(b1.num_pages);
  PRINT_VALUE(b1.rating);

  printf("\n");

  /* structure initialization list, copies the given values
     into all fields of the structure */
  book b2 = {"C++ Primer", "Barbara E. Moo", 938, five_stars};
  /* Because here the object of the struct type is being created,
     we can initialize a C-string with a string literal!
     Initializing a string literal to a char array (C-string) occurs
     only once, at the definition of the C-string. */
  /* This is equivalent to: */
  /*
  char name[20] = "C++ Primer";
  */
  /* All chars from the string literal, including the '\0', are copied
     into the C-string one-by-one. */
  /* Anywhere outside the DEFINITION of the C-string, we cannot
     use the = assignment operator to assign another string literal
     to the C-string: */
  /*
  name = "Absolute C++";
  */

  PRINT_STRING(b2.name);
  PRINT_STRING(b2.author);
  PRINT_VALUE(b2.num_pages);
  PRINT_VALUE(b2.rating);

  printf("\n");

  /* Passing a string literal to the PRINT_STRING macro.
     What will get printed? */
  PRINT_STRING("Hello World");

  printf("\n");

  return EXIT_SUCCESS;
}
