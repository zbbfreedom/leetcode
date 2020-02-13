//
// Created by 18305 on 2020/2/14.
//

#include "search_a_2d_matrix.h"
#include <vector>
using  namespace std;
bool searchInVector(vector<int>& nums,int begin,int end,int target)
{
    if(begin>end)
    {
        return false;
    }
    int middle = begin+(end-begin)/2;

    if(nums[begin]==target||nums[end]==target)
    {
        return true;
    }
    else
    {
        if(nums[middle]==target)
        {
            return true;
        }
        else if(nums[middle]>target)
        {
            return searchInVector(nums,begin+1,middle-1,target);
        }
        else
        {
            return searchInVector(nums,middle+1,end,target);
        }
    }
}

void translate(int& value,int &row,int& col,const int& n)
{
    if(n<=0)
    {
        row=-1,col=-1;
        return;
    }
    row = value/n;
    col = value-value/n*n;
}
bool searchFuck(vector<vector<int>>& matrix,int begin,int end ,int target)
{
    if(begin>end)
    {
        return false;
    }
    int n = matrix[0].size();
    int middle = begin+(end-begin)/2;

    {
        int beginRow=0,beginCol = 0;
        translate(begin,beginRow,beginCol,n);
        if(matrix[beginRow][beginCol]==target)
        {
            return true;
        }
    }
    {
        int beginRow=0,beginCol = 0;
        translate(end,beginRow,beginCol,n);
        if(matrix[beginRow][beginCol]==target)
        {
            return true;
        }
    }
    {
        {
            int beginRow=0,beginCol = 0;
            translate(middle,beginRow,beginCol,n);
            if(matrix[beginRow][beginCol]==target)
            {
                return true;
            }
            else if(matrix[beginRow][beginCol]>target)
            {
                return searchFuck(matrix,begin+1,middle-1,target);
            }
            else
            {
                return searchFuck(matrix,middle+1,end,target);
            }

        }
    }
}
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    if(matrix.size()<=0)
    {
        return false;
    }
    if(matrix[0].size()<=0)
    {
        return false;
    }
    int m  = matrix.size();
    int n = matrix[0].size();
    return searchFuck(matrix,0,m*n-1,target);
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    bool findRow = false;
    int index = 0;
    for( ;index<matrix.size();++index)
    {
        if(matrix[index].size()==0)
        {
            continue;
        }
        int first = matrix[index].front();
        int last = matrix[index].back();
        if(first==target||last==target)
        {
            return true;
        }
        else
        {
            if(first<target&&target<last)
            {
                return searchInVector(matrix[index],0,matrix[index].size()-1,target);
            }
            else if(target<first)
            {
                return false;
            }
            else
            {
                continue;
            }
        }
    }
    return false;
}
void search_a_2d_matrix::test() {

    {
        vector<vector<int>> t1 = {{1,3,5,10},
                                  {11,17,25,31},
                                  {44,52,71,88}
        };
        bool v = searchMatrix2(t1,12);
        bool v2 = searchMatrix2(t1,17);
        t1.size();

    }
}
