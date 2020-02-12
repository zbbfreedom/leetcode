//
// Created by 18305 on 2020/2/13.
//

#include "plus_one.h"
#include <vector>
using  namespace std;
vector<int> plusOne(vector<int>& digits) {

    int signal = 1;
    for(int i= digits.size()-1;i>=0;--i)
    {
        if(i==digits.size()-1)
        {
            digits[i]+=signal;

        }
        else
        {
            digits[i]+=signal;

        }
        signal = digits[i]/10;
        if(signal==0)
        {
            break;
        }
        digits[i] = digits[i]-digits[i]/10*10;

    }
    if(signal==1)
    {
        digits.insert(digits.begin(),signal);
    }
    return digits;
}
void plus_one::test() {

}
