# Activity 4a: Sorting Algorithms, Insertion Sort
----------------------------------

## Tasks
1. Proof that, under the average-case scenario, the insertion sort has a time complexity of O(N^2). Draw a clear figure and show all the operations clearly. **2 pts**
<p align="center">
  <img src="https://raw.githubusercontent.com/jesa06/CISC187/e607041f29ddd11c4f9384b1fa490312905ed84b/Images/insertion.png" width="400">
</p>
<p align="center"><em>Insertion Sort Example</em></p>
<br>

> I found that this randomized array ended up being around 12 operations, which is not super close to N^2, 25. I think this case just ended up being closer to a "best-case" as it is close to 2N or 2*5 operations. However, you can see that through each pass, the number of operations grow...so as N gets bigger, the work increases very fast. You can say that the total operations grow quadratically. 


2. Insertion sort normally begins with i = 1 (0-based indexing). Let N = 5 and assume the array is in descending order (worst case).
	* Count operations where:
		* a comparison is A[j] > key
		* a shift is A[j+1] = A[j]
<p align="center">
  <img src="https://github.com/jesa06/CISC187/blob/main/Images/task2.png" width="400">
</p>
<p align="center"><em>Insertion Sort At Indices 2 and 3</em></p>
<br>
a. Start the algorithm at i = 1. Verify the total operations = 20.
> It is 20, 10 comparisons and 10 swaps. 
b. Start the algorithm at i = 2, then i = 3. Count operations again.
> Operations for starting at i = 2, 18 operations. 9 comparisons and 9 shifts. 
> Operations for starting at i = 3, 14 operations. 7 comparisons and 7 shifts.
c. For (b), does the algorithm still sort the entire array? Explain.
> The algorithm does not sort the entire array because in insertion sort, it assumes that the left side of the array (after the chosen starting index) is already sorted. If you start at i = 2, the array will end up with {1, 2, 3, 5, 4}. If you start at i = 3, the array will end up with {1, 2, 5, 4, 3}. Simply, the sort ends once the it reaches the end of the array.
**4 pts**

3. The following function returns whether or not a capital “X” is present within a string. **4 pt**

```
function containsX(string) {
	foundX = false;
	for(let i = 0; i < string.length; i++) { 
		if (string[i] === "X") {
			foundX = true; 
		}
	}
	return foundX; 
}
```

* What is this function’s time complexity regarding Big O Notation?
	> The functions time complexity is O(N) because it always traverses through the entire string of length, N. In all cases: best, worst, and average scenario, where there is no "X", every character will be examined.
* Then, modify the code to improve the algorithm’s efficiency for best- and average-case scenarios.
	> To improve on this code I would put an earlier return statement to terminate the program once the capital "X" is found, so that we do not have to keep searching once we find it. 

```
function containsX(string) {
	foundX = false;
	for(let i = 0; i < string.length; i++) { 
		if (string[i] === "X") {
			foundX = true; 
			return foundX;
		}
	}
	return foundX; 
}
```
		

<br>
<br>

## Video Submission: [Video]()