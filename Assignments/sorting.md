# Activity 3: Sorting Algorithms
----------------------------------

## Tasks
1. Use Big O Notation to describe the time complexity of an algorithm that takes 4N + 16 steps. (1 pt)
> The time complexity would be O(N) because when considering time complexity in Big O Notation, you ignore constant multipliers (coefficients) as well as constant adders. In this case we would ignore the +16 and the *4 on the N.
2. Use Big O Notation to describe the time complexity of an algorithm that takes 2N^2. (1 pt)
> The time complexity would be O(N) because when considering time complexity in Big O Notation, you ignore constant multipliers (coefficients). In this case we would ignore the 2 being multiplied to N^2.
3. Use Big O Notation to describe the time complexity of the following function, which returns the sum of all numbers of an array after the numbers have been doubled: (2 pts)

```
def double_then_sum(array) 
	doubled_array = []

	array.each do |number| 
		doubled_array << number *= 2
	end

	sum = 0

	doubled_array.each do |number| 
		sum += number
	end
	return sum 
end
```

> The time complexity would be O(N) because on the first loop, array.each, it passes through the elements once, meaning that loop would be O(N). Inside is just a simple operation (multiply + append) → constant time. The second loop, doubled_array.each also passes through the elements once, just adding each element to create a total sum...again this would be O(N). So combining the times it would give us O(N) + O(N) = O(2N), and you ignore the coefficient so it would result in O(N).

4. Use Big O Notation to describe the time complexity of the following function, which accepts an array of strings and prints each string in multiple cases: (2 pts)

```
def multiple_cases(array) 
	array.each do |string|
		puts string.upcase 
		puts string.downcase 
		puts string.capitalize
	end 
end
```
> The time complexity would be O(N). Let N be be the number of strings in the array, the function iterates through each string and within each sstring it does 3 operations. However, these operations are each constant time, so per iteration = O(1). Since each iteration does constant work, the constants are ignored and we are left with O(N). 
O(3N) → O(N)

5. The next function iterates over an array of numbers, and for each number whose index is even, it prints the sum of that number plus every number in the array. What is this function’s efficiency in terms of Big O Notation? (4 pts)
```
def every_other(array) 
	array.each_with_index do |number, index|
		if index.even?
			array.each do |other_number|
            	puts number + other_number
			end 
		end
	end 
end
```
> The time complexity would be O(N^2). The biggest tell-tale that the time is N^2 is that there is a nested loop, or a loop within a loop. In this code, the outer loop iterates through every element once, so that would be O(N). The condition then states to check only the even indices, that statement alone is a constant time or a simple check, O(1). But in Big O, the constant would be ignored. This condition means that the inner loop would only run through or check 1/2 of the elements, so N/2. But in Big O, the 1/2 coefficient on the N would be ignored. Since the loops are nested, we multiple the time complexities together instead of add, so N/2 * N would be N^2/2 and we would ignore the coefficient of 1/2...so the final time would be O(N^2)
<br>
<br>

## Video Submission: [Video](https://youtu.be/-8Pyem_m4h8)