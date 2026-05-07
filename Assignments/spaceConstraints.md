# Activity 13: Space Constraints
> How to write a space-efficient code! *Space complexity* - how much memory an algorithm consumes 

----------------------------------

##  Tasks
1. Following is the 'Word Builder' algorithm. Describe its space complexity in terms of Big O.
``` cpp
function wordBuilder(array) { 
		let collection = [];
		for(let i = 0; i < array.length; i++) { 
				for(let j = 0; j < array.length; j++) {
						if (i !== j) {
								collection.push(array[i] + array[j]);
						}
				}
		}
		return collection; 
}
```
* The space complexity of the "Word Builder" algorithm is O(N^2). This is because there is a nested loop, outer loop runs N times and inner loop runs N times...if the two indices are different, then they are concatenated and the "word" is added to collection. So there are N cases where i==j, and the total comparisons are n*n = n^2, so n^2 - n is still O(N^2). The statement "let collection = []" is constant, O(1), so it is ignored in the overall Big O. 

<br>

2. Following is a function that reverses an array. Describe its space complexity in terms of Big O:
```cpp
function reverse(array) { 
		let newArray = [];
		for (let i = array.length - 1; i >= 0; i--) { 
				newArray.push(array[i]);
		}
		return newArray;
}
```
* The space complexity of this function is O(N). This is because all this function does is first creates a new array which is O(1), and then it uses a loop to put in an element of the original array (starting from the end of the array) into the new array. So overall, there is a new array created with the same amount of N elements. Since the new array ultimately stores N elements, the total additional space used grows linearly with the input size, resulting in O(N) space complexity.

<br>

3. Create a new function to reverse an array that takes up just O(1) extra space.
```cpp
function reverse(array) {
    let left = 0;
    let right = array.length - 1;

    while (left < right ) {
        let temp = array[left];

        array[left] = array[right];
        array[right] = temp;

        right -= 1;
        left +=1;
    }
    return array;
}
```
* This is O(1) space because the amount of extra memory it uses does not grow with the input size. No matter how big the array is, you still only use variables: left, right, and temp. That’s 3 variables total, and that number never changes.

<br>

4. Following are three different implementations of a function that accepts an array of numbers and returns an array containing those numbers multiplied by 2. For example, if the input is [5, 4, 3, 2, 1], the output will be [10, 8, 6, 4, 2].

```cpp
function doubleArray1(array) { 
	let newArray = []; // constant O(1)

	for(let i = 0; i < array.length; i++) { // go through N items
		newArray.push(array[i] * 2); // put item *2, in new array, O(N)
	}
	return newArray; 
}


function doubleArray2(array) {
	for(let i = 0; i < array.length; i++) { // go through N items
  	    array[i] *= 2; // constant function
    }
	return array; 
}


function doubleArray3(array, index=0) { 
	if (index >= array.length) {  // constant comparison
        return; 
    }
    array[index] *= 2;  // constant 
    doubleArray3(array, index + 1); // recursion for the next index, call stack
	    return array; 
}
```

<br>

Fill in the table that follows to describe the efficiency of these three versions in terms of both time and space:

| Version | Time complexity | Space complexity |
|-|-|-|
| Version #1 | O(N) | O(N) |
| Version #2 | O(N) | O(1) |
| Version #3 | O(N) | O(N) |