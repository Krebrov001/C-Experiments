/*
 * https://www.youtube.com/watch?v=4De5HW4BAOU
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

#define PRINT_VALUE(x) printf("%s : %d\n", #x, x)

struct card1 {
  char* face;
  char* suit;
};

struct card2 {
  char face[20];
  char suit[15];
};


int main(void) {
  PRINT_VALUE(sizeof(struct card1));
  PRINT_VALUE(sizeof(struct card2));

  /* no typedef, we have to use the full data type,
     data_type aCard; */
  struct card1 aCard;
  struct card1* cardPtr;

  aCard.face = "Ace";
  aCard.suit = "Spades";

  cardPtr = &aCard;

  /* array initialization list initializes each struct object
     in the array. */
  /* This sets the face and suit fields of each struct card1 object
     to point to the corresponding string literals. */
  struct card1 packCard[3] = { {"ten", "Diamond"}, {"five", "heart"},
                                                   {"queen", "spades"} };
  cardPtr = &packCard[0];
  cardPtr = cardPtr + 2;

  /* %s accepts a pointer to the first element in the C-string */
  /*
     cardPtr->face is a char* to the first char in the string literal
   */
  printf("%s %s\n", cardPtr->face, cardPtr->suit);

  struct card2* cardPtr2;

  /* array initialization list initializes each struct object
     in the array. */
  /* This copies each char from the string literals into the
     corresponding C-strings face and suit fields. */
  struct card2 myCards[3] = { {"ten", "Diamond"}, {"five", "heart"},
                                                  {"queen", "spades"} };
  cardPtr2 = &myCards[0];
  cardPtr2 = cardPtr2 + 2;

  /* %s accepts a pointer to the first element in the C-string */
  /*
     cardPtr->face is a C-string, which in turn decays into a char*
     pointing to the first char in the C-string.
   */
  printf("%s %s\n", cardPtr2->face, cardPtr2->suit);

  PRINT_VALUE(sizeof(packCard));
  PRINT_VALUE(sizeof(myCards));

  printf("\n");

  struct point
  {
    int x;
    int y;
  };

  /* The optional name allows us to use the name of the data type like this:
     struct name objectName;
   */
  struct rectangle
  {
    struct point p1;
    struct point p2;
  };

  /* initializing each field manually */
  struct rectangle r1;
  r1.p1.x = 5;
  r1.p1.y = 6;
  r1.p2.x = 7;
  r1.p2.y = 20;

  PRINT_VALUE(r1.p1.x);
  PRINT_VALUE(r1.p1.y);
  PRINT_VALUE(r1.p2.x);
  PRINT_VALUE(r1.p2.y);

  printf("\n");

  /* initialization list for each internal struct field separately */
  /* Error: you cannot do this in C!
     An initialization list is valid only on initialization of a variable,
     when a variable is being declared/defined.
     Since the object struct had already been defined on the line above,
     we cannot use an initialization list for ASSIGNMENT of its fields.
   */
  /*
  struct rectangle r2;
  r2.p1 = {5, 6};
  r2.p2 = {7, 20};

  PRINT_VALUE(r2.p1.x);
  PRINT_VALUE(r2.p1.y);
  PRINT_VALUE(r2.p2.x);
  PRINT_VALUE(r2.p2.y);

  printf("\n");
  */

  /* initialization list for the whole struct
     using nested struct syntax. */
  struct rectangle r3 = { {5, 6}, {7, 20} };

  PRINT_VALUE(r3.p1.x);
  PRINT_VALUE(r3.p1.y);
  PRINT_VALUE(r3.p2.x);
  PRINT_VALUE(r3.p2.y);

  printf("\n");

  /* initialization list for the whole struct
     without using the nested struct syntax, all in one go. */
  struct rectangle r4 = {5, 6, 7, 20};

  PRINT_VALUE(r4.p1.x);
  PRINT_VALUE(r4.p1.y);
  PRINT_VALUE(r4.p2.x);
  PRINT_VALUE(r4.p2.y);

  printf("\n");

  /* The universal 0 initializer initializes
     all fields of the struct to 0 */
  struct rectangle r5 = {0};

  PRINT_VALUE(r5.p1.x);
  PRINT_VALUE(r5.p1.y);
  PRINT_VALUE(r5.p2.x);
  PRINT_VALUE(r5.p2.y);

  printf("\n");

  return EXIT_SUCCESS;
}
