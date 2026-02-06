#include <iostream>
using namespace std;

int main() {
    int numArray[5] = {1, 3, 5, 7, 9};
    cout << "Base Address:" << numArray << endl;
    cout << "Base Address:" << &numArray[0] << endl;
    
    cout << "Address of element 4: " << numArray + 3 << endl;
    cout << "Address of element 4: " << &numArray[3] << endl;


    cout << "===================================" << endl;

    string array[5] = {"bananas", "apples", "apples", "oranges", "apples"};

    int count = 0;
    int length = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < length; ++i) {
        if (array[i] == "apples") {
            count++;
        }
    }

    cout << "Number of 'apples': " << count << endl;
        return 0;
    }
