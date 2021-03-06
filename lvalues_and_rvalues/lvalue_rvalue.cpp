// This lesson is about lvalues and rvalues.

/*
 * Simplified Definition:
 *
 * lvalue = logical address value
 *          An object that occupies some identifiable location in memory
 *          It is a "place" where data can be stored.
 *          An lvalue has an address associated with it.
 *
 * rvalue = register value
 *          Any object that is not a lvalue
 *          It is "the data" that is loaded into the lvalue,
 *          or memory location.
 *          An rvalue does not occupy some identifiable location in memory
 */


 // lvalue Examples:
 int i;        // i is a lvalue because it is a place where data can be stored
 int* p = &i;  // i's address is identifiable - i has a location in memory
i = 2;     // Memory content of a lvalue can be modified
           // The rvalue 2 is stored inside the lvalue i

class dog;  // We have the declaration of the dog class.
            // Let's suppose we have a class named dog.

class dog { ... };  // definition of the dog class.

dog d1;  // lvalue of user defined type (class dog)
         // It's a dog object stored somewhere in memory
	 // and it has an address.

	 // Most variables in C++ code are lvalues


// rvalue Examples:
int x = 2;       // 2 is an rvalue because it does not have a
                 // memory location associated with it.

int x = i + 2;   // (i + 2) is an rvalue
                 // it is a data value which can be assigned to a 
		 // memory location
		 // x is an lvalue

int* p = &(i + 2);  // Error: (i + 2) is an rvalue, therefore you cannot
                    // take the address of that expression,
		    // it does not have a memory location.

i+2 = 4;  // Error: (i + 2) is an rvalue, you cannot store any data
          // inside of it.

2 = i;  // Error: Same as above, you cannot have an rvalue on the left side
        //        of the assignment = operator.
	// Since the rvalue 2 does not have a memory location, into where
	// do you want to store the value of i?
	// It's unknown.

dog d1;  // create an object of type dog
d1 = dog();  // dog() is rvalue of user defined type (class)
             // The default constructor sets the private data members,
	     // and returns an "anonymous" rvalue object of the dog class,
	     // with no memory location.
	     // That dog rvalue is then placed into the d1 lvalue.
	     // It actually just copies all the data members of the rvalue
	     // into the d1 lvalue.
	     // d1 is an object of the dog class, WITH AN IDENTIFIABLE
	     // MEMORY LOCATION. It "lives" in the memory.

// int x = 3;
// int y = 4;
// int x is a formal parameter (parameter)
// 3, the value which is passed into the function,
// is an actual parameter (argument)
//
//   The formal parameter (parameter) is an lvalue,
//   which has space on the stack.
//
//   The actual paramter (argument) is an rvalue,
//   which is placed into the lvalue.
//
// lvalue = rvalue;
int sum(int x, int y) {
  return x + y;  // is rvalue
}

// int i = (x + y);
int i = sum(3, 4);  // sum(3, 4) is rvalue
                    // to be more exact, the function call returns an int
		    // rvalue, (x + y), which is then assigned into the
		    // int lvalue i.

// rvalues: 2, i+2, dog(), 3, 4, x+y, sum(3, 4)
// lvalues: x, i, d1, p
// int* p is also an lvalue because it lives on the stack, and has a
// memory location associated with it, even though it can hold the
// address of another lvalue.


// Reference (or lvalue reference):
int i;
int& r = i;  // r is an int reference variable
             // it is a reference for the lvalue i
	     // it is now another name for the lvalue i,
	     // and both r and i refer to the same data object,
	     // occupying the same memory location.
// Notice that in this situation, an lvalue is on both sides of the
// = assignment operator.

int& r = 5;  // Error: you cannot do an rvalue reference
             // This is because a Reference (or lvalue reference)
	     // demands an lvalue on the right side of the = assignment
	     // operator.
// Think about it, how would you create a reference from an rvalue?
// What is the memory location of the int literal 5?
// The Reference variable r cannot refer to 5 since it has nowhere to refer to
// An rvalue does not have a memory location associated with it.
//
// An rvalue, such as the literal 5, for example, is stored in a register.
// The int literal 5 is just a bunch of bits generated by the ALU,
// they get sent via the bus to a register and stored there.
// Then the rvalue is moved from the register into the lvalue (a location in memory)
// The expression (x + y) is an rvalue. It gets created by:
// 1. Loading the value of x into a register, overwriting its former contents.
// 2. Adding the value of y to the value held in that register.
// 3. Storing the rvalue (x + y) from the register into the given lvalue.


