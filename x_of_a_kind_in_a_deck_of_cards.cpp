//
// Created by yuki on 2020/3/27.
//

#include "x_of_a_kind_in_a_deck_of_cards.h"
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (a < b) {
        int t = a;
        a = b;
        b = t;
    }
    if(b==0){
        return 1;
    }
    int mod = a % b;
    if (mod == 0) {
        return b;
    } else {
        return gcd(b, mod);
    }
}

bool hasGroupsSizeX(vector<int> &deck) {

    if (deck.size() == 0) {
        return false;
    }
    sort(deck.begin(), deck.end());

    int lastNum = deck.front();
    int preMinCount = 0;
    int lastCount = 1;
    for (int index = 1; index != deck.size(); ++index) {
        if (deck[index] == lastNum) {
            ++lastCount;
        } else {
            if (preMinCount == 0) {
                preMinCount = lastCount;
            } else {
                int value = gcd(preMinCount, lastCount);
                if (value == 1) {
                    return false;
                } else {
                    preMinCount = value;
                }
            }
            lastCount = 1;
            lastNum = deck[index];
        }

    }

    if (lastCount != 0) {
        if (preMinCount == 0) {
            preMinCount = lastCount;
        } else {
            int value = gcd(preMinCount, lastCount);
            if (value == 1) {
                return false;
            } else {
                preMinCount = value;
            }
        }

    }
    return preMinCount > 1;
}

void x_of_a_kind_in_a_deck_of_cards::test() {
    {
        vector<int> nums = {1, 2, 3, 4, 4, 3, 2, 1};
        auto res = hasGroupsSizeX(nums);
        nums.size();
    }
    {
        vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 3};
        auto res = hasGroupsSizeX(nums);
        nums.size();
    }
    {
        vector<int> nums = {1};
        auto res = hasGroupsSizeX(nums);
        nums.size();
    }
    {
        vector<int> nums = {1, 1};
        auto res = hasGroupsSizeX(nums);
        nums.size();
    }
    {
        vector<int> nums = {1, 1, 2, 2, 2, 2};
        auto res = hasGroupsSizeX(nums);
        nums.size();
    }

}
