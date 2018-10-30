#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

//make this bigger as possible if you work for graphs that have more than 1000000000 node
//TODO change according to the maximum number of nodes
#define infinite 1000000000

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

int time;

//This works
void DFS_AP(bool **adj, int *disc, int *low, bool *visited, int *parent, bool *AP, int vertex, int V) {

    int i;
    visited[vertex] = true;
    time = disc[vertex] = low[vertex] = time + 1;
    int child = 0;
    for (i = 0;i<V;i++){
        if (adj[vertex][i] == true) {
            if (visited[i] == false) {
                child = child + 1;
                parent[i] = vertex;
                DFS_AP(adj, disc, low, visited, parent, AP, i, V);
                low[vertex] = min(low[vertex], low[i]);
                //Check if the root is an Articulation point or not
                if (parent[vertex] == -1 && child > 1)
                    AP[vertex] = true;
                //Check if the other nodes are Articulation points or not
                if (parent[vertex] != -1 && low[i] >= disc[vertex]&&low[i]!=infinite)
                    AP[vertex] = true;
            }
            else if (parent[vertex] != i)
                low[vertex] = min(low[vertex], disc[i]);
        }
    }

}

int main() {
    time=0;
    bool **adj;
    int *disc,*low,*parent;
    bool *visited,*AP;
    int NodesNumber,i;

    //Number of nodes in the Graph
    //TODO Change the value to what suits your example
    NodesNumber=6;

    adj = malloc(NodesNumber* sizeof(bool*));
    for(i=0;i<NodesNumber;i++) {
        adj[i]= malloc(NodesNumber* sizeof(bool));
    }

    //Content of adjacency matrix
    //TODO Change the value to what suits your example
    adj[0][0]=false; adj[0][1]=true; adj[0][2]=false; adj[0][3]=false; adj[0][4]=false; adj[0][5]=true;
    adj[1][0]=true; adj[1][1]=false; adj[1][2]=true; adj[1][3]=true; adj[1][4]=false; adj[1][5]=false;
    adj[2][0]=false; adj[2][1]=true; adj[2][2]=true; adj[2][3]=true; adj[2][4]=true; adj[2][5]=false;
    adj[3][0]=false; adj[3][1]=true; adj[3][2]=true; adj[3][3]=false; adj[3][4]=true; adj[3][5]=false;
    adj[4][0]=false; adj[4][1]=false; adj[4][2]=true; adj[4][3]=true; adj[4][4]=false; adj[4][5]=false;
    adj[5][0]=true; adj[5][1]=false; adj[5][2]=false; adj[5][3]=false; adj[5][4]=false; adj[5][5]=false;


    disc = malloc(NodesNumber*sizeof(int));
    low = malloc(NodesNumber*sizeof(int));
    parent= malloc(NodesNumber*sizeof(int));
    AP = malloc(NodesNumber*sizeof(bool));
    visited = malloc(NodesNumber*sizeof(bool));

    for(i=0;i<NodesNumber;i++) {
        disc[i]=-1;
        low[i]=infinite;
        parent[i]=-1;
        AP[i]=false;
        visited[i]=false;

    }

    DFS_AP(adj,disc,low,visited,parent,AP,0,NodesNumber);

    for(i=0;i<NodesNumber;i++)
    {
        if(AP[i]) printf("%d is an Articulation Point.\n",i);
    }
    return 0;
}