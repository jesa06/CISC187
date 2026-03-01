#include <random>
#include <iostream>
#include <cstdlib>   // for rand()
#include <algorithm>
using namespace std;

// PART A 
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // lower val placed at index 0
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) { // compare lower val with the index above
                minIndex = j; // make the higher index the lower value if so
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int n, int &comparisons, int &shifts) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;  // count comparison

            if (arr[j] > key) {
                arr[j + 1] = arr[j]; // shift
                shifts++;
                j--;
            } else {
                break;
            }
        }

        arr[j + 1] = key; // insertion
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
    cout << "Scenario: " << scenario << endl;
   
   int comp = 0, shifts = 0;

    if (scenario == "best") {
        cout << "\nBest, Using Insertion Sort (Nearly Sorted Case)\n";
        insertionSort(arr, N, comp, shifts);
        cout << "Comparisons: " << comp << endl;
        cout << "Shifts: " << shifts << endl;
     }
    else if (scenario == "worst") {
        cout << "\nWorst, Using Selection Sort (Reverse Sorted Case)\n";
        selectionSort(arr, N);
    }
    else {
        cout << "\nUsing Selection Sort (Average Case)\n";
        selectionSort(arr, N);
    }

    cout << "Test worst case scenario with 5 elements: arr[5] = {5, 4, 3, 2, 1}.\n";
    int worstArr[5] = {5, 4, 3, 2, 1};
    comp = 0, shifts = 0;
    insertionSort(worstArr, 5, comp, shifts);  
    cout << "Comparisons: " << comp;
    cout << "\nShifts: " << shifts;  

    return 0;
}
