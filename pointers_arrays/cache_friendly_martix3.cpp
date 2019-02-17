#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;


int main()
{

    cout << "program3" << endl;

    int size;
    cout << "Enter the size of the matrix: ";
    cin  >> size;

    int value = 0;

    int (*matrix)[size] = static_cast<int(*)[size]>( malloc(sizeof(int[size][size])) );

    clock_t t1 = clock();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
	    matrix[i][j] = value;
	    ++value;
	}
    }

    clock_t t2 = clock();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
	    cout << matrix[i][j] << ' ';
	}
	cout << endl;
    }

    double elapsed = double(t2 - t1)/CLOCKS_PER_SEC;  // elapsed is the time in seconds
    cerr << "Time elapsed: " << elapsed << endl;

    delete[] matrix;
    matrix = nullptr;

    return EXIT_SUCCESS;
}
