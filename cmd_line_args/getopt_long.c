#include <getopt.h>  // GetOpt library          - for getopt_long()
#include <stdio.h>   // C standard input/output - for fprintf(), printf(), stdout, stderr
#include <stdlib.h>  // C standard library

/* The name of this program. */
const char* program_name;

/* Prints usage information for this program to stream (typically
   stdout or stderr), and exit the program with exit_code. Does not return.
 */
/* In C/C++, adjacent string litrals are concetenated.
   The fprintf() statement takes advantage of this to print one single big format string,
   breaking it up into parts.
   The programmer easily visualizes what the user will see printed on the screen.
   Instead of having multiple fprintf() statements, the \n separates the output into new lines.
 */

void print_usage(FILE* stream, int exit_code)
{
  fprintf(stream, "Usage:  %s options [ inputfile ... ]\n", program_name);
  fprintf(stream,
          "  -h  --help             Display this usage information.\n"
	  "  -o  --output filename  Write output to file.\n"
	  "  -v  --verbose          Print verbose messages.\n");
  exit(exit_code);
}

/* Main program entry point. ARGC contains number of argument list
   elements; ARGV is an array of pointers to them. */
