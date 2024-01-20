#include<bits/stdc++.h>
using namespace std;

// Time and space complexity - O(N + E)
void adjList(vector<pair<int,int>>& edge, unordered_map<int, vector<int>>& adjlist){
    for(auto i : edge){
        int u = i.first;
        int v = i.second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

void dfs(unordered_map<int, vector<int>> &adjlist, unordered_map<int, bool> &visited, int node, vector<int>& component){
    component.push_back(node);
    visited[node] = true;

    for(auto i : adjlist[node]){
        if(!visited[i]){
            dfs(adjlist, visited, i, component);
        }
    }
}

int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    vector<pair<int,int>> edge;

    for(int i = 0; i < edges; i++){
        int u, v; 
        cin >> u >> v;

        edge.push_back({u, v});
    }

    unordered_map<int, vector<int>> adjlist;
    adjList(edge, adjlist);

    // Check if the node is visited or not 
    unordered_map<int, bool> visited;

    vector<vector<int>> ans;
    // Using a loop to handle disjoint components graph
    for(int i = 0; i < nodes; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(adjlist, visited, i, component);
            ans.push_back(component);
        }
    }

    // Output the connected components
    for(auto i : ans){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
