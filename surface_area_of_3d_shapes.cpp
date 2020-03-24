//
// Created by yuki on 2020/3/25.
//

#include "surface_area_of_3d_shapes.h"
#include <vector>
using namespace std;
int surfaceArea(vector<vector<int>>& grid) {
    int totalCurb = 0;
    int fucker =0;
    for(int row = 0;row!=grid.size();++row)
    {
        for(int col = 0;col!=grid[row].size();++col)
        {
            int num= grid[row][col];
            totalCurb+=num;
            if(num>0){
                fucker+=num-1;
            }
            if(row>0){
                int top = grid[row-1][col];
                fucker+=min(top,num);
            }
            if(col>0){
                int left = grid[row][col-1];
                fucker+=min(left,num);
            }
        }
    }

    return 6*totalCurb-2*fucker;
}

void surface_area_of_3d_shapes::test() {
    {
        vector<vector<int>> test= {
                {1,1,1},
                {1,0,1},
                {1,1,1}
        };
        int value = surfaceArea(test);
        test.clear();
    }
}
