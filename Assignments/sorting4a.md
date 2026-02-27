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

2. At the start of the insertion sort, the index of the inspected value is set to 1. Change the index of the inspected value and verify that the total number of operations equals 20. Consider the worst-case scenario. Use N=5, where N is the number of elements. **4 pts**
	>  To make the total number of operations equal 20 in the worst case for insertion sort with N = 5, you need to start the inspected index at 0. 
	```
	for (let i = 0; i < N; i++)
	```

	> In the worst-case scenario with N = 5, the number of comparisons become 10 and the number of shifts become 10...so there would be 20 total operations.

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