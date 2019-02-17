/*
 * https://www.youtube.com/watch?v=qht-dvDSYiA
 * https://stackoverflow.com/questions/5453170/usage-of-union-inside-a-class
 * https://stackoverflow.com/questions/7558058/accessing-a-variable-in-a-union-which-is-inside-a-class?rq=1
 */

#include <iostream>
using std::cout;
using std::endl;

/* the class TaggedUnion_1 contains the following data members:
 DATA_TYPE - an enumerated type of an anonymous enum having two possible values, INTEGER and FLOAT
 
 int i and float f - two variabvles of an anonymous union inside the class.
 because the union is anonymous, we can access the data members directly
 like this:
   TaggedUnion_object.i = 100;

 An anonymous union defines these two variables as data members of the class
 having overlapping memory.
 It is worth noting that these variables are direct data members of the
 class, not members of a union inside of the class,
 because there is no union object/instance inside the class!
 */
class TaggedUnion_1 {
 public:
  enum {INTEGER, FLOAT} DATA_TYPE;

  // int i and float f occupy the same location in memory
  union {
    int i;
    float f;
  };  // no union object/instance inside the class
};


/* the class TaggedUnion_2 contains the following data members:
   
   int i and float f - two variables are actually data members of the
   union object/instance myUnion, which in turn is a data member of the
   class TaggedUnion_2.
   Unlike an anonymous union which does not have a union object/instance,
   here we define an object/instance of the union, which means that
   we need to access the data members int i and float f
   from the class, through the union:
     TaggedUnion2_object.myUnion.i = 200;

   Both these variables occupy the same memory location and behave otherwise
   as any other variables inside of unions.
   Since we've defined an object of the union type, myUnion is now a
   data member of the class TaggedUnion_2, and int i and float f are data
   members of the union.
 */
class TaggedUnion_2 {
 public:
  enum type {INTEGER, FLOAT} DATA_TYPE;

  union {
    int i;
    float f;
  } myUnion;  // object/instance of the union defined!
};


int main()
{
  TaggedUnion_1 t;
  t.DATA_TYPE = TaggedUnion_1::INTEGER;
  t.i = 100;

  cout << t.i << endl;
  cout << t.f << endl;
  cout << &t.i << endl;
  cout << &t.f << endl;

  TaggedUnion_2 u;
  u.DATA_TYPE = TaggedUnion_2::INTEGER;
  u.myUnion.i = 200;

  cout << u.myUnion.i << endl;
  cout << u.myUnion.f << endl;
  cout << &u.myUnion.i << endl;
  cout << &u.myUnion.f << endl;

  return 0;
}
