# Activity 6: Stacks and Queues 
----------------------------------

##  Tasks
1. Using Figure 17 as a model, in the book Data Structures in C++, illustrate the result of each operation in the sequence PUSH(S,4), PUSH(S,1), PUSH(S,3), POP(S), PUSH(S,8), and POP(S) on an initially empty stack S stored in array S[1..6]. **Code is not required. 3 pts**
<p align="center">
  <img src="https://github.com/jesa06/CISC187/blob/main/Images/stacks.png" width="400">
</p>
<p align="center"><em>Stack Example</em></p>
<br>

2. Using Figure 18 as a model, in the book Data Structures in C++, illustrate the result of each operation in the sequence ENQUEUE(Q,4), ENQUEUE(Q,1), ENQUEUE(Q,3), DEQUEUE(Q), ENQUEUE(Q,8), and DEQUEUE(Q) on an initially empty queue Q stored in array Q[1..6]. **Code is not required. 3 pts**
<p align="center">
  <img src="https://github.com/jesa06/CISC187/blob/main/Images/queue.png" width="600">
</p>
<p align="center"><em>Queue Example</em></p>
<br>

3. Rewrite ENQUEUE and DEQUEUE to detect **underflow** and **overflow** of a queue. (see Listings 4 & 5 in the book). **Code is not required. 1 pt**

*Listing 4 Pseudocode of ENQUEUE(Q,x)*
```
if ((Q.head == Q.tail + 1) || ((Q.head == 1) && (Q.tail == Q.length))) // Full queue 
    error "overflow"
else 
  Q[Q.tail] = x
  if Q.tail == Q.length
    Q.tail = 1
  else 
    Q.tail = Q.tail + 1
```
*Listing 5 Pseudocode of DEQUEUE(Q)*
```
if (Q.head == Q.tail) // Empty queue
    error "underflow"
else
  x = Q[Q.head]
  if Q.head == Q.length
    Q.head = 1
  else 
    Q.head = Q.head + 1
  return x
```
4. A **stack** allows insertion and deletion of elements at only end, and a queue allows insertion at one end and deletion at the other end, a **deque** (double-ended queue) allows insertion and deletion at both ends. Write four O(1)-time procedures to insert elements into and delete elements from both ends of a deque implemented by an array. **Code is not required. 3 pts**

*Insert at START of Deque*
```
if ((D.head == D.tail + 1) || ((D.head == 1) && (D.tail == D.length))) //if deque is full
    error "overflow"
else if deque is empty
    D.head = 1
    D.tail = 1
else if D.head == 1
    D.head = D.length
else
    D.head = D.head - 1

D[D.head] = x
```

*Insert at END of Deque*
```
if ((D.head == D.tail + 1) || ((D.head == 1) && (D.tail == D.length))) //if deque is full
    error "overflow"
else if deque is empty
    D.head = 1
    D.tail = 1
else if D.tail == D.length
    D.tail = 1
else
    D.tail = D.tail + 1 //make tail one more over

D[D.tail] = x
```

*Delete START of Deque*
```
if (D.head == D.tail) // Empty queue
    error "underflow"
else    
    x = D[D.head]
    if D.head == D.length
        D.head = 1
    else
        D.head = D.head + 1
    return x
```

*Delete END of Deque*
```
if (D.head == D.tail) // Empty queue
    error "underflow"
else
    x = D[D.tail]
    if D.tail == 1
        D.tail = D.length
    else
        D.tail = D.tail - 1
    return x
```
