#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int> > qu;
        int fo = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1) fo++;
                if(grid[i][j] == 2) qu.push({i,j});
            }
        }

        qu.push({-1,-1});
        int mins = 0;

        while(!qu.empty()) {
            auto curr = qu.front();
            qu.pop();
            if(curr.first == -1) {
                mins++;
                if(qu.empty()) {
                    break;
                } else {
                    qu.push({-1,-1});
                }
            }
            vector<vector<int> > dirs = {{1,0},{-1,0},{0,1},{0,-1}};
            for(int i=0; i<4; i++) {
                int nr = curr.first + dirs[i][0];
                int nc = curr.second + dirs[i][1];

                if(nr < 0 || nc < 0 || nr >= row || nc >= col) continue;
                if(grid[nr][nc] == 2 || grid[nr][nc] == 0) continue;
                fo--;
                qu.push({nr,nc});
                grid[nr][nc] = 2;
            }

        }

        return fo ? -1 : mins-1;
        
    }
};