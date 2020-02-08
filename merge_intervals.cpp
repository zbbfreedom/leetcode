//
// Created by 18305 on 2020/2/8.
//

#include "merge_intervals.h"
#include <vector>
#include <map>
#include<algorithm>

using  namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {

    std::sort(intervals.begin(),intervals.end(),[](vector<int>& l,vector<int>& r)
    {
        return l.front()<r.front();
    });

    int backIndex = -1;
    for(auto& unordered_data:intervals)
    {
        if(backIndex<0)
        {
            backIndex=0;

            continue;
        }
        else
        {
            auto& lastInterval = intervals[backIndex];

            if((unordered_data.front()>=lastInterval.front()&&unordered_data.front()<=lastInterval.back())
            ||(unordered_data.back()>=lastInterval.front()&&unordered_data.back()<=lastInterval.back()))
            {
                lastInterval.back() = max(lastInterval.back(),unordered_data.back());

            }
            else
            {
                ++backIndex;
                intervals[backIndex]={unordered_data.front(),unordered_data.back()};
            }
        }
    }
    if(backIndex>=0)
    {
        intervals.resize(backIndex+1);
    }
    return intervals;
}

void merge_intervals::test() {
    {
        vector<vector<int>> t1 = {{1,5},{2,9},{0,1},{10,15},{14,16}};
        auto r1 = merge(t1);
        r1.size();
    }
}
