# Graph

A Graph is a non-linear data structure consisting of vertices and edges. The vertices are sometimes also referred to as nodes and the edges are lines or arcs that connect any two nodes in the graph. More formally a Graph is composed of a set of vertices( V ) and a set of edges( E ). The graph is denoted by G(V, E).

## Types of Graph
- Directed Graph
- Undirected Graph

## Representation
- ### Adjacency Matrix 
  An adjacency matrix is a way of representing a graph as a matrix of boolean (0’s and 1’s).
  Let’s assume there are n vertices in the graph So, create a 2D matrix Mat[n][n] having dimension n x n.
   - If there is an edge from vertex i to j, mark Mat[i][j] as 1.
   - If there is no edge from vertex i to j, mark Mat[i][j] as 0.
     - #### Undirected Graph Adjacency Matrix
     <p align="center">
      <img src="https://github.com/arghadeep25/Data-Structures-and-Algorithms/blob/master/resources/undirected_graph_am.png" width="480">
     </p> 
     
     - #### Directed Graph Adjacency Matrix
     <p align="center">
      <img src="https://github.com/arghadeep25/Data-Structures-and-Algorithms/blob/master/resources/directed_graph_am.png" width="480">
     </p>

- ### Adjacency List
  An array of Lists is used to store edges between two vertices. The size of array is equal to the number of vertices (i.e, n). Each index in this array represents a specific vertex in the graph. The entry at the index i of the array contains a linked list containing the vertices that are adjacent to vertex i.
  
  Let’s assume there are n vertices in the graph So, create an array of list of size n as adjList[n].
  adjList[0] will have all the nodes which are connected (neighbour) to vertex 0.
    - adjList[0] will have all the nodes which are connected (neighbour) to vertex 0.
    - adjList[1] will have all the nodes which are connected (neighbour) to vertex 1 and so on.
        
       - #### Undirected Graph Adjacency List
      <p align="center">
       <img src="https://github.com/arghadeep25/Data-Structures-and-Algorithms/blob/master/resources/undirected_graph_al.png" width="480">
      </p>
      
       - #### Directed Graph Adjacency List
      <p align="center">
       <img src="https://github.com/arghadeep25/Data-Structures-and-Algorithms/blob/master/resources/directed_graph_al.png" width="480">
      </p>