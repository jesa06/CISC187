# Activity 1: Array data structure
----------------------------------

##  Tasks
1. Explain how to create an array of 100 elements.
> To create an array of 100 elements, you would first choose what data type (string, int, double,...) and then choose a name for the array. I chose colors. Then to enter the size, you would put in the number of elements inside of brackets, right after the array name. You could create it empty or initialize all elements, if you wanted to.

```C++
string colors[100] = {"Red", "Purple", "Blue", "Green",...};
int nums[100];
```
   
<br>
2. What will be the size of each element of an array?
> The size of each element in an array depends on the data type of the array.
All elements in an array are the same type, so each element takes the same amount of memory.

* For example:

    * If the array is of type int, each element is typically 4 bytes.

    * If it is double, each element is typically 8 bytes.

    * If it is char, each element is 1 byte.

```C++
int numbers[100];

    cout << "Size of one element: " << sizeof(numbers[0]) << " bytes" << endl;
```
<br>

3. For an array containing 100 elements, provide the number of steps the following operations would take: 
    * Reading: 1 step
        * Direct access with a given index
    * Searching for a value not contained within the array: 100 steps
        * Must go through and check each element 
    * Insertion at the beginning of the array: 101 steps
        * Insert an element then shift the other 100 elements over to the right by one position
    * Insertion at the end of the array: 1 step
        * Just place another element at the end, no shifting needed
    * Deletion at the beginning of the array: 100 steps
        * Delete the first element, shift the remaining 99 elements one position to the left
    * Deletion at the end of the array: 1 step
        * Just remove the last element in the array, no shifting needed 
<br>

4. Normally the search operation in an array looks for the first instance of a given value. But sometimes we may want to look for every instance of a given value. For example, say we want to count how many times the value “apple” is found inside an array. How many steps would it take to find all the “apples”? Give your answer in terms of N. 
> This would take N steps, linear time. Because the program must check every element once to match "apples", it will take N steps. In actual code, you can identify this by looking at the loops being used. Since you would use a single for loop to traverse through the array and search for "apples", the time is linear or O(N).

```c++
string array[5] = {"bananas", "apples", "apples", "oranges", "apples"};

int count = 0;
int length = sizeof(array) / sizeof(array[0]);

for (int i = 0; i < length; ++i) {
    if (array[i] == "apples") {
        count++;
    }
}

cout << "Number of 'apples': " << count << endl;

```

<br>

5. Research how to find the memory address of an array. You can use any programming language of your choice. 
> You can find the address of **any element** in the array by using the address-of operator (&) or by using pointer arithmetic with the array name. 

    * Because array elements are stored in contiguous memory locations, the addresses are sequential. 
        The address of arr[i] can be calculated with the formula:

        * Address of arr[i] = Base Address + (Index * Size of each element) 
> You can find the starting address or the **base address** in the array by just printing the array name or with the pointer and index 0.

    * The output will be in hexadecimal format!
```C++
int array[5] = {1, 3, 5, 7, 9};
cout << "Memory address of element 4 is: " << &array[3] << endl; // & operator
cout << "Memory address of element 4 is: " << array + 3 << endl; // pointer arithmetic

cout << "Base address is: " << array << endl; 
cout << "Base address is:" << &array[0] << endl;
```
