#include <iostream>
#include <cstdlib>     // for rand, srand
#include <ctime>       // for time (seed)
using namespace std;

int linearSearch(int arr[], int size, int key, int &steps) {
    steps = 0; // initialize
    for (int i = 0; i < size; ++i) {
        steps++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; //if not found
}

int binarySearch(int arr[], int size, int key, int &steps) {
    steps = 0;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        steps++;
        int mid = (left + right) / 2; // find midpoint

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            left = mid + 1; // change lower index of search
        }
        else {
            right = mid - 1;
        }
        
    }
    return -1;
}

int main() {
    const int SIZE = 100000;
    int numArray[SIZE];
    int key;
    int stepsLin;
    int stepsBin;
    
    srand(time(0));

    // randomize array elements
    for (int i = 0; i < SIZE; i++) {
        
        numArray[i] = rand() % 100001;   // random numbers
    }
   
    cout << "What integer would you like to search for? (0-100,000)" << endl;
    cin >> key;
    
    int posLin = linearSearch(numArray, SIZE, key, stepsLin);

    sort(numArray, numArray + SIZE);

    int posBin = binarySearch(numArray, SIZE, key, stepsBin);

    cout << "Linear Search Steps: " << stepsLin << endl;
    cout << "Binary Search Steps: " << stepsBin << endl;

    if (posLin != -1)
        cout << "Linear Search: Found at index " << posLin << endl;
    else
        cout << "Linear Search: Not found" << endl;

    if (posBin != -1)
        cout << "Binary Search: Found at index " << posBin << endl;
    else
        cout << "Binary Search: Not found" << endl;

    return 0;
}
