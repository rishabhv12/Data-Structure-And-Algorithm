#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
        // Store adjacency list
        unordered_map<int, vector<int>> adjList;

        void addEdge(int u, int v, bool direction){
            adjList[u].push_back(v);

            // If it is undirectional graph (direction -> 0 means undirectional, 1 means directional )
            if(direction == 0){
                adjList[v].push_back(u);
            }
        }

        void printList(){

            for(auto i:adjList){
                cout<<i.first<<" -> ";

                for(auto j:i.second){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }

        // Store adjacency matrix
        vector<vector<int>> adjMatrix;

        void createAdjMatrix(int nodes, int u, int v, bool direction){
            // Initialize the adjacency matrix with zeros
            adjMatrix.resize(nodes, vector<int>(nodes, 0));

            adjMatrix[u][v] = 1;
            if(direction == 0){
                adjMatrix[v][u] = 1;
            }
        }

        void printMatrix(){
            for(auto i:adjMatrix){
                for(auto j:i){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
};

int main(){
    // Node -> number of nodes in graph
    // Edges -> number of edges in graph
    int node , edges;
    cin>>node>>edges;

    Graph g;

    // input connection b/w nodes
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;

        g.addEdge(u,v,0);
        g.createAdjMatrix(node,u,v,0);
    }

    g.printList();
    cout<<endl;
    g.printMatrix();
    return 0;
}


// Input ->
// 5
// 6
// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 0 4


// Output ->
// Adjacency List
// 4 -> 3 0 
// 3 -> 2 1 4 
// 2 -> 1 3 
// 1 -> 0 2 3 
// 0 -> 1 4 

// Adacency Matrix
// 0 1 0 0 1 
// 1 0 1 1 0 
// 0 1 0 1 0 
// 0 1 1 0 1 
// 1 0 0 1 0