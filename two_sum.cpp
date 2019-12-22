//
// Created by 赵斌斌 on 2019/12/19.
//

#include "two_sum.h"
#include <vector>
#include <functional>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {


    auto fetchOrignalResult =[nums](int value,bool preOrder) {
        if(preOrder)
        {
            for (auto index = 0;index!=nums.size();++index)
            {
                if(nums[index]==value)
                {
                    return (int)index;
                }
            }

        } else{
            for (auto index = nums.size()-1;index>=0;--index)
            {
                if(nums[index]==value)
                {
                    return (int)index;
                }
            }

        }
        return -1;
    };
    std::sort(nums.begin(),nums.end(),[=](int left,int right){return left<right;});

    unsigned begin = 0;
    unsigned end = nums.size()-1;
    while(begin<end)
    {
        int total = nums[begin]+nums[end];
        if(total==target)
        {
            return {fetchOrignalResult(nums[begin],true),fetchOrignalResult(nums[end],false)};
        }
        else if (total<target)
        {
            ++begin;
        }
        else
        {
            --end;
        }
    }
    return {fetchOrignalResult(nums[begin],true),fetchOrignalResult(nums[end],false)};
}

void two_sum::test() {

    {
        vector<int> testData={2,11,7,15};
        int target = 9;
        vector<int> result = twoSum(testData,target);

    }
    {
        vector<int> testData={3,2,9};
        int target = 11;
        vector<int> result = twoSum(testData,target);

        int a=0;
    }
    {
        vector<int> testData={3,3};
        int target = 6;
        vector<int> result = twoSum(testData,target);

        int a=0;
    }

}

