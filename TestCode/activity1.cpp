#include <iostream>
using namespace std;

int main() {
    int numArray[5] = {1, 3, 5, 7, 9};
    cout << "Base Address:" << numArray << endl;
    cout << "Base Address:" << &numArray[0] << endl;
    
    cout << "Address of element 4: " << numArray + 3 << endl;
    cout << "Address of element 4: " << &numArray[3] << endl;
    return 0;
}
