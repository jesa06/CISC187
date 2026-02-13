#include <vector>
#include <random>
#include <iostream>
using namespace std;

int randomizedSearch(const vector<int>& data, int key, int& comparisons) {
    int n = data.size();
    comparisons = 0;

    // Create index list [0, 1, 2, ..., n-1]
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }

    // set up Random generator
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator

    // Fisher–Yates shuffle
    for (int i = n - 1; i > 0; --i) {
        uniform_int_distribution<> dist(0, i); //gives a number between 0 and i inclusive
        int j = dist(gen); //picks a random index j in [0, i]
        swap(indices[i], indices[j]); //ensures that every element has an equal chance of ending up in any position
    }

    // Search in randomized order
    for (int k = 0; k < n; ++k) {
        int i = indices[k];
        comparisons++;

        if (data[i] == key) {
            return i;  // Found
        }
    }

    return -1;  // Not found
}

int main() {
    const int N = 100000;

    // Create dataset of 100,000 distinct elements
    vector<int> data(N);
    for (int i = 0; i < N; ++i) {
        data[i] = i + 1;  // distinct values 1..100000
    }

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    int comparisons = 0;
    int index = randomizedSearch(data, key, comparisons);

    if (index != -1)
        cout << "Key found at index: " << index << endl;
    else
        cout << "Key not found." << endl;

    cout << "Comparisons performed: " << comparisons << endl;

    return 0;
}
