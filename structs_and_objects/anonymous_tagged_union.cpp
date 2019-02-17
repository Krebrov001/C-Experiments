#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;


/* Unions can be anonymous (unnamed).
 * This form is used when nesting a union inside a struct or class that contains an extra data member
 * to indicate what the union contains.
 * This arrangement is called a tagged union (or managed union).
 * It can be used as a "polymorphic" class which can be several things at once, for example to create an array
 * of different data types.
 */

class Number {
    friend ostream& operator<<(ostream& os, Number& num);
  public:
    enum data_type { INTEGER, FLOAT } DATA_TYPE;

    union {
        int i;
        float f;
    };
};


ostream& operator<<(ostream& os, Number& num)
{
    switch (num.DATA_TYPE) {
        case Number::INTEGER:
	  cout << num.i;
          break;
        case Number::FLOAT:
	  cout << num.f;
          break;
	default:
	  cout << 0;
	  break;
    }

    return os;
}


int main()
{
    // Here we have an object of that taggedUnion class.
    // We can access both DATA_TYPE and i using the . operator because
    // they are both public data members of that class.
    // enum { ... } DATA_TYPE;  - nichego udevitelnogo, data_type variable_name; inside the class.
    // Recall that our union is actually an anonymous union, and that there is no anonymous union object,
    // so both of these variables int i; and float f; are in the global scope, they just happen to occupy
    // the same memory. In the "global scope" means that they are treated just like regular data members of the class.
    // The enumerated values INTEGER and FLOAT are also in the "global scope".
    // Thay are VALUES, not data members.
    // Because their "global scope" turns out to be the scope inside the class Number { ... },
    // We have to scope-quality them because they are in a greater enclosing scope: Number::INTEGER;
    Number t;
    t.DATA_TYPE = Number::INTEGER;
    t.i = 100;
    cout << t << endl;
    t.DATA_TYPE = Number::FLOAT;
    t.f = 100.0f;
    cout << t << endl;

    // This Number r is uninitialized because I've not created a constructor yet.
    // However, If the case would be default, if r.DATA_TYPE happens to be == 
    // it would automatically print a 0.
    // Let's see what happens when we print it.
    // It print 0 all the time.
    Number r;
    cout << r << endl;

    cout << endl;

    // Here we're setting s.DATA_TYPE = 3, which is something other than INTEGER or FLOAT,
    // So a 0 is printed automatically.
    // Actually assigning it to 3 just like that will not work.
    // We need to first type cast it into the appropriate data type.
    // Here we need to give the enum { .. } a name, a tag, in order to let the compiler know what data type it is.
    Number s;
    s.DATA_TYPE = (Number::data_type) 3;
    cout << s << ' ' << s.DATA_TYPE;      // prints 0 3

    return EXIT_SUCCESS;
}
