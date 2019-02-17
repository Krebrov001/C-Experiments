#include <iostream>
#include <climits>
using namespace std;


void showBits(int num) {
  int num_bits = sizeof(int) * CHAR_BIT;
  for (int i = (num_bits - 1); i >= 0; i--) {
    cout << ((num >> i) & 0x1);
  }
}


int main()
{
    // This array can store upto 12 elements (3x2x2)
    int test[3][2][2];

    // Compress the above 3-D array into a 2-D array.
    int pixel[2][2];

    cout << "Enter 12 values: \n";
    
    // Inserting the values into the test array
    // using 3 nested for loops.
    for(int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for(int k = 0; k < 2; ++k )
            {
                cin >> test[i][j][k];
            }
        }
    }

    cout<<"\nDisplaying Value stored:"<<endl;

    // Displaying the values with proper index.
    for(int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for(int k = 0; k < 2; ++k)
            {
                cout << "test[" << i << "][" << j << "][" << k << "] = " << test[i][j][k] << endl;
            }
        }
    }

    cout << "test is " << sizeof(test) << " bytes long." << endl;

    int num_elements = sizeof(test) / sizeof(int);
    
    cout << "There are " << num_elements << " elements in test." << endl;

    int* p = (int*) test;

    for (int i = 0; i < num_elements; i++) {
      cout << *p << ' ';
      p++;
    }
    cout << endl;

    /*
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 3; k++) {
          *(((char*)  &(pixel[i][j])) +k) = test[k][i][j];
	}
      }
    }

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 3; k++) {
          cout << (int) *(((char*)  &(pixel[i][j])) +k) << ' ';
	}
      }
    }
    cout << endl;

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        cout << (int) pixel[i][j] << ' ';
      }
    }
    cout << endl;
    */

        for (int j = 0; j < 2; ++j)
        {
            for(int k = 0; k < 2; ++k )
            {
	       *(((unsigned char*) (pixel + (j * 2 + k))) + 0) = test[0][j][k];
	       *(((unsigned char*) (pixel + (j * 2 + k))) + 1) = test[1][j][k];
	       *(((unsigned char*) (pixel + (j * 2 + k))) + 2) = test[2][j][k];
            }
        }

    for (int row = 0; row < 2; row++) {
      for (int col = 0; col < 2; col++) {
	       cout << (int) *(((unsigned char*) (pixel + (row * 2 + col))) + 0) << ' ';
	       cout << (int) *(((unsigned char*) (pixel + (row * 2 + col))) + 1) << ' ';
	       cout << (int) *(((unsigned char*) (pixel + (row * 2 + col))) + 2) << ' ';
	       cout << endl;
      }
    }

    // Output the array in high-level, sorted, logical/algorithmical order.
    for (int plane = 0; plane < 3; plane++) {
      for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
	  cout << (int) *(((unsigned char*) (pixel + (row * 2 + col))) + plane) << ' ';
	}
      }
    }
    cout << endl;

    for (int i = 1; i <= 12; i++) {
      cout << i << ' ';
      showBits(i) ;
      cout << endl;
    }

    for (int row = 0; row < 2; row++) {
      for (int col = 0; col < 2; col++) {
        showBits(pixel[row][col]);
	cout << endl;
      }
    }

    return 0;
}
