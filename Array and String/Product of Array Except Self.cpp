#ifndef LEETCODE
#define LEETCODE

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#include <math.h>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();
        ans.resize(len);
        fill(ans.begin(), ans.end(), 1);
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (i == j) // is not i
                {
                    continue;
                }
                ans[i] *= nums[j];
            }            
        }
        
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums { 1, 2, 3, 4 };
    sol.productExceptSelf(nums);
    return 0; 
}

#endif //LEETCODE
