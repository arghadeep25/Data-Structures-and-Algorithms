# Graph

A Graph is a non-linear data structure consisting of vertices and edges. The vertices are sometimes also referred to as nodes and the edges are lines or arcs that connect any two nodes in the graph. More formally a Graph is composed of a set of vertices( V ) and a set of edges( E ). The graph is denoted by G(V, E).

## Types of Graph
- Directed Graph
- Undirected Graph

## Representation
- ### Adjacency Matrix Undirected Graph

  An adjacency matrix is a way of representing a graph as a matrix of boolean (0’s and 1’s).
  Let’s assume there are n vertices in the graph So, create a 2D matrix Mat[n][n] having dimension n x n.
   - If there is an edge from vertex i to j, mark Mat[i][j] as 1.
   - If there is no edge from vertex i to j, mark Mat[i][j] as 0.
     <p align="center">
      <img src="https://github.com/arghadeep25/Data-Structures-and-Algorithms/blob/master/resources/undirected_graph_am.png" width="360">
     </p>

- ### Adjacency List
  


