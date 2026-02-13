# Activity 2: Linear and Binary Search
----------------------------------

## Tasks

1. How many steps would it take to perform a linear search for the number 8 in the ordered array, [2, 4, 6, 8, 10, 12, 13]? - 1 pt
> It would take 4 steps to find number 8 using linear search because it is the 4th element of the array and linear search just compares the key to the elements of the array sequentially, starting from the beginning of the array to the end.

2. How many steps would binary search take for the previous example? - 1 pt
> It would only take 1 step to find number 8 using binary search because it first checks the middle element of the list, and 8 is at the middle. (0+6) / 2 = 3... index 3

3. What is the maximum number of steps it would take to perform a binary search on an array of size 100,000? - 1 pt
> The maximum number of steps it would take to perform a binary search on an array of 100,000 elements would be log2(100,000) which is about 17 steps.
    * 2^16 = 65,536
    * 2^17 = 131,072

4. Write a C++ program that implements both linear search and binary search algorithms using an array of 100,000 elements. The program should record and report the number of steps (comparisons) performed during each search operation. In addition, analyze and justify the observed behavior by providing a theoretical explanation using Big-O notation, demonstrating why linear search exhibits O(N) complexity and binary search exhibits O(log⁡N) complexity. - 2 pts

5. Write pseudocode for a randomized search algorithm that searches for a given key by randomly selecting indices without repetition. Use a dataset of 100,000 distinct elements, stored in a vector. Each element may be examined at most once during the search. Analyze and state the best-case, average-case, and worst-case time complexities of this algorithm using Big-O notation.
    * Then, implement the algorithm in C++, using only the following standard headers: <vector> for data storage, <random> for random index generation, and <iostream> for input and output. The implementation should track and report the number of comparisons performed during the search.
    * Finally, compare and contrast the randomized search algorithm with linear search and binary search in terms of time complexity, data requirements (such as ordering), and practical efficiency. Discuss scenarios in which each approach may be preferred, highlighting the advantages and limitations of randomized search relative to linear and binary search. - 5 pts
    
```c++
RandomizedSearch(vector A of size N, key):

    Create vector indices of size N
    For i from 0 to N-1:
        indices[i] ← i

    // Shuffle indices randomly (Fisher–Yates)
    For i from N-1 down to 1:
        j ← random integer in [0, i]
        swap(indices[i], indices[j])

    comparisons ← 0

    For k from 0 to N-1:
        i ← indices[k]
        comparisons ← comparisons + 1

        If A[i] = key:
            return (i, comparisons)   // found

    return (-1, comparisons)          // not found
```