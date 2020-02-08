//
// Created by 18305 on 2020/2/8.
//

#include "spiral_matrix_ii.h"
#include <vector>
using  namespace std;

vector<vector<int>> generateMatrix(int n) {

    vector<vector<int>> result;
    result.resize(n);
    for(auto& item:result)
    {
        item.resize(n);
    }
    int beginNum = 1;
    for(int index = 0 ;index!=(n+1)/2;++index)
    {
        int endNum = beginNum+4*(n-index*2-1);
        int i=index,j=index;

        int pos=0;
        if(beginNum==endNum)
        {
            result[i][j]=beginNum;

        }
        else
        {
            for(;beginNum<endNum;++beginNum)
            {
                result[i][j]=beginNum;

                if(pos==0)
                {
                    ++j;
                    if(j>=n-index-1)
                    {
                        pos=1;
                    }
                }
                else if(pos==1)
                {
                    ++i;
                    if(i>=n-index-1)
                    {
                        pos=2;
                    }
                }
                else if(pos==2)
                {
                    --j;
                    if(j<=index)
                    {
                        pos=3;
                    }
                }
                else {
                    --i;
                    if (i <= index) {
                        pos = 1;
                    }
                }
            }

        }
    }
    return result;
}

void spiral_matrix_ii::test() {

    {
        vector<vector<int>> r1 = generateMatrix(4);
        r1.size();
    }
    {
        vector<vector<int>> r1 = generateMatrix(5);
        r1.size();
    }
    {
        vector<vector<int>> r1 = generateMatrix(3);
        r1.size();
    }

}
