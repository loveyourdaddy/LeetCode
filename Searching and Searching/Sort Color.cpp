class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                //change low and mid 
                int tmp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = tmp;                 
                low++;
                mid++;
                continue;
            }
            if(nums[mid] == 1){
                mid ++;
                continue;
            }
                
            if(nums[mid] == 2){
                //change mid and high 
                int tmp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = tmp;
                high--;
                continue;
            }
        }
    }
};
