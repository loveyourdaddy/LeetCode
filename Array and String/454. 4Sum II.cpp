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

// O(n^4)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        int size = nums1.size();
        for (int a = 0; a < size; a++)
        {
            for (int b = 0; b < size; b++)
            {
                for (int c = 0; c < size; c++)
                {
                    for (int d = 0; d < size; d++)
                    {
						if (nums1[a] + nums2[b] + nums3[c] + nums4[d] == 0)
                        {
                            ans += 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums1{ 1, 2 };
    vector<int> nums2{ -2, -1 };
    vector<int> nums3{ -1, 2 };
    vector<int> nums4{ 0, 2 };

    sol.fourSumCount(nums1, nums2, nums3, nums4);
    return 0; 
}

#endif //LEETCODE

// O(n^2)
// Runtime: 280 ms
// Memory Usage: 24.6 MB
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        map<int, int> m; // 합한 값, 등장횟수

        for (auto a : nums1)
        {
            for (auto b : nums2)
            {
                m[a + b]++;
            }
        }

        // it: map iterator
		for (auto c : nums3)
        {
            for (auto d : nums4)
            {
                auto it = m.find(-1 * (c + d));
                if (it != m.end())
                {
                    ans += it->second;
                }
            }
        }

        return ans;
    }
};

