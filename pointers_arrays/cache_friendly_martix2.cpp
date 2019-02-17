#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;


int main()
{

    cout << "program2" << endl;

    int size;
    cout << "Enter the size of the matrix: ";
    cin  >> size;

    int matrix_size = size * size;
    int value = 0;

    int* matrix = new int[matrix_size];

    clock_t t1 = clock();

    for (int rowindex = 0; rowindex < matrix_size; rowindex += size) {
        for (int j = 0; j < size; ++j) {
	    matrix[rowindex + j] = value;
	    ++value;
	}
    }

    clock_t t2 = clock();

    for (int rowindex = 0; rowindex < matrix_size; rowindex += size) {
        for (int j = 0; j < size; ++j) {
	    cout << matrix[rowindex + j] << ' ';
	}
	cout << endl;
    }

    double elapsed = double(t2 - t1)/CLOCKS_PER_SEC;  // elapsed is the time in seconds
    cerr << "Time elapsed: " << elapsed << endl;

    delete[] matrix;
    matrix = nullptr;

    return EXIT_SUCCESS;
}
