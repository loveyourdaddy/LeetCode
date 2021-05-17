//dynamic programming / greedy 
// 12 ms
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
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return true;
		int curIdx = 0, curJump = nums[curIdx];
        //int maxIdx = 0, maxJump = nums[maxIdx];
        int i;
		for (i = 1; i <= curJump; i++)
        {
			if (i + nums[curIdx + i] >= curJump) 
            {
                curIdx += i;
                curJump = nums[curIdx];
                i = 0;
            }        

			if (curIdx + curJump >= len - 1)
                return true;
        }
        
		return false;
    }
};

int main() {
    Solution sol;

	vector<int> nums = { 1,1,1,0 };
    
    bool ans = sol.canJump(nums);

    return 0; 
}

#endif //LEETCODE
