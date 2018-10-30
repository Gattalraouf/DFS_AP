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
