# Activity 3: Implementing a Hash Table with Separate Chaining
----------------------------------

## Part 1: Class Structure
```cpp
#include <vector>
#include <list>
#include <string>
using namespace std;

class HashTable {
private:
    vector<list<pair<string, int>>> table;
    int currentSize;
    int capacity;
    int collisionCount;

    int hashFunction(const string& key) const;
    void rehash();

public:
    HashTable(int size = 11);

    void insert(const string& key, int value);
    bool remove(const string& key);
    int search(const string& key) const;
    double loadFactor() const;
    int size() const;
    bool isEmpty() const;
    void printTable() const;
};
```

## Part 2: Hash Function
> Implement a polynomial rolling hash:
```cpp
int HashTable::hashFunction(const string& key) const {
    const int prime = 31;
    long long hash = 0;

    for (char c : key) {
        hash = hash * prime + c;
    }

    return hash % capacity;
}
```

## Part 3: Insert & Collision Handling
Use separate chaining (vector<list<>>)
If inserting into a non-empty bucket, increment collisionCount
If key already exists, update value instead of duplicating

## Part 4: Resizing (Rehashing)

## Part 5: Testing Program

## Part 6:  Experimental Analysis 
> Short Explanation: