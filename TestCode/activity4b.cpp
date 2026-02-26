#include <random>
#include <iostream>
using namespace std;

// PART A 
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // lower val placed at index 0
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) { // compare lower val with the index above
                minIndex = j; // make the higher index the lower value if so
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) { //i is current element being inserted
        int key = arr[i]; // storing current inserting value
        int j = i - 1; //Start comparing with the element to the left
        // j moves backward through the sorted portion

    // keep moving left as long as we haven't passed the beginning and current value is bigger than the key
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; //Shift the larger value one step to the right
            j--; // move left
        }

        arr[j + 1] = key; // insert key into correct position
    }
}

string analyzeArray(int arr[], int n) {
    int ascendingPairs = 0;
    int descendingPairs = 0;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] <= arr[i + 1])
            ascendingPairs++;
        if (arr[i] >= arr[i + 1])
            descendingPairs++;
    }

    if (ascendingPairs >= 0.8 * (n - 1))
        return "best";
    else if (descendingPairs >= 0.8 * (n - 1))
        return "worst";
    else
        return "average";
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    const int N = 50;
    int arr[N]; // create array

    // Fill array (example random values)
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 100;

    cout << "Original array:\n";
    printArray(arr, N);

// analyze the array to choose which sort
    cout << "Analyzing code...if 80% or more adjacent elements are in ascending order, using Insertion Sort." << endl;
    cout << "If 80% or more adjacent elements are in decreasing order, using Selection Sort." << endl;
    cout << "Otherwise, average case, using Selection Sort." << endl;

    string scenario = analyzeArray(arr, N);

    if (scenario == "best") {
        cout << "Using Insertion Sort (Best/Nearly Sorted Case)\n";
        insertionSort(arr, N);
     }
    else if (scenario == "worst") {
        cout << "Using Selection Sort (Reverse Sorted Case)\n";
        selectionSort(arr, N);
    }
    else {
        cout << "Using Selection Sort (Average Case)\n";
        selectionSort(arr, N);
    }

    return 0;
}
