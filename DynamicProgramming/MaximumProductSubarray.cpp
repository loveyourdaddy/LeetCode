// 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max = INT_MIN;
        int length = nums.size();
        for (int i = 0; i < length; i++) // begin 
        {
            for (int j = i; j < length; j++) // end 
            {
				int tmp = 1;
                for (int k = i; k <= j; k++)
                {
                    tmp *= nums[k];
                }
                if (max < tmp)
                {
                    max = tmp;
                }
            }
        }

        return max;
    }
};
