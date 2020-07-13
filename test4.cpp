#include <bits/stdc++.h>
class Solution {
public:
    static int nofisland, ci, cj, n, m;
    
    static bool find1(vector<vector<char>>& grid) {
        for(int i = ci; i<n; i++) {
            for(int j = cj; j<m; j++) {
                if(grid[i][j] == '1') {
                    ci = i; cj = j;
                    return true;
                }
            }
        }
        return false;
    }
    
    static bool searchisland(vector<vector<char>>& grid, int i, int j) {
        if(i<0 || j<0 || i>n-1 || j>m-1 || grid[i][j] == '0') return false;
        grid[i][j] = '0';
        searchisland(grid, i+1, j);
        searchisland(grid, i-1, j);
        searchisland(grid, i, j+1);
        searchisland(grid, i, j-1);
        return false;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        while(find1(grid)){
            searchisland(grid, ci, cj);
            nofisland++;
        } 
        return nofisland;
    }
};

int Solution::nofisland = 0;
int Solution::ci = 0;
int Solution::cj = 0;
int Solution::n = 0;
int Solution::m = 0;
