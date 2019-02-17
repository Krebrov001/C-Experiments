#include "apples_header.h"

using std::cout;
using std::endl;

int main() {
	// #defines in one file carry on and apply to the file which included them
	// as well.
	int num_apples = APPLES;
	cout << VAR << endl;

	// Preprocessor directives do not have semicolons (;) at their ends!
	// This is because Preprocessor directives are not C++ code statements!

	#ifdef LOGGING_ENABLED
	  #pragma message("Logging is enabled")
	#endif

	#define LOGGING_MIN 0
	#define LOGGING_MAX 10

	// #ifdef "executes" if a macro is defined, regardless of its value,
	// even if its value would be 0.

	// If a macro is not defined, the Preprocessor acts as though it does not
	// exist:
	// 1. It does not attempt to expand that macro, and
	// 2. Because the macro does not expand to any value at all (because it does
  //    not exist), any logical statement with it will not evaluate to anything.

	#if (LOGGING_LEVEL == LOGGING_MIN && \
	     LOGGING_FLAG)
		cout << "Logging is minimal" << endl;
	#elif (LOGGING_LEVEL == LOGGING_MAX && \
	       LOGGING_FLAG)
		cout << "Logging is maximum" << endl;
	#elif LOGGING_FLAG
		cout << "Logging is standard" << endl;
	#endif

	#ifdef LOGGING_LEVEL
	  cout << "LOGGING_LEVEL is defined" << endl;
	#endif

	cout << LOGGING_LEVEL << endl;

	return 0;
}
