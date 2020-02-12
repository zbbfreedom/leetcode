//
// Created by 18305 on 2020/2/13.
//

#include "minimum_path_sum.h"
#include <vector>
using namespace std;

int minPathSum2(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> result ;
    result.resize(m);
    if(n==0)
    {
        return 0;
    }
    for(int i=0;i!=m;++i)
    {
        if(i==0)
        {
            result[0] = grid[0][0];
            continue;
        }
        else
        {
            result[i] = result[i-1]+grid[i][0];
        }
    }
    for(int j=1;j!=n;++j)
    {
        for(int i=0;i!=m;++i)
        {
            if(i==0)
            {
                result[i] +=grid[i][j];
                continue;
            }
            else
            {
                result[i] = min(result[i],result[i-1])+grid[i][j];
                continue;
            }
                }

    }
    return result[m-1];
}
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    for(auto  i = 0;i!=m;++i)
    {
        for(auto  j=0;j!=n;++j)
        {
            if(i==0&&j==0)
            {
                continue;
            }
            if(i==0)
            {
                grid[i][j]=grid[i][j-1]+grid[i][j];
            }
            else if(j==0)
            {
                grid[i][j] = grid[i-1][j]+grid[i][j];
            }
            else
            {
                grid[i][j] = min(grid[i-1][j],grid[i][j-1])+grid[i][j];
            }
        }
    }
    return grid[m-1][n-1];
}


void minimum_path_sum::test() {
    {
        vector<vector<int>> t1 = {{1,3,1},
                                  {1,5,1},
                                  {4,2,1}
        };
        int v = minPathSum2(t1);
        t1.size();
    }

}
