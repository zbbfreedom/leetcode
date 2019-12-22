//
// Created by suzumiya on 2019/12/22.
//

#include "remove_duplicates_from_sorted_array.h"
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums) {
    int scan_index = 0;
    int fix_index = 0;
    int totalSize = nums.size();
    while (scan_index < totalSize) {
        while (scan_index + 1 < totalSize && nums[scan_index] == nums[scan_index + 1]) {
            ++scan_index;
        }
        nums[fix_index] = nums[scan_index];
        ++fix_index;
        ++scan_index;
    }
    return fix_index;
}

void remove_duplicates_from_sorted_array::test() {
    vector<int> nums = {1, 1, 2};

    auto res = removeDuplicates(nums);

    int a = 0;
}
