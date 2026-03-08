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
hash(string) = 

```cpp
int HashTable::hashFunction(const string& key) const {
    const int prime = 31;
    long long hash = 0;

    for (char c : key) {
        hash = hash * prime + c;
    }

    return hash % capacity; // compresses that large number into a valid index.
}
```

## Part 3: Insert & Collision Handling
## Part 4: Resizing (Rehashing)
## Part 5: Testing Program
```c++
#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;


// Part 1 -- Class Structure

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
        int getSize() const; 
        bool isEmpty() const;
        void printTable() const;
        int getCapacity() const;
        int getCollisionCount() const;
};

bool HashTable::remove(const string& key) {
    int index = hashFunction(key);

    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            table[index].erase(it);  // remove the pair
            currentSize--;           // update size
            return true;             // successful removal
        }
    }

    return false; // key not found
}


int HashTable::search(const string& key) const {
    int index = hashFunction(key);

     for (const auto& pair : table[index]) {
        if (pair.first == key) {
            return pair.second;
        }
    }

    return -1; // key not found
}

int HashTable::getCapacity() const {
    return capacity;
}

int HashTable::getCollisionCount() const {
    return collisionCount;
}

int HashTable::getSize() const {
    return currentSize;
}

HashTable::HashTable(int size) : capacity(size), currentSize(0), collisionCount(0) {
    table.resize(capacity); // create empty lists for each bucket
}

// Part 2 -- Hash Function

int HashTable::hashFunction(const string& key) const {
    const int prime = 31;
    long long hash = 0;

    for (char c : key) {
        hash = hash * prime + c;
    }

    return hash % capacity;
}

double HashTable::loadFactor() const {
    return 1.0 * currentSize/capacity; // ensure it is a double 
}

// Part 3 -- Insert & Collision Handling
void HashTable::insert(const string& key, int value) {
    if (loadFactor() > 0.75) {
        rehash();
    }

    int index = hashFunction(key);

    for (auto& pair : table[index]) { // check if key exists
        if (pair.first == key) {
            pair.second = value; // update value instead of duplicating
            return;
        }
    }

    // If inserting into a non-empty bucket, increment collisionCount
    if (!table[index].empty()) {
            collisionCount++;
    } 
    
    // Insert new key-value pair
    table[index].push_back({key, value});
    currentSize++;
}


// Part 4 -- Resizing (Rehashing)
void HashTable::rehash() {
    int oldCapacity = capacity;
    capacity *= 2; // double capacity
    vector<list<pair<string,int>>> oldTable = table;  // save old data
    table.clear();                // empty table
    table.resize(capacity);       // create new empty buckets w doubled capacity
    currentSize = 0;              // will reinsert elements
    collisionCount = 0;           // reset collisions

    for (int i = 0; i < oldCapacity; ++i) { // reinsert all elements
        for (auto &pair : oldTable[i]) {
            insert(pair.first, pair.second);
        }
    }
}

// Part 5 -- Testing Program

int main() {
    const int N = 100;
    vector<string> words = {"dog", "cats", "athyna", "elly", "oakley", "pippy", "red", "blue", "green", "purple",
                    "apple", "banana", "mango", "grape", "egg", "fish", "house", "music", "door", "gate",
                    "drum", "piano", "microphone", "guitar", "speaker", "television", "window", "pet", "leash", "collar",
                    "black", "white", "person", "student", "teacher", "school", "college", "class", "exam", "quiz",
                    "bag", "table", "car", "keys", "tree", "bird", "grass", "mirror", "light", "floor",
                    "seat", "couch", "basket", "laundry", "food", "dessert", "drink", "blanket", "bed", "pillow",
                    "phone", "wallet", "hairbrush", "toothbrush", "computer", "laptop", "homework", "work", "job", "sport",
                    "exercise", "train", "gym", "run", "walk", "eat", "plant", "life", "love", "laugh",
                    "fruit", "Jesus", "God", "church", "worship", "praise", "patience", "humble", "kind", "death",
                    "gospel", "truth", "way", "light", "chair", "shoe", "pants", "shirt", "road", "sky"};

    HashTable ht; 

    for (int i = 0; i < 100; i++) {
        ht.insert(words[i], i);  // or some value
    }
    cout << "Table capacity: " << ht.getCapacity() << endl;
    cout << "Number of elements: " << ht.getSize() << endl;
    cout << "Load factor: " << ht.loadFactor() << endl;
    cout << "Total collisions: " << ht.getCollisionCount() << endl;

    // Search for: Existing key & Non-existing key
    cout << "Searching for 'road'... " << endl; 
    int existResult = ht.search("road");
    if (existResult != -1) {
        cout << "'road' found at index " << existResult << endl;
    } else {
        cout << "'road' NOT found" << endl;
    }

    cout << "Searching for 'dragon'... " << endl; 
    int nonExistResult = ht.search("dragon");
    if (nonExistResult != -1) {
        cout << "'dragon' found at index " << nonExistResult << endl;
    } else {
        cout << "'dragon' NOT found" << endl;
    }

    cout << "Removing 'road'..." << endl;
    if (ht.remove("road")) {
        cout << "Successfully removed 'road'!" << endl;
    } else {
        cout << "Error removing 'road'!" << endl;
    }

    int result2 = ht.search("road");
     if (result2 != -1) {
        cout << "'road' found at index " << result2 << endl;
    } else {
        cout << "'road' NOT found" << endl;
    }


    // Part 6 -- Experimental Analysis
    cout << "============ Experimental Analysis ============" << endl;

    const int TEST_SIZE = 100;

    /* -------- Random Strings -------- */
    HashTable randomStrings;
    for (int i = 0; i < TEST_SIZE; i++) {
        randomStrings.insert(words[i], i); //uses my hard coded random words list
    }

    cout << "\nRandom Strings:" << endl;
    cout << "Total collisions: " << randomStrings.getCollisionCount() << endl;
    cout << "Maximum bucket size: " << randomStrings.getMaxBucketSize() << endl;
    cout << "Average bucket length: " << randomStrings.getAverageBucketLength() << endl;

    /* -------- Sequential Keys -------- */
    HashTable sequentialKeys;
    for (int i = 0; i < TEST_SIZE; ++i) {
        string key = "student" + to_string(i); //student0, student1,...
        sequentialKeys.insert(key, i);
    }

    cout << "\nSequential Keys:" << endl;
    cout << "Total collisions: " << sequentialKeys.getCollisionCount() << endl;
    cout << "Maximum bucket size: " << sequentialKeys.getMaxBucketSize() << endl;
    cout << "Average bucket length: " << sequentialKeys.getAverageBucketLength() << endl;


    /* -------- Same Prefix Keys -------- */
    HashTable prefixKeys;

    for (int i = 0; i < TEST_SIZE; i++) {
        string key = "data_" + to_string(i); //data_0, data_1,...
        prefixKeys.insert(key, i);
    }

    cout << "\nSame Prefix Keys:" << endl;
    cout << "Total collisions: " << prefixKeys.getCollisionCount() << endl;
    cout << "Maximum bucket size: " << prefixKeys.getMaxBucketSize() << endl;
    cout << "Average bucket length: " << prefixKeys.getAverageBucketLength() << endl;

    return 0;
}

```
## Part 6:  Experimental Analysis 
> Short Explanation: The experimental analysis shows that the random string inputs produced the most collisions in the hash table. A total of 19 collisions occurred, and the maximum bucket size reached 3. This indicates that some of the randomly distributed words hashed to the same index, which caused multiple elements (3) to be stored in the same bucket. The average bucket length remained relatively small, showing that overall the elements were still distributed fairly evenly across the table.

In contrast, the sequential keys and the keys with the same prefix produced no collisions, with a maximum bucket size of only 1. This means that each key was placed into a different bucket. The hash function was able to distribute these keys effectively even though they followed a predictable pattern. As a result, the average bucket length was the same across tests, but the lack of collisions shows that the hash function (polynomial hashing) handled these structured keys very efficiently.The average bucket length remained the same across all three tests because it is calculated by dividing the total number of elements by the table capacity. Since each experiment inserted the same number of elements and the table resized to the same capacity, the average bucket length did not change. However, the number of collisions and maximum bucket size varied depending on how evenly the hash function distributed the keys.

```md
**Experiment 6 Results**
Total collisions: 19
Maximum bucket size: 3
Average bucket length: 0.568182

Sequential Keys:
Total collisions: 0
Maximum bucket size: 1
Average bucket length: 0.568182

Same Prefix Keys:
Total collisions: 0
Maximum bucket size: 1
Average bucket length: 0.568182
```