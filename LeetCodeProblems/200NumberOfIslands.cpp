#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int count = 0;

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == '0') continue;

                count++;
                grid[i][j] = '0';
                queue<pair<int, int>> qu;
                qu.push({i,j});
                while(!qu.empty()) {
                    auto curr = qu.front();
                    qu.pop();

                    int first = curr.first;
                    int second = curr.second;

                    if(first -1 >= 0 && grid[first-1][second] == '1') {
                        qu.push({first-1, second});
                        grid[first-1][second] = '0';
                    }
                    if(first +1 < row && grid[first+1][second] == '1') {
                        qu.push({first+1, second});
                        grid[first+1][second] = '0';
                    }
                    if(second -1 >= 0 && grid[first][second-1] == '1') {
                        qu.push({first, second-1});
                        grid[first][second-1] = '0';
                    }
                    if(second + 1 < col && grid[first][second+1] == '1') {
                        qu.push({first, second + 1});
                        grid[first][second + 1] = '0';
                    }
                }
            }
        }

        return count;
    }
};