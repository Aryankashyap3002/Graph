#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>

using namespace std;

vector<list<int> > graph;
int v; // no. of vertices

void add_edges(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }
}

void dfs(int node, unordered_set<int>& visited) {
    visited.insert(node);
    for(auto neighbor : graph[node]) {
        if(!visited.count(neighbor)){
            dfs(neighbor, visited);
        }
    }
}

int connected_components() {
    int result = 0;
    unordered_set<int> visited;
    for(int i=0; i<v; i++) {
        if(!visited.count(i)) {
            result++;
            dfs(i, visited);
        }
    }

    return result;
}


 
int main() {

    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    while(e--) {
        int s,d;
        cin>>s>>d;
        add_edges(s, d);
    }
    cout<<connected_components()<<endl;

    return 0;
}