# Activity 11: Graphs
> Understanding Dijkstra's algorithm

----------------------------------

##  Tasks
1. Explain with the help of an example "Why Dijkstra's algorithm fails on negative weights".
> Dijkstra's algorithm fails on negative weights because the algorithm is intended to find the shortest path in a graph. Its core assumption breaks: it assumes that once a node has the “shortest” distance, it can never be improved later. A shortest path does not exist in a graph that has negative edge weight cycles, because each loop around the negative edge weight cycle further decreases the cycle length, so no minimum exists. **Remember,** once a node is marked “finalized” (its shortest distance is chosen), that distance will never improve later. That assumption is only true when **all edge weights are non-negative**. A negative edge can later *“undo”* a previously chosen best distance.

<p align="center">
  <img src="https://github.com/jesa06/CISC187/blob/main/Images/dijkstraFail.png" width="600">
</p>
<p align="center"><em>Dominant Top Positions in Jiu-Jitsu</em></p>
<br><br>

<br>

Dijkstra's path is greedy. The goal is to find the shortest path from A->B. Starting from node A, it compares the weight of the edges to the adjacent nodes, B and C. Since 3 < 5, Dijkstra chooses the edge A->B. However, it misses out on the other path which ends up being shorter than 3. A->C is 5, and C->B is -4. 5-4=1 and 1 < 3. Since there is a negative weight "hidden" down the path that the apparent heavier/costlier first edge lies, it sort of tricks Dijkstra's logic. This is why Dijkstra's algorithm does not work with graphs with negative weights.