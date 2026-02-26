# Activity 4b: Adaptive Sorting Strategy
----------------------------------

## Part A: Adaptive Sorting Selection
* The program analyzes the initial ordering of the array by counting ascending and descending adjacent pairs. If at least 80% of the elements are already in ascending order, the array is considered nearly sorted, and Insertion Sort is used because it runs in O(n) time in this case.

* If at least 80% of the elements are in descending order, the array is considered worst case, and Selection Sort is used because it performs consistently regardless of input order. Otherwise, the array is treated as average case, and Selection Sort is used.

		

<br>
<br>

## Video Submission: [Video]()