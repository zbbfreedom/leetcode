//
// Created by 18305 on 2020/2/8.
//

#include "unique_paths.h"
#include <vector>
using  namespace std;
int uniquePaths(int m, int n) {
    vector<vector<int>> array1;
    array1.resize(m + 1);
    for(auto& item:array1)
    {
        item.resize(n+1);
    }
    for(auto index = 0;index!=m+1;++index)
    {
        array1[index][1]=1;
    }
    for(auto index = 0;index!=n+1;++index)
    {
        array1[1][index]=1;
    }

    for(auto i=2;i!=m+1;++i)
    {
        for(auto j=2;j!=n+1;++j)
        {
            array1[i][j]= array1[i - 1][j] + array1[i][j - 1];
        }
    }

    return array1[m][n];
}

void unique_paths::test() {
    {
        int v=uniquePaths(7,3);
        vector<int> f;
        f.resize(1);
    }
}