// Exception: Constant lvalue reference can be assign a rvalue:
const int& r = 5;
// What is happening in this code right here?
// An "anonymous" lvalue, a "nameless location" COULD BE allocated in memory
// The rvalue 5 is placed into that "temporary" lvalue.
// Then that constructed lvalue is now on the right side of the = assignment operator
// Then the reference variable r is assigned to reference that lvalue
// The reference variable r is now set to be another name for that lvalue
// cout << r << endl;  would print me the contents of that memory address,
// which is 5.
//
// A Reference (or lvalue reference) must have a lvalue on the right side
// of the = assignment operator.
// It cannot have an rvalue on the right side of the = assignment operator,
// except for a Consant lvalue reference!
// Why is this the case?
// A constant lvalue reference variable cannot be reassigned to
// a different lvalue.
// If that would be the case, and we assigned r to reference the
// "temporary" lvalue created out of 5,
// and then reassigned the reference to a different lvalue,
// we would have orphaned the original "5 lvalue",
// which would be a major problem!

// This function has an lvalue reference as a paramter.
// The formal parameter (parameter), which is a reference variable,
// is set as another name for the actual parameter (argument),
// which MUST BE a lvalue.
int square(int& x) {
  return x*x;  // returns a rvalue expression
}

square(i);   // int& x = i;   OK: x is set to reference the lvalue i
square(40);  // int& x = 40;  Error: x cannot reference the rvalue 40

// Workaround:
// Now the formal parameter (parameter) is a const lvalue reference.
int square(const int& x) {
  return x*x;
}

square(i);   // const int& x = i;
             // OK: x is set to reference the lvalue i and that reference
	     //     cannot be changed.
square(40);  // const int& x = 40;
             // OK: a "temporary" lvalue is created in memory, the rvalue
	     //     40 is placed into that lvalue,
	     //     and x is set as another name (reference) for that lvalue
             // It is worth noting that x expires when the function ends,
	     // so the lvalue containing 40 goes out of scope,
	     // and we no longer have access to that memory location.


/*
 * lvalue can be used to create an rvalue
 */
int i = 1;  // i an an lvalue
int x = i + 2;  // The quantity i+2 is an rvalue.
                // The data stored in i is loaded into a register,
		// the literal (immediate value) 2 is added to that register,
		// and the resulting rvalue is moved from the register into the lvalue x.

int x = i;  // The data (which is an rvalue) stored in i,
            // is moved into the lvalue x.
	    // An lvalue can be implicitly transformed into a rvalue in
	    // C++ source code depending on the context.
// However, an rvalue cannot be implicitly transformed into an lvalue.
// An rvalue MUST BE EXPLICITLY transformed into an lvalue,
// as the above example with the const lvalue reference illustrates.


/*
 * rvalue can be used to create an lvalue
 */
int v[3];
*(v+2) = 4;  // The expression v+2 is an rvalue.
             // It represents the address of a memory location.
	     // Most likely it is held inside of a register.
	     // The dereference of that rvalue generates a lvalue,
	     // or goes to that memory location and stores the rvalue
	     // 4 inside of it.


/*
 * Misconception 1: function or operator always yields rvalues.
 */
 int x = i + 3;      // The quantity (i + 3) is an rvalue
 int y = sum(3, 4);  // The function sum() just happens to return an rvalue

int myglobal;
// this function returns an int& - which is an lvalue
int& foo() {
  return myglobal;  // returns a reference to myglobal
}

foo() = 50;  // int& lvalue = int rvalue;
             // Not all functions return rvalues.
             // A function that returns a reference variable
	     // returns an lvalue.
// foo() returned a reference, or another name, for myglobal
// myglobal = 50;

// A more common example:
array[3] = 50;  // Operator [] almost always generates lvalue
                // Not all operators generate rvalues.


/*
 * Misconception 2: all lvalues are modifiable.
 *
 * C language: lvalue means "value suitable for left-hand-side of assignment"
 */
const int c = 1;  // c is a lvalue
c = 2;  // Error: because c is declared as a const int,
        // its memory contents cannot be changed.
	// Here, c is an example of an lvalue that is not modifiable.
// ISO C introduced the const qualifier.


/*
 * Misconception 3: rvalues are not modifiable.
 */
i + 3 = 6;  // Error: the rvalue expression i+3 is not modifiable,
            // it is read-only
sum(3, 4) = 7;  // Error: sum() returns an int, an rvalue
                // which is not modifiable.

// It is not true for user defined type (class)
// suppose we have the dog class mentioned above.
class dog;

// the default constructor of the dog class initializes variables
// and returns an rvalue of the dog class.
dog().bark();  // bark() may change the state of the dog object.

// rvalues of the default data types are not modifiable,
// whereas the rvalues of a user defined type may be modifiable.
