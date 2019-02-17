/**
 * The main purpose of this program is to see what range of
 * values main() can return to the operating system.
 *
 * This program should be compiled with a command-line defined
 * macro, RET_VAL, representing the desired value to be returned
 * to the OS.
 * g++ -D RET_VAL=0 return_numbers.cpp 
 */
int main()
{
  return RET_VAL;
}
