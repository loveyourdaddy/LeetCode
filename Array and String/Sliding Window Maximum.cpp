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
		// auto maxVal = std::max_element(tmpVec.cbegin(), tmpVec.cend());
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

// time limit exceeded 
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
#include <deque>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		
        deque<int> window;
        vector<int> ret;
        int curr_max = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            window.push_back(nums[i]);
            // 먼저 window에 채워넣기
            if (i < k - 1)
                continue;
            
            // 추가된 값이 현재 최대값보다 크다면 최대값 교체 
            if (curr_max ==  INT_MIN)
            {
                curr_max = *max_element(window.begin(), window.end());
            }
            else if (nums[i] > curr_max)
            {
                curr_max = nums[i];
            }

            // 최대값을 윈도우에서 빼면 초기화
            ret.push_back(curr_max);
            if (curr_max == window.at(0))
            {
                curr_max = INT_MIN;
            }
            window.pop_front();
            
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> nums1{ 1,3,1,2,0,5 };

    sol.maxSlidingWindow(nums1, 3);
    return 0; 
}

#endif //LETCODE

// Runtime: 300 ms
// Memory Usage: 131.9 MB
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		
        deque<int> window; // 윈도우에는 인덱스가 저장됨
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            // 가장최근에 들어왔던 것과 새로 들어올 것의 크기 비교 -> 새로들어올게 크다면 가장최근에 들어왔던걸 버림
            while (!window.empty() && nums[window[window.size() - 1]] <= nums[i])
                window.pop_back();
            
            // 새로운걸 넣기
            window.push_back(i);
            
            // k값과 비교해서 예전껀 버리기
            if (i - window.at(0) >= k)
                window.pop_front();

            if (i + 1 >= k)
                ret.push_back(nums[window.at(0)]);
        }

        return ret;
    }
};
