#include <cstdint>   // for uint8_t
#include <cstdlib>   // for size_t, EXIT_SUCCESS
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


void fillPrices(void* ptr, size_t num_of_stations)
{
    // The pointer is const but the data is not const.
    uint8_t (* const prices)[num_of_stations] = static_cast<uint8_t(*)[num_of_stations]>(ptr);

    for (size_t row = 0; row < num_of_stations; ++row) {
	// The price to get from one station to itself is 0.
	prices[row][row] = 0;

        for (size_t col = row + 1; col < num_of_stations; ++col) {
	    int price = 0;
	    cout << "prices[" << row << "][" << col << "] = ";
	    cin >> price;
	    // Type cast is needed because we are reading in an int but we are storing uint8_t into the matrix.
	    // uint8_t is read in as char by default.
	    prices[row][col] = static_cast<uint8_t>(price);
	}
    }
}


void calculateTables(void* ptr, vector<uint8_t>& C, vector<uint8_t>& B)
{
    register size_t num_of_stations = C.size();

    // Both the data is const and the pointer is const.
    const uint8_t (* const prices)[num_of_stations] = static_cast<uint8_t(*)[num_of_stations]>(ptr);

    C.at(0) = 0;
    B.at(0) = 0;

    // Put the loop counters and the temporary variable in registers for faster access.

    for (register size_t i = 1; i < num_of_stations; ++i) {

        for (register size_t j = 0; j < i; ++j) {
	    register uint8_t current_cost = C.at(j) + prices[j][i];
	    if (current_cost < C.at(i)) {
	        C.at(i) = current_cost;
		B.at(i) = j;
	    }
	}

    }
}


void printTables(const vector<uint8_t>& C, const vector<uint8_t>& B)
{
    register size_t num_of_stations = C.size();

    register size_t i = 0;
    cout << "C: ";
    for (i = 0; i < num_of_stations; ++i) {
	// Type cast is needed because uint8_t is printed as a char by default.
        cout << static_cast<int>(C.at(i)) << ' ';
    }
    cout << endl;
    cout << "B: ";
    for (i = 0; i < num_of_stations; ++i) {
	cout << static_cast<int>(B.at(i)) << ' ';
    }
    cout << endl;
}


int main()
{
    size_t num_of_stations = 0;
    cin >> num_of_stations;

    uint8_t (*prices)[num_of_stations] = static_cast<uint8_t(*)[num_of_stations]>( malloc(sizeof(uint8_t[num_of_stations][num_of_stations])) );

    fillPrices(prices, num_of_stations);
    cout << endl;

    vector<uint8_t> C(num_of_stations, UINT8_MAX);  // Min-cost table
    vector<uint8_t> B(num_of_stations, UINT8_MAX);  // Backtracking table

    calculateTables(prices, C, B);

    printTables(C, B);

    delete[] prices;
    prices = nullptr;

    return EXIT_SUCCESS;
}
