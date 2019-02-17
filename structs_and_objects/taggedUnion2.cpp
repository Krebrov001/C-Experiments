/*
 * https://www.youtube.com/watch?v=qht-dvDSYiA
 */

#include <iostream>
#include <cmath>     // C Math library  - for INFINITY, M_E
#include <cfloat>    // C float library - for FLT_MAX
#include <string>
using std::string;
using std::cout;
using std::cerr;
using std::clog;
using std::endl;

/* the class TaggedUnion contains the following data members:
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
class TaggedUnion {
 public:
  enum {INTEGER, FLOAT} DATA_TYPE;

  // int i and float f occupy the same location in memory
  union {
    int i;
    float f;
  };  // no union object/instance inside the class

  /* int constructor */
  TaggedUnion(int input)
  {
    DATA_TYPE = INTEGER;
    this->i = input;
    clog << "int set with " << input << endl;
  }

  /* float constructor */
  TaggedUnion(float input)
  {
    this->DATA_TYPE = FLOAT;
    f = input;
    clog << "float set with " << input << endl;
  }

  /* double constructor, for overloading, to convert a double into a
     float behind the scenes. To avoid ambiguous function call errors. */
  TaggedUnion(double input)
  {
    this->DATA_TYPE = FLOAT;
    f = static_cast<float>(input);
    clog << "double (converted to float) set with " << input << endl;
  }

  /* default constuctor takes no arguments! */
  TaggedUnion()
  {
    DATA_TYPE = INTEGER;
    i = 0;
    clog << "default constructor set with " << 0 << endl;
  }

  ~TaggedUnion()
  {
    switch (DATA_TYPE) {
      case INTEGER:
        clog << i;
	break;
      case FLOAT:
        clog << f;
	break;
      default:
        break;
    }

    clog << " destroyed!" << endl;
  }
};


/**
 * This function prints out a TaggedUnion based on the DATA_TYPE
 * enumerated type field which holds information about the data that
 * is stored in that TaggedUnion.
 *
 * This function uses a switch statement on u.DATA_TYPE.
 * TaggedUnion::INTEGER is just an enumerated constant,
 * and an enumerated constant is nothing more than integral integer type.
 *
 * @param const TaggedUnion& u - an object of the TaggedUnion class
 *   pass-by-reference to avoid the overhead of copying an entire object.
 *   const pass-by-reference to avoid inadvertently changing the object.
 */
void PrintTaggedUnion(const TaggedUnion& u) {
  switch (u.DATA_TYPE) {
    case TaggedUnion::INTEGER:
      cout << u.i << endl;
      break;
    case TaggedUnion::FLOAT:
      cout << u.f << endl;
      break;
    default:
      cerr << "Oops, something went wrong!" << endl;
  }

  return;
}


int main()
{
  TaggedUnion t(100);
  /* The enumerated constant INTEGER has class scope.
     It is defined in the enum field of the class.
     We can use INTEGER as an enumerated constant inside the class without
     using the :: scope operator because since INTEGER was defined inside
     the class definition, it has class scope.
     The :: scope resolution operator makes a name visible outside of its
     scope. Normally, INTEGER enumerated constant would not be visible
     outside of the class. That is why we have to quality it with
     TaggedUnion::INTEGER if we want to use it outside of the class scope.
     This is just like scope-qualifying functions of a class.
     The first part tells the scope from which we want to get the name,
     to where the name belongs. Then we have a ::. Then the actual name
     itself that you want to use follows.
   */
  t.DATA_TYPE = TaggedUnion::INTEGER;
  // t.DATA_TYPE = INTEGER;
  /*
  t.i = 100;
  */

  PrintTaggedUnion(t);

  TaggedUnion u(3.14f);
  /*
  u.DATA_TYPE = TaggedUnion::FLOAT;
  u.f = 3.14f;
  */

  PrintTaggedUnion(u);

  /* Create some arbitrary TaggedUnion objects to test the constructors. */

  TaggedUnion v(50);
  TaggedUnion w(FLT_MAX);  // FLT_MAX is the maximum finite float value
  TaggedUnion x(4);
  TaggedUnion y(M_E);  // M_E is actually a double value!
  TaggedUnion z;  // Default constructor gets called.
  TaggedUnion inf(INFINITY);  // + infinity, the value guaranteed to overflow an IEEE float!

  PrintTaggedUnion(v);
  PrintTaggedUnion(w);
  PrintTaggedUnion(x);
  PrintTaggedUnion(y);
  PrintTaggedUnion(z);
  PrintTaggedUnion(inf);

  /* The string() constructor returns a printable rvalue of string class type. */
  cout << string(50, '=') << endl;

  //cout << INTEGER << endl;  // error: 'INTEGER' was not declared in this scope!
  cout << TaggedUnion::INTEGER << endl;  // This workd

  int INTEGER = 5;
  cout << INTEGER << endl;  // INTEGER was defined as an int local to main()

  /* You cannot have a using declaration on a class in C++!
     error: 'TaggedUnion' is not a namespace or unscoped enum
   */
  /*
  using TaggedUnion::FLOAT;
  using TaggedUnion::INTEGER;
  cout << INTEGER << endl;
  */

  /*
  A using declaration declares that you want to use a particular name:
  using std::cout;

  A using directive directs you to use every name in that particular namespace.
  A using directive lets you use all names from a NAMESPACE without qualifying them:
  using namespace std;
  */

  cout << string(50, '=') << endl;

  /* explicitly destroy some objects */
  y.~TaggedUnion();  // Destroys M_E
  v.~TaggedUnion();  // Destroys 50
  v.~TaggedUnion();  // Destroys 50

  cerr << v.i << endl;

  /* objects are destroyed when they go out of scope,
     in the reverse order in which they were created. */

  return 0;
}
