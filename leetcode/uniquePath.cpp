    #include <iostream>
#include <vector>

    using namespace std;

    int uniquePaths(int m, int n, vector<vector<int> > &obstacleGrid) {
        int** d = new int* [m];
        for(int i = 0; i < m; ++i)
            d[i] = new int [n];
            
        for(int i = 0; i < m; ++i){
            if(obstacleGrid[i][0] == 1)
                d[i][0] = 0;
            else
                d[i][0] = 1;
        }
        
        for(int j = 0; j < n; ++j){
            if(obstacleGrid[0][j] == 1)
                d[0][j] = 0;
            else
                d[0][j] = 1;
        }
        
        for(int i= 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(obstacleGrid[i][j] == 1)
                    d[i][j] = 0;
                else
                    d[i][j] = d[i][j-1]+d[i-1][j];
            }
        }
        
        int ret = d[m-1][n-1];
        
        for(int i = 0; i < m; ++i)
            delete [] d[i];
        delete [] d;
        
        return ret;
    }

    int main()
    {
        vector<vector<int> > obstacleGrid;
        std::vector<int> v(3);
        v[0] = v[1] = v[2] = 0;

        obstacleGrid.push_back(v);
        v[1] = 1;
        obstacleGrid.push_back(v);
        v[1] = 0;
        obstacleGrid.push_back(v);


        cout << uniquePaths(3,3, obstacleGrid) << endl;

        return 0;
    }