#include<iostream>
#include<vector>
#include<list>
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

void dfs(int curr, int end, vector<int>& path) {
    if(curr == end) {
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    } 
    visited.insert(curr);
    path.push_back(curr);

    for(auto neighbour : graph[curr]) {
        if(!visited.count(neighbour)) {
            dfs(neighbour, end, path);
        }
    }

    path.pop_back();
    visited.erase(curr);
}

void anyPath(int start, int end) {
    visited.clear();
    vector<int> path;
    dfs(start, end, path);
}

int main() {
    cin >> v;
    graph.resize(v);  // Resize graph before using it

    int e;
    cin >> e;
    while(e--) {
        int s, d;
        cin >> s >> d;
        add_edges(s, d);
    }

    int x, y;
    cin >> x >> y;
    anyPath(x, y);

    // Display all paths found
    for(const auto& path : result) {
        for(int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
