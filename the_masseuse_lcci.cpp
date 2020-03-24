//
// Created by yuki on 2020/3/24.
//

#include "the_masseuse_lcci.h"
#include <vector>

using namespace std;

int massage(vector<int> &nums) {
    if (nums.size() == 0) {
        return 0;
    }

    for (int index = 0; index != nums.size(); ++index) {
        if (index == 0) {
            continue;
        } else {
            if (index == 1) {
                nums[index] = max(nums[index - 1], nums[index]);
            } else {
                nums[index] = max(nums[index - 1], nums[index - 2] + nums[index]);

            }
        }
    }
    return nums.back();
}

void the_masseuse_lcci::test() {
    {
        vector<int> nums = {2, 1, 4, 5, 3, 1, 1, 3};
        int res = massage(nums);
        nums.clear();
    }
    {
        vector<int> nums = {};
        int res = massage(nums);
        nums.clear();
    }

}
