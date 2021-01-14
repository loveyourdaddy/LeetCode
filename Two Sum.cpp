class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j)
                    if (nums[i] + nums[j] == target) {
                        output.push_back(i);
                        output.push_back(j);
                        break;
                    }
            }
            if (output.size() != 0)
                break;
        }

        return output;
    }
};

