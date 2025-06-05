#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>

using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }
}

bool dfs(int curr, int end) {
    if(curr == end) return true;  // base case
    visited.insert(curr);

    for(auto neighbour : graph[curr]) {
        if(!visited.count(neighbour)) {
            if(dfs(neighbour, end)) return true;
        }
    }

    return false;
}

bool anyPath(int start, int end) {
    visited.clear();  // Clear before each new search
    return dfs(start, end);
}

int main() {
    cin >> v;
    graph.resize(v);  // Resize graph to hold v vertices
    int e;
    cin >> e;
    while(e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }

    int x, y;
    cin >> x >> y;
    cout << anyPath(x, y) << endl;

    return 0;
}
