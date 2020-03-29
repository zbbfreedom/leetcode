//
// Created by yuki on 2020/3/29.
//

#include "subsets.h"

#include <vector>

using namespace std;

vector<vector<int>> innerMethod(vector<int> &nums, int begin) {
    vector<vector<int>> result;
    if (begin > nums.size() - 1) {
        result.push_back({});
        return result;
    } else {
        auto fuck = innerMethod(nums, begin + 1);
        for (auto item: fuck) {
            auto item_copy = item;
            item_copy.insert(item_copy.begin(), nums[begin]);
            result.push_back(item_copy);

            auto item_copy2 = item;
            result.push_back(item_copy2);
        }
        return result;
    }

}

vector<vector<int>> subsets1(vector<int> &nums) {
    vector<vector<int>> result;

    if (nums.size() == 0) {
        return result;
    }

    int length = nums.size();
    return innerMethod(nums, 0);
}

void subsets::test() {
    {
        vector<int> test = {1, 2, 3};
        auto res = subsets1(test);
        test.size();
    }
}
