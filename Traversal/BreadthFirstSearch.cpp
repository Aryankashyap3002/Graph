#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include <limits.h>
#include<unordered_set>

using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;
int v;

void add_edges(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }
}

void bfs(int src, int end, vector<int> &dist) {
    queue<int> qu;
    visited.clear();
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    qu.push(src);
    while(!qu.empty()) {
        int curr = qu.front();
        qu.pop();
        for(auto neighbour : graph[curr]) {
            if(!visited.count(neighbour)) {
                qu.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
            
        }
    }
}

int main() {
    cin >> v;
    graph.resize(v);  // Resize graph to hold v vertices
    int e;
    cin >> e;
    while(e--) {
        int s, d;
        cin >> s >> d;
        add_edges(s, d);
    }

    int x, y;
    cin >> x >> y;
    vector<int> dist;
    bfs(x,y, dist);

    for(int i = 0; i < dist.size(); i++) {
        if(dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout<<endl;

    return 0;

}