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
    friend ostream& operator<<(ostream& os, const Number& num);
  public:
    /* Constructor with default int argument acts as a default constructor too.
     * If Number is default-constructed, it is set to an integer 0.
     * If an int argument is provided, it overwrites/rides the default argument.
     * It initializes the data member int i; with the parameter.
     * This constructor also alows you to do implicit type conversion.
     */
    Number(int i = 0) : DATA_TYPE(INTEGER), i(i) { /*cerr << "Number(" << i << ")\n";*/	}
	
	/* And we also want Numbers to be initialized with unsigned int too.
	 * To avoid the ambiguous conversion error, we have to create this constructor explicitly.
	 * The unsigned int is treated as a (signed) int. If it's too big, it becomes a large negative number.
	 */
	Number(unsigned int u) : DATA_TYPE(INTEGER), i(static_cast<int>(u)) { /*cerr << "Number((signed) " << i << ")\n";*/ }

    /* Same thing here, but there is no default argument
     * in order to make a default-constructed Number always call the int constructor.
     * This constructor also allows you to to implicit type conversion from a float to a Number.
     */
    Number(float f) : DATA_TYPE(FLOAT), f(f) { /*cerr << "Number(" << f << ")\n";*/ }
	
	/* This conversion constructor is specifically made to accept floats, because I don't want to type
	 * 3.14f always. The user will not always put the f at the end.
	 * We want the code to behave well as the user expected it, to accept a double as an initializer.
	 * The double is treated as a float, it is type cast.
	 */
	Number(double d) : DATA_TYPE(FLOAT), f(static_cast<float>(d)) { /*cerr << "Number((float) " << f << ")\n";*/ }

    /* The copy constructor initializes *this object as a copy of the passed in object const Number& rhs.
     * The DATA_TYPE is copied over, nothing unusual.
     * When you have an anonymous union, you want to initialize the largest data member of the union
     * to that of the rhs to make sure that all the bits comprising the union are copied over exactly.
     * Here the int i and float f are the same size so it makes no difference which one we decide to copy.
     * Even if the rhs.DATA_TYPE was == FLOAT, that doesn't matter since all the bits are copied over anyway
     * with the int i, and int i shares the exact same memory location with float f.
     */
    Number(const Number& rhs) : DATA_TYPE(rhs.DATA_TYPE), i(rhs.i) { /*cerr << "Number((Number) " << *this << ")\n";*/ }

    Number& operator=(const Number& rhs)
    {
        this->DATA_TYPE = rhs.DATA_TYPE;
	this->i = rhs.i;

        //cerr << "operator=(const Number&)" << endl;
	return *this;
    }

    Number& operator=(int i)
    {
	// Because the parameter i overshadows the class variable i,
	// this-> is needed to identify the data member.
        this->DATA_TYPE = INTEGER;
	this-> i = i;

	//cerr << "operator=(int i)" << endl;
    }

    Number& operator=(unsigned int u)
    {
        this->DATA_TYPE = INTEGER;
	this-> i = static_cast<signed int>(u);

	//cerr << "operator=(unsigned int u)" << endl;
    }

    Number& operator=(float f)
    {
	// Because the parameter f overshadows the class variable f,
	// this-> is needed to identify the data member.
        this->DATA_TYPE = FLOAT;
	this-> f = f;

	//cerr << "operator=(float f)" << endl;
    }

    /* This code is necessary because previously there didn't exist an overloaded assignment operater that takes
     * a double. When trying to assign a double to a number object, the compiler compains:
     taggedUnion_temporary_object.cpp:141:7: error: ambiguous overload for ‘operator=’ (operand types are ‘Number’ and ‘double’)
       num1 = 12.5;
              ^
     * This is because the compiler could convert the double to a float, or to an int,
     * or even into a temporary Number object using the conversion constructor!
     * So in order to get rid of the ambiguity, we have to explicitly provide an overloaded assignment operator=
     * to handle the double.
     */

    Number& operator=(double d)
    {
        this->DATA_TYPE = FLOAT;
	this-> f = static_cast<float>(d);

	//cerr << "operator=(double d)" << endl;
    }

    ~Number() { /*cerr << "~Number()" << endl;*/ }

  private:
	    enum data_type { INTEGER, FLOAT } DATA_TYPE;

    union {
        int i;
        float f;
    };
};


ostream& operator<<(ostream& os, const Number& num)
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
	Number num1 = 200;
	Number num2 = 3.14;
	Number num3 = num1;
	Number num4 = num2;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	cout << "num3 = " << num3 << endl;
	cout << "num4 = " << num4 << endl;
	cout << endl;

	Number num5 = 8;
	cout << num5 << endl;
	num5 = 7;
	cout << num5 << endl;
	num5 = 1.2;
	cout << num5 << endl;
	num5 = 1;
	cout << num5 << endl;
	num5 = num1;
	cout << num5 << endl;
	num5 = num4;
	cout << num5 << endl;
        cout << endl;
	
    Number numbers[8];
	// In a "regular" modern C++11 renge-based for loop,
	// the "loop variable" gets set to every single one of the variables/objects/elements in the array.
	// As a result of this, it gets created and destroyed for every single iteration of the loop,
	// it gets created and destroyed for every single element.
	// In order to avoid this, we declare the loop variable as a const reference.
	//
	// The loop variable of a range based for loop has the same syntax as a function parameter.
	// So just like we don't want to copy elements unneedingly excessivley,
	// we can also just declare a const pass by reference loop variable for the range based for loop.
	/*
	for (Number element : numbers) {
		cout << element << ' ';
	}
	*/
	for (const Number& element : numbers) {
		cout << element << ' ';
	}
	cout << endl;
	
	numbers[0] = 5;
	numbers[1] = 1.1;
	numbers[2] = 3.14;
	numbers[3] = 18;
	numbers[4] = 4;
	numbers[5] = 7.0;
	numbers[6] = 1.12;
	numbers[7] = 32;
	/*
	for (Number element : numbers) {
		cout << element << ' ';
	}
	*/
	for (const Number& element : numbers) {
		cout << element << ' ';
	}
	cout << endl;

    return EXIT_SUCCESS;
}
