//
// Created by yuki on 2020/3/22.
//

#include "minimum_increment_to_make_array_unique.h"
#include <vector>

using namespace std;

int minIncrementForUnique(vector<int> &A) {
    if (A.size() <= 0) {
        return 0;
    }
    std::sort(A.begin(), A.end());
    int target = A.front();
    int result = 0;
    for (auto item:A) {
        if (item < target) {
            result += target - item;
            ++target;
        } else {
            target = item + 1;

        }
    }
    return result;
}

int findNext(vector<int> &array, int finder) {
    if (array[finder] == -1) {
        array[finder] = finder;
    } else {
        array[finder] = findNext(array, array[finder] + 1);
    }
    return array[finder];

};

// 空间换时间
int minIncrement2(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    vector<int> array = {-1};
    array.resize(80000, -1);
    int result = 0;
    for (int item:nums) {
        int fuck = findNext(array, item);
        result += fuck - item;
    }
    return result;
}

void minimum_increment_to_make_array_unique::test() {
    {
        vector<int> nums = {3, 2, 1, 2, 1, 7};
        int res = minIncrement2(nums);
        nums.clear();
    }


}
