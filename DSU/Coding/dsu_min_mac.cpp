#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find(vector<int> &parent, int x) {
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

void Union(vector<int> &parent, vector<int> &rank, vector<int> &sz, vector<int> &minimal, vector<int> &maximal, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a == b) return; // already in same set

    if (rank[a] >= rank[b]) {
        parent[b] = a;
        sz[a] += sz[b];
        minimal[a] = min(minimal[a], minimal[b]);
        maximal[a] = max(maximal[a], maximal[b]);
        if (rank[a] == rank[b]) rank[a]++;
    } else {
        parent[a] = b;
        sz[b] += sz[a];
        minimal[b] = min(minimal[a], minimal[b]);
        maximal[b] = max(maximal[a], maximal[b]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> rank(n + 1, 0);
    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1); // initialize size to 1
    vector<int> minimal(n + 1);
    vector<int> maximal(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        minimal[i] = maximal[i] = i;
    }

    while (m--) {
        string str;
        cin >> str;
        if (str == "union") {
            int x, y;
            cin >> x >> y;
            Union(parent, rank, sz, minimal, maximal, x, y);
        } else {
            int x;
            cin >> x;
            int root = find(parent, x);
            cout << minimal[root] << " " << maximal[root] << " " << sz[root] << endl;
        }
    }

    return 0;
}
