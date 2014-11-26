/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

#include <iostream>

using namespace std;

    int uniquePaths(int m, int n) {
        // wirte your code here
        int **d = new int* [m];
        for(int i = 0; i < m; ++i)
            d[i] = new int [n];
            
        for(int i = 0; i < m; ++i)
            d[i][0] = 1;
        for(int j = 0; j < n; ++j)
            d[0][j] = 1;
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                d[i][j] = d[i][j-1] + d[i-1][j];
            }
        }
        
        int ans = d[m-1][n-1];
        
        for(int i = 0; i < m; ++i)
            delete [] d[i];
        delete [] d;
        
        return ans;
    }