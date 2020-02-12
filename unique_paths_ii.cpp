//
// Created by 18305 on 2020/2/8.
//

#include "unique_paths_ii.h"
#include <vector>
#include <array>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    std::array<array<long,100>,100> array1={0};

    for (auto i = 0; i != m; ++i) {
        for (auto j = 0; j != n; ++j) {
            if (i == 0 && j == 0) {
                array1[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
                continue;
            }

            if (obstacleGrid[i][j] == 0) {
                if (i == 0) {
                    array1[i][j] = array1[i][j - 1];

                } else if (j == 0) {
                    array1[i][j] = array1[i - 1][j];

                } else {
                    array1[i][j] = array1[i - 1][j] + array1[i][j - 1];

                }

            } else {
                array1[i][j] = 0;
            }
        }
    }

    return array1[m - 1][n - 1];
}


void unique_paths_ii::test() {
    {
        {
            vector<vector<int>> t1 = {{0, 0, 0},
                                      {0, 1, 0},
                                      {0, 0, 0}
            };
            int v = uniquePathsWithObstacles(t1);
            t1.size();
        }
        {
            vector<vector<int>> t1 = {{1, 0}
            };
            int v = uniquePathsWithObstacles(t1);
            t1.size();
        }

    }
}
