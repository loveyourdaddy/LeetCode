//brute force
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        if (nums.size() < 3) return output;
        //1
        for (int i = 0; i < nums.size(); i++)
        {
            //2
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> input = { nums[i], nums[j], nums[k] };
                        sort(input.begin(), input.end());

                        if (output.size() == 0) output.push_back(input);

                        for (int idx = 0; idx < output.size(); idx++) // stack 쌓여있는것이랑 비교. 
                        {
                            if (output[idx][0] != input[0] || output[idx][1] != input[1] || output[idx][2] != input[2]) {
                                if (idx != output.size() - 1)
                                    continue;
                                else // 끝에 도달했을때 
                                    output.push_back(input);
                            }
                            else // 완전히 동일 
                                break;
                        }
                    }
                }
            }
        }
        return output;
    }
};


// 
#include "iostream"
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> ans;
        if (nums.size() < 3) return output;
        sort(nums.begin(), nums.end());

        int len = nums.size();
        int idx = 0;
        while (nums[idx] == 0 )
        {
            idx++;
            if (idx >= len)
                break;
        }
        if (idx >= 3) {
            ans = { 0,0,0 };
            output.push_back(ans);
            return output;
        }
        //중복이 없는 배열을 만들기 

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {                
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) right--;
                else if (sum < 0) left++;
                else 
                {
					ans = { nums[i], nums[left], nums[right] };
					output.push_back(ans);
                    left++;

                    while ( left < right && nums[left - 1] == nums[left] )
                    {
                        left++;
                    }
				}
            }
        }
        return output;
    }
};
int main() {
    Solution sol;
    vector<int> input = {-4,-1,-4,0,2,-2,-4,-3,2,-3,2,3,3,-4};
    vector<vector<int>> result = sol.threeSum(input);

	return 0;
}
