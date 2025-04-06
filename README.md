
//itamarbabai98@gmail.com
# Assignment 1 - System Programming 2 - Algorithm implementation with CPP 
## General Explanation
---
* **Compiler:** g++

* **Run Example:**
```bash
make
./main
```

* **Tests run example:**
```bash
make run_tests
```
* **Project stracture:**
```bash
├── CCP_files/          
│   ├── main.cpp
│   ├── Algorithms.cpp
│   ├── Edge.cpp
|   ├── Graph.cpp
|   ├── Praiority_Q.cpp
|   ├── Queue.cpp
|   ├── Test_prog.cpp
|   └── Union.cpp
├── HPP_files/        
│   ├── doctest.h
│   ├── Algorithms.hpp
│   ├── Edge.hpp
|   ├── Graph.hpp
|   ├── Praiority_Q.hpp
|   ├── Queue.hpp
|   ├── Test_prog.hpp
|   └── Union.hpp
├── Makefile       
└── README.md        
```

## General Explanation of the Code:
The main goal of this project is to Implement a graph using an adjacency list.
Implement several algorithms in C++.
Use various data structures to support the algorithms.
In this document, we will explain each class separately and how the functions are implemented.
The entire project is under the "graphs" namespace.

### Details:
* **main:**  
  Main showcase of the code functionality.

* **Edge:**  
  Class representing an edge in the graph.

* **Graph:**  
  Class representing a graph using an adjacency list.

* **Priority_Q:**  
  Data structure representing a priority queue.

* **Queue:**  
  Data structure representing a basic queue.

* **Union:**  
  Data structure implementing Union-Find (Disjoint Set Union - DSU).

* **Algorithms:**  
  Class containing all the algorithms required for this assignment:
  (BFS, DFS, Dijkstra, Kruskal, Prim).

* **Test_prog:**  
  Test class that checks all edge cases.

---
### Edge:
- A basic class that contains two integers as members, representing the weight and the neighboring vertex.
- It is used to represent the adjacency list.
### Graph:
- Contains the graph and represents it as an adjacency list.
- The number of vertices is fixed.
-Edges can be added or removed (directed or undirected) using the functions addEdge and removeEdge.
- Contains the print_graph function.
### Data stractures:
- **Queue:**A simple array that contains vertex numbers as integers. A circular method is used with modulo to manage the queue.

- **Praiority_Q:** The praiority_Q class implements a priority queue using a linked list. Each node stores a vertex, its weight, neighboring vertex, and priority key.
Key methods: pra_push - Insert the node to the correct place by the vulue. par_pop - returns the first node (that already in order). is_in - returns true if the edge is in the Queue. 

- **Union:** The UnionFind class implements the Union-Find data structure, which handles the merging of sets and finding the representatives of each set.
Key methods: find() - returns the representative of the set. Union() - union between two sets. 

### Algorithms:
1. ***BFS:*** Finds the shortest (by edges number) path from a given source. Can also say if the graph is connected. BFS explores the graph layer by layer, visiting all vertices at the present depth level before moving on to vertices at the next depth level.

2. ***DFS:*** The main_DFS function initializes necessary arrays (color[], pi[], d[], f[]) for DFS traversal and starts the DFS process from the given source vertex s. It then calls the recursive DFS_visit function for each unvisited vertex, which marks the vertex as "in-progress" (Gray), updates discovery times, and recursively visits unvisited neighbors. After all neighbors are explored, it marks the vertex as "finished" (Black) and records its finishing time. Finally, main_DFS prints discovery, finish times, and parent relationships, and returns a graph built from the DFS traversal.

3. ***Dijkestra:*** The dijkstra function implements Dijkstra's shortest path algorithm. It starts by initializing the distances to all vertices as infinite and sets the parent pointers to -1. The algorithm uses a priority queue to manage vertices, where the smallest distance vertex is processed first. For each vertex, the algorithm checks its neighbors, and if a shorter path is found, it updates the distance and parent pointer. The algorithm continues until all reachable vertices are processed. Finally, the function prints the distance and parent arrays and constructs a graph based on the results, which is returned.

