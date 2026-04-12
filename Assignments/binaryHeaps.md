# Activity 9: Binary Heaps
----------------------------------

## Tasks
1. Draw what the following heap would look like after we insert the value 11 into it:
<p align="center">
  <img src="https://github.com/jesa06/CISC187/blob/main/Images/t1HS.png" width="400">
</p>
<p align="center"><em>Task 1 Heap</em></p>
<br><br>

2. Draw what the previous heap would look like after we delete the root node.
<p align="center">
  <img src="https://github.com/jesa06/CISC187/blob/main/Images/t2HS.png" width="400">
</p>
<p align="center"><em>Task 2 Heap</em></p>
<br><br>

3. Imagine you’ve built a brand-new heap by inserting the following numbers into the heap in this particular order: 55, 22, 34, 10, 2, 99, 68. If you then pop them from the heap one at a time and insert the numbers into a new array, in what order would the numbers now appear?
> If I pop the root nodes from the heap one at a time and insert the numbers into a new array, the numbers would appear in order from maximum to minimum or descending. This is because after inserting the nodes correctly we must trickle them down so that none of its children will be greater than it AND the heap must be complete and balanced. So when we pop the ROOT from the heap, that means the maximum node or element is removed, and then the next maximum, and the next... The final array would look like [99, 68, 55, 34, 22, 10, 2]!

<p align="center">
  <img src="https://github.com/jesa06/CISC187/blob/main/Images/t3HS.png" width="400">
</p>
<p align="center"><em>Task 3 Heap</em></p>
<br><br>
