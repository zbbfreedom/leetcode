//
// Created by 18305 on 2020/2/13.
//

#include "set_matrix_zeroes.h"
#include <vector>
using  namespace std;
void setZeroes(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    bool needClearFirstRow= false;
    for(int j=0;j!=n;++j)
    {
        if(matrix[0][j]==0)
        {
            needClearFirstRow=true;
            break;
        }
    }

    // 这里从第一行，第0列开始扫描，如果第一列有值为0，那么matrix[0][0]也会为0
    // 为啥不从 0 0 开始？ 这里故意跳过第0行 ，按照非第0行的值来更新第0行的value，
    //  那么下面计算  for(int j = 0;j<n;++j)的时候也不能从0开始，否则会被影响
    // 换句话说 这里是1开始，下面操作的地方也得是1开始，下面是1开始，这里就得是1开始
    for(int i=1;i<m;++i)
    {
        for(int j = 0 ;j<n;++j)
        {
            if(matrix[i][j]==0)
            {
                matrix[0][j] = 0;
                matrix[i][0]=0;
            }
        }
    }

    for(int i=1;i!=m;++i)
    {
        if(matrix[i][0]==0)
        {
            for(int j=0;j!=n;++j)
            {
                matrix[i][j]=0;
            }
        }
    }

    for(int j = 0;j<n;++j)
    {
        if(matrix[0][j]==0)
        {
            for(int i=0;i<m;++i)
            {
                matrix[i][j]=0;
            }
        }
    }
    if(needClearFirstRow)
    {
        for(int j=0;j<n;++j)
        {
            matrix[0][j]=0;
        }
    }
}

void set_matrix_zeroes::test() {
    {
        vector<vector<int>> t1 = {{1,0}
        };
       setZeroes(t1);
        t1.size();

    }
    {
        vector<vector<int>> t1 = {{1},{0}
        };
        setZeroes(t1);
        t1.size();

    }

}