4. ***Kruskal:*** The kruskal function implements Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a graph. It first checks if the graph is connected using BFS. Then, the algorithm sorts all edges by weight using bubble sort. For each edge, it checks if the two vertices are in different sets using the Union-Find structure. If they are, the edge is added to the MST. The function tracks the parent of each vertex and the weight of the edges in the MST, printing the results and constructing a graph representing the MST, which is then returned.

5. ***Prim:*** The prim function implements Prim's algorithm to find the Minimum Spanning Tree (MST) of a graph. It first checks if the graph is connected using BFS. Then, the algorithm initializes an array of keys (distances), a parent array, and a boolean array to track vertices included in the MST. It iteratively selects the vertex with the minimum key value not yet in the MST and updates the keys of its neighbors if the new edge provides a smaller weight. After processing all vertices, the function constructs the MST by adding edges based on the parent array and returns the resulting graph.

### Test_prog: 
In this part of the code we try to test the extream cases that can hapand and may become a problem.
1. Graph test: 
    * Addind an Edge that already exist - runtime exception.
    * Check if "has_edge()" function returns false to edge that being removed.
    * Create graph with (-1) vertex - invalid_argument exception.
    * Create graph with no vertex - invalid_argument exception.
    * Check if "has_edge()" function returns out_of_range exception to (-1,4) edge.
    * Adding Edge with negative vertex - out_of_range exception.
    * Removing Edge that not exist - runtime_error.
    * Try to get_vertex_list()(neigbors list) and insert it to non exist list - invalid_argument exeption.
    * Try to get_vertex_list()(neigbors list) to negative vertex - out_of_range exeption.

1. BFS test:
    * Check if the function returns true on the connected pointer when the graph is connected.
    * Check if after BFS the neigbor list for each vertext its as expacted.
    * Check if the level-by-level method of the BFS workiung well.
    * Check if the BFS detect unconnected graphs.
    * Try to run BFS with vertext out of range - out_of_range exception.

2. Queue test:
    * Check if is_empty() function returns true to an empty queue and false to full.
    * Try to pop a vertex from empty queue - runtime_error exception.
    * Try to push vertex to the Queueu more than capacity - runtime_error excepation.
    * Check if the first element that insterted is the first that popes out.
    * Try to create Queueu with invalid num of elements - invalid_argument exception.

3. DFS test:
    * Try to run a DFS with out of range vertex - out_of_range exception.
    * Check if the number of neigbors after DFS is as expected.
    * Run a DFS on unconnected graph and print the resault.
    * Check if BFS also retuns that the graph is not connected.

4. Dijkestra test:
    * Check if the distance between source vertex to chosen vertex is he minimum as expected, (0-9 , brake down as 0-3 , 3-6 , 6-9)
    * show that there is no directed edge between 0-9
    * Check if dijkestra choose a better option after added one.
    * Run dijestra with negative edge - runtime_error exception.
    * Run dijestra from out of range vertex -  out_of_range.

5. praiority_Q test:
    * Create Queue with negative number of vertex - out_of_range exception.
    * Check if the Queue returnt the minimum edge value that in d[].
    * Check if the update function works correctly.
    * Check that is_empty() function returns true on empty queue.
    * Trying to pop a vertext when the queue is empty - runtime_error exception.    

6. Kruskal test:
    * Try to run kruskal on empty graph - runtime_error exception.
    * Check if the mst gives the minimal Weight.
    * Changing values and check again.
    * Check unconnected graph - runtime_error Exception.

7. Union find test:
    * Check if the connected function returns the correct values.

8. Prim test:
    * Check if the weight for empty graph.
    * Check unconnected graph - runtime_error Exception.
    * Check if the mst gives the minimal Weight.
    * Changing values and check again.


