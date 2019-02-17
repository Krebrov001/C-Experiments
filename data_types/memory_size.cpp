/*
 * Name             : memory_size.cpp
 * Author           : Konstantin Rebrov
 * Created on       : 30 December 2017
 * Last modified on : 30 December 2017
 * Description      : This program prompts the user to enter an amount of memory in GB
 *                    and prints out the equivalent amount of memory in:
 *                    - GB
 *                    - MB
 *                    - KB
 *                    - bytes
 *                    - bits
 *                    This program should be compiled with C++11 standard:
 *                      g++ -std=c++11 memory_size.cpp
 * Sources          : Zybooks C++ Figure 4.6.1
 */

#include <iostream>  // C++ input/output stream
#include <cstdlib>   // C standard library - for EXIT_SUCCESS
#include <cstdint>   // C standard integer data types
using std::cout;
using std::cin;
using std::endl;

int main() {
  const uint8_t bits_in_byte = 8;       // 1 byte is 8 bits
  const uint16_t bytes_in_KB = 0x0400;  // 1 kilobyte is 2^10 = 1024 bytes

  uint32_t memSizeGB    = 0;
  uint32_t memSizeMB    = 0;
  uint32_t memSizeKB    = 0;
  uint64_t memSizeBytes = 0;
  uint64_t memSizeBits  = 0;

  cout << "Enter memory size in GBs: ";
  cin  >> memSizeGB;

  /*
   * 1 byte = 8 bits
   * 1 KB = 2^10 bytes
   * 1 MB = 2^10 KB = 2^20 bytes
   * 1 GB = 2^10 MB = 2^20 KB = 2^30 bytes
   */

  memSizeMB = memSizeGB * bytes_in_KB;
  memSizeKB = memSizeMB * bytes_in_KB;
  memSizeBytes = static_cast<uint64_t>(memSizeKB) * bytes_in_KB;
  memSizeBits  = memSizeBytes * bits_in_byte;

  cout << endl;
  cout << "Memory size in GB:    " << memSizeGB << endl;
  cout << "Memory size in MB:    " << memSizeMB << endl;
  cout << "Memory size in KB:    " << memSizeKB << endl;
  cout << "Memory size in bytes: " << memSizeBytes << endl;
  cout << "Memory size in bits:  " << memSizeBits  << endl;

  return EXIT_SUCCESS;
}
