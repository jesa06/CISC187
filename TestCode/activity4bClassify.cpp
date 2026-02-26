#include <random>
#include <iostream>
using namespace std;

// PART B
string classifyArray(int arr[], int n) {
    int ascendingPairs = 0;
    int descendingPairs = 0;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] <= arr[i + 1])
            ascendingPairs++;
        if (arr[i] >= arr[i + 1])
            descendingPairs++;
    }

      // 80% threshold
    if (descendingPairs >= 0.8 * (n - 1))
        return "Worst Case";
    else
        return "Average Case";
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

    // Fill array (with user input)
    cout << "Enter 50 integers:\n";
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout << "Original array:\n";
    printArray(arr, N);

     string result = classifyArray(arr, N);

    cout << "\nClassification: " << result << endl;

    return 0;
}
