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
