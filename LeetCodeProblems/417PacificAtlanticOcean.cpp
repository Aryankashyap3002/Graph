#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int row;
    int col;

    vector<vector<int> > dir = {{1,0}, {-1,0}, {0,1}, {0, -1}};
    vector<vector<int>> h;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();

        h = heights;

        queue<pair<int, int> > pacificQu;
        queue<pair<int, int> > atlanticQu;

        for(int i=0; i<row; i++) {
            pacificQu.push({i, 0});
            atlanticQu.push({i, col-1});
        }

        for(int j=1; j<col; j++) {
            pacificQu.push({0, j});
        }

        for(int j=0; j<col-1; j++) {
            atlanticQu.push({row-1, j});
        }

        vector<vector<bool> > pacific = dfs(pacificQu);
        vector<vector<bool> > atlantic = dfs(atlanticQu);
        vector<vector<int> > result;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(pacific[i][j] && atlantic[i][j]) result.push_back({i,j});
            }
        }

        return result;

    }

    vector<vector<bool>> dfs(queue<pair<int, int> >& qu ) {
        vector<vector<bool> > visited(row, vector(col, false));
        while(!qu.empty()) {
            auto curr = qu.front();
            qu.pop();
            int currRow = curr.first;
            int currCol = curr.second;
            visited[currRow][currCol] = true;
            for(int i=0; i<4; i++){
                int r = dir[i][0] + currRow;
                int c = dir[i][1] + currCol;
                if(r < 0 || r >= row || c < 0 || c >= col) continue;
                if(h[currRow][currCol] > h[r][c]) continue;
                if(visited[r][c]) continue;

                qu.push({r,c});
            }
        }

        return visited;
    }
};