// Brute force 
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

// DP
// Runtime: 8 ms
// Memory Usage: 11.8 MB
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
		int maxProduct = nums[0];
		int minProduct = nums[0];
        int ans = nums[0];
        int length = nums.size();
        
        for (int i = 1; i < length; i++) // begin 
        {
            int now = nums[i];
            int minTmp = min({ now, now * maxProduct, now * minProduct });
            int maxTmp = max({ now, now * maxProduct, now * minProduct });
            minProduct = minTmp;
			maxProduct = maxTmp;
            
            if (ans < maxProduct)
                ans = maxProduct;
        }

        return ans;
    }
};
