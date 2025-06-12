#include<iostream>
#include<vector>

using namespace std;

int find(vector<int> &parent, int x) {
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

bool Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if(a == b) return true;
    if(rank[a] >= rank[b]) {
        rank[a]++;
        parent[b] = a;
    } else {
        rank[b]++;
        parent[a] = b;
    }

    return false;
}

int main() {
    int n,m;
    // n->element m->no. of queries
    cin>>n>>m;
    vector<int> rank(n+1, 0);
    vector<int> parent(n+1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    while(m--) {
        string str;
        cin>>str;
        if(str == "union") {
            int x,y;
            cin>>x>>y;
            bool b = Union(parent, rank, x, y);
            if(b == true) cout<<"Cycle detected"<<endl;
        } else {
            int x;
            cin>>x;
            cout<<find(parent, x)<<endl;
        }
    }
    return 0;
}