/* Runtime: 14 ms
Memory Usage: 17.7 MB */ 
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int mid = len/2;
		if (len % 2 == 1)
        {
            mid += 1;
        }
        vector<int> ret;
        ret.resize(len);

        for (int i = 0; i < mid; i++) //  i = 0,1,2 , mid = 3 
        {
            ret[2 * i] = nums[mid - 1 - i];
			if (2 * i + 1 < len)
            {
                ret[2 * i + 1] = nums[len - 1 - i];
            }
        }
        nums = ret;
    }
};
