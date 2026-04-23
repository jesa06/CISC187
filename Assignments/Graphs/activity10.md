# Activity 10: Graphs
> Implement Breadth-first search and Depth-first search algorithms in C++

----------------------------------

##  Tasks
1. Create a theoretical graph using a pen and paper OR electronically. **(2 points)**
<p align="center">
  <img src="https://github.com/jesa06/CISC187/blob/main/Images/BJJposgraph.png" width="400">
</p>
<p align="center"><em>Dominant Top Positions in Jiu-Jitsu</em></p>
<br><br>

<br>

2. Implement the graph created in step 1 and apply breadth and depth-first search algorithms using C++. **(6 points)**
```cpp
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <stack>
    using namespace std;

    // BFS function
    void BFS(vector<vector<int>>& graph, int start) {
        vector<bool> visited(graph.size(), false); // discovered set
        queue<int> q; // frontier queue

        // Step 1: enqueue start and mark visited
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        // Step 2: loop while queue not empty
        while (!q.empty()) {
            int current = q.front(); // dequeue
            q.pop();

            cout << current << " "; // visit

            // check all adjacent vertices
            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // mark discovered
                    q.push(neighbor);         // enqueue
                }
            }
        }
        cout << endl;
    }


    void DFS(vector<vector<int>>& graph, int start) {
        vector<bool> visited(graph.size(), false);
        stack<int> s;

        s.push(start);

        cout << "DFS Traversal: ";

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;

                for (int neighbor : graph[current]) {
                    s.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    int main() {
        // Graph based on your BJJ positions
        // 0 = Kesa-gatame
        // 1 = Mount
        // 2 = Side Control
        // 3 = North-South
        // 4 = Back

        // adjacency list
        vector<vector<int>> graph = {
            {1, 3},        // Kesa-gatame
            {0, 2, 4},     // Mount
            {1, 3, 4},     // Side Control
            {0, 2},        // North-South
            {1, 2}         // Back
        };

        int start = 1; // Start at Mount

        BFS(graph, start);
        DFS(graph, start);

        return 0;
    }
```

3. Compare both search algorithms in the context of Big O notations. **(2 points)**
> Both Breadth-First Search (BFS) and Depth-First Search (DFS) have the same time complexity when traversing a graph. In Big O notation, both run in O(V + E), where V is the number of vertices and E is the number of edges. This means they are equally efficient in terms of time for a full graph traversal. The main difference is not time complexity, but space complexity—BFS uses O(V) space due to the queue, while DFS typically uses less memory, about O(V) in the worst case but often O(h) depending on recursion depth...so BFS generally uses more memory than DFS.