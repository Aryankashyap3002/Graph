#include<bits/stdc++.h>

using namespace std;

vector<list<int>> graph;
int v;

void add_edge(int a, int b, bool bi_dir=true){
    graph[a].push_back(b);
    if(bi_dir) {
        graph[b].push_back(a);
    }
}

void topoBFS() {
    vector<int> indegree(v, 0);
    for(int i=0; i<v; i++) {
        for(auto neighbor: graph[i]) {
            indegree[neighbor]++;
        }
    } 
    queue<int> qu;
    unordered_set<int> vis;
    for(int i=0; i<v; i++) {
        if(indegree[i] == 0) {
            qu.push(i);
            vis.insert(i);
        }
    }

    while(!qu.empty()) {
        int node = qu.front();
        cout<<node<<" ";
        qu.pop();
        for(auto neighbor : graph[node]) {
            if(!vis.count(neighbor)) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    qu.push(neighbor);
                    vis.insert(neighbor);
                }
            }
        }
    }
}

int main() {
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v, list<int>());
    while(e--) {
        int x,y;
        cin>>x>>y;
        add_edge(x, y, false);
    }

    topoBFS(); 
    cout<<endl;
    return 0;
}