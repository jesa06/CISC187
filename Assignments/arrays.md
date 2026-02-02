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
2. What will be the size of each element of an array.
>

<br>

3. For an array containing 100 elements, provide the number of steps the following operations would take: 
* Reading
* Searching for a value not contained within the array
* Insertion at the beginning of the array
* Insertion at the end of the array
* Deletion at the beginning of the array
* Deletion at the end of the array
<br>

4. Normally the search operation in an array looks for the first instance of a given value. But sometimes we may want to look for every instance of a given value. For example, say we want to count how many times the value “apple” is found inside an array. How many steps would it take to find all the “apples”? Give your answer in terms of N. 

<br>

5. Research how to find the memory address of an array. You can use any programming language of your choice. 
> You can find the address of **any element** in the array by using the address-of operator (&) or by using pointer arithmetic with the array name. 

    * Because array elements are stored in contiguous memory locations, the addresses are sequential. The address of arr[i] can be calculated with the formula:

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
