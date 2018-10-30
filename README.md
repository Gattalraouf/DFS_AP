# DFS_AP
Detecting Articulation points in Graphs Algorithm

# Articulation Point

In a graph, a vertex is called an articulation point if removing it and all the edges associated with it results in the increase of the number of connected components in the graph.


Articulation Points represents vulnerabilities in a network. In order to find all the articulation points in a given graph, the brute force approach is to check for every vertex if it is an articulation point or not, by removing it and then counting the number of connected components in the graph. If the number of components increases then the vertex under consideration is an articulation point otherwise not. 
Clearly the brute force approach will fail for bigger graphs.



There is an algorithm that can help find all the articulation points in a given graph by a single Depth First Search, that means with complexity
, but it involves a new term called "Back Edge" which is an edge that connects a vertex to a vertex that is discovered before it's parent.

Presence of a back edge means presence of an alternative path in case the parent of the vertex is removed. 


Suppose a vertex "u" is having a child "v" such that none of the vertices in the subtree rooted at "v" have a back edge to any vertex 
discovered before "u" , that means if vertex "v" is removed then there will be no path left for vertex "v" or any of the vertices present in the subtree rooted at vertex "v" to reach any vertex discovered before "u", that implies, the subtree rooted at vertex "v" will get disconnected from the entire graph, and thus the number of components will increase and "u" will be counted as an articulation point. On the other hand, if the subtree rooted at vertex "v" has a vertex "x" that has back edge that connects it to a vertex discovered before "u", say "y", then there will be a path for any vertex in subtree rooted at "v" to reach "y" even after removal of "u", and 
if that is the case with all the children of "u", then "u" 
will not count as an articulation point.

So ultimately it all converges down to finding a back edge for every vertex. 
So, for that apply a DFS and record the discovery time of every vertex and 
maintain for every vertex "v"
the earliest discovered vertex that can be reached from any of the vertices in 
the subtree rooted at "v". If a vertex "u"is having a child such that the 
earliest discovered vertex that can be reached from the vertices in 
the subtree rooted at "v" has a discovery time greater than or equal to "u", 
then "v" does not have a back edge, and thus"u"
will be an articulation point.

So, till now the algorithm says that if all children of a vertex "u"
are having a back edge, then "u" is not an articulation point. 
But what will happen when "u" is root of the tree, as root does not have 
any ancestors. Well, it is very easy to check if the root is an articulation 
point or not. If root has more than one child than it is an articulation 
point otherwise it is not. Now how does that help?? 
Suppose root has two children, "v1" and "v2". If there had been an edge 
between vertices in the subtree rooted at "v1" and those of the subtree rooted 
at "v2", then they would have been a part of the same subtree. 


Here's what everything means:


adj[][]: It is an N*N matrix denoting the adjacency matrix of the given graph.

disc[][]: It is an array of N elements which stores the discovery time of every vertex. It is initialized by 0.

low[]: It is an array of N elements which stores, for every vertex "v", the discovery time of the earliest discovered vertex to which "v" or any of the vertices in the subtree rooted at "v" is having a back edge. It is initialized by INFINITY.


visited[]: It is an array of size N which denotes whether a vertex is visited or not during the DFS. It is initialized by false.


parent[]: It is an array of size N which stores the parent of each vertex. It is initialized by NIL.

 AP[]: It is an array of size N. AP[i]=true, if the ith vertex is an articulation point.


 vertex: It is an array of size . = true, if ith vertex is an articulation point.


 time: Current value of discovery time.



The above program (which resolves the issue of finding the Articulation points in a way faster time and better complexity than the brute force aproach), starts with an initial vertex say "u", marks it visited, record its discovery time disc[u], , and since it is just discovered, the earliest vertex it is connected to is itself, so low[u] is also set equal to vertex's discovery time. 


 It keeps a counter called "child" to count the number of children of a vertex. Then the algorithm iterates over every vertex in the graph and see if it is connected to "u", if it finds a vertex "v" that is connected to "u", but has already been visited, then it updates the value low[u] to minimum of low[u] and discovery time of "v"i.e. disc[v], .But if the vertex "v" is not yet visited, then it sets the parent[v] to "u" and calls the DFS again with "vertex=v". So the same things that just happened with "u" will happen for "v" also. When that DFS call will return, low[v] will have the discovery time of the earliest discovered vertex that can be reached from any vertex in the subtree rooted at "v". So set low[u] to minimum of low[v] and itself. And finally if "u" is not the root, it checks whether low[u] is greater than or equal to disc[u] , and if so, it marks AP[u] as true. And if "u" is root it checks whether it has more than one child or not, and if so, it marks AP[u] as true.
