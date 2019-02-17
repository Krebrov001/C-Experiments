#include <cstdlib>   // for EXIT_SUCCESS
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::ostream;


class Register {
  friend ostream& operator<<(ostream& ostr, Register reg);

  public:
    // A list of values denoting the possible registers that there can be.
    // Used as a parameter into the constructor to tell what register to initialize the object to.
    // Used as a clean way for the outside world to tell the class what register it wants.
    // Now the reason that this is provided as a data type with a tag, and no accompanying variable
    // is that the class Register doesn't need to store an enumerated variable.
    // A variable of that enumerated type only gets passed into the register constructor, which is not
    // even data associated with the Register.
    // The member functions of a class are not part of the class. They take the this pointer as the first argument.
    enum reg_name {EAX, EBX, ECX, EDX, ESI, EDI, EBP, ESP};

    Register() = delete;

    Register(reg_name the_register)
    {
        switch (the_register) {
	  case EAX:
    	      name[0] = 'E';
	      name[1] = 'A';
	      name[2] = 'X';
	      name[3] = '\0';
	      break;
	  case EBX:
	      name[0] = 'E';
	      name[1] = 'B';
	      name[2] = 'X';
	      name[3] = '\0';
	      break;
	  case ECX:
	      name[0] = 'E';
	      name[1] = 'C';
	      name[2] = 'X';
	      name[3] = '\0';
	      break;
	  case EDX:
	      name[0] = 'E';
	      name[1] = 'D';
	      name[2] = 'X';
	      name[3] = '\0';
	      break;
	  case ESI:
	      name[0] = 'E';
	      name[1] = 'S';
	      name[2] = 'I';
	      name[3] = '\0';
	      break;
	  case EDI:
	      name[0] = 'E';
	      name[1] = 'D';
	      name[2] = 'I';
	      name[3] = '\0';
	      break;
	  case EBP:
	      name[0] = 'E';
	      name[1] = 'B';
	      name[2] = 'P';
	      name[3] = '\0';
	      break;
	  case ESP:
	      name[0] = 'E';
	      name[1] = 'S';
	      name[2] = 'P';
	      name[3] = '\0';
	      break;
	  default:
	      name[0] = 'E';
	      name[1] = 'A';
	      name[2] = 'X';
	      name[3] = '\0';
	      break;
	}
    }
  private:
    char name[4];
};


ostream& operator<<(ostream& ostr, Register reg)
{
    ostr << reg.name;
    return ostr;
}


class Numero {
  friend ostream& operator<<(ostream& ostr, Numero& num)

  public:
    // In-class initializer is used to initialize the data_type when the Numbero object is first cosntructed.
    // Data members without in-class initializers will be default-constructed, which results in undefined values
    // for POD types.
    // In-class initializers were introducted in the C++11 standard.
    enum data_type {INT, FLOAT, REGISTER} DATA_TYPE = INT;

    // Uses the default compiler-generated constructor.
    // In this case, DATA_TYPE is initialized to INT by the in-class initializer,
    // and the Register::Register() default constructor zeroes out all the data for the union type.
    Numero() = default;

    Numero(int num)
    {
        data.i = num;
	DATA_TYPE = INT;
    }

    Numero(float num)
    {
        data.f = num;
	DATA_TYPE = FLOAT;
    }

    Numero(Register reg)
    {
        data.r = reg;
	DATA_TYPE = REGISTER;
    }

    void initialize(int num)
    {
        data.i = num;
	DATA_TYPE = INT;
    }

    void initialize(float num)
    {
        data.f = num;
	DATA_TYPE = FLOAT;
    }

    void initialize(Register reg)
    {
        data.r = reg;
	DATA_TYPE = REGISTER;
    }
  private:
    union four_bytes {
        int i;
	float f;
	Register r;

	// The union constructor zeroes out the bytes for that union.
        four_bytes() : i(0) {}
    } data;
};


ostream& operator<<(ostream& ostr, Numero& num)
{
    switch (num.DATA_TYPE) {
      case INT:
          cout << num.four_bytes.i << endl;
	  break;
      case FLOAT:
          cout << num.four_bytes.f << endl;
	  break;
      case REGISTER:
          cout << num.four_bytes.r << endl;
	  break;
    }
}


int main()
{
    Register reg1(Register::EBX);
    cout << reg1;

    Numero numaler;

    /*
    Numero numerals[8];
    numerals[0].initialize(2);
    */

    return EXIT_SUCCESS;
}
