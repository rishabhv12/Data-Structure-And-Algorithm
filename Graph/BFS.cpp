#include<bits/stdc++.h>
using namespace std;

// Time and space complexity - O(N + E)
void adjList(vector<pair<int,int>>& edge, unordered_map<int, vector<int>>& adjlist){

    for(auto i:edge){
        int u = i.first;
        int v = i.second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    
}


void bfs(unordered_map<int,vector<int>> &adjlist, unordered_map<int,bool> &visited, int node){
    queue<int> curr;

    curr.push(node);
    visited[node] = 1;

    while(!curr.empty()){
        int frontNode = curr.front();
        curr.pop();

        // Print current node
        cout<<frontNode<<" ";

        // Traverse all neighbours of frontNode
        for(auto i:adjlist[frontNode]){
            if(!visited[i]){
                curr.push(i);
                visited[i] = 1;
            }
        }
    }
}


int main(){
    int node, edges;
    cin>>node>>edges;

    vector<pair<int,int>> edge;

    for(int i=0;i<edges;i++){
        int u,v; 
        cin>>u>>v;

        edge.push_back({u,v});
    }


    unordered_map<int, vector<int>> adjlist;
    adjList(edge, adjlist);

    // Check if node is visited or not 
    unordered_map<int,bool> visited;

    // Using loop to handle disjoint components graph
    for(int i=0;i<node;i++){
        if(!visited[i]){
            bfs(adjlist, visited, i);
        }
    }
    return 0;
}