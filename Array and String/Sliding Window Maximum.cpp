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
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int totalCount = nums.size() - k + 1;
        vector<int> ret;
        for (int i = 0; i < totalCount; i++)
        {
            vector<int> tmpVec; 
            for (int j = 0; j < k; j++)
            {
                tmpVec.push_back(nums[i+j]);
            }
            int tmp = findMax(tmpVec);
			ret.push_back(tmp);
        }
        return ret;
    }

    int findMax(vector<int> vec)
    {
        int largest = vec[0];
        int size = vec.size();
        for (int i = 0; i < size; i++)
        {
            if (vec[i] > largest)
            {
                largest = vec[i];
            }
        }
        return largest;
    }
};

int main() {
    Solution sol;
    vector<int> nums1{ 1,3,-1,-3,5,3,6,7 };

    sol.maxSlidingWindow(nums1, 3);
    return 0; 
}

#endif //LETCODE
