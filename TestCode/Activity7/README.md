# Explanation of stack implementation
-----------------------------------------
## 1. Why is a linked list efficient for stack implementation?
> A linked list is efficient for stack implementation because push and pop operations only involve updating pointers at the top node. Additionally, linked lists are dynamic in size and do not require shifting elements, making them more flexible than arrays.

## 2. What is the time complexity of push and pop operations?
> The time complexity of push and pop operations is constant time, O(1). This is because, no matter the number of elements, you only work with the top node. This means the time complexity is **NOT** O(N)...you never traverse the list or search. You just access the top node and either remove it or add another one as the top. 

## 3. What happens if memory is not deallocated after pop?
> If memory is not deallocated, the node that was removed still occupies memory but is no longer accessible through the stack (because no node points to it). This causes a memory leak, which over time can waste system memory and may eventually crash the program if many nodes are popped without deleting them.

## 4. Compare a stack implemented with an array versus a linked list.
> Arrays are simple and cache-friendly but have a fixed size and may need costly resizing, whereas linked lists allow a stack to grow dynamically with constant-time push and pop operations, but require extra memory for node pointers.
| Functions | Array | Linked List | 
| - | - | - |
| Memory | Fixed size, Can waste memory if array is larger than needed | Dynamic size, No wasted unused space |
| Operation Efficiency | Push can be O(1) if space allows, Must resize if need more space | push() and pop() are always O(1) |
| Ease of use | Simple to implement, access by index | More complex to implement, Extra memory per node for pointer |