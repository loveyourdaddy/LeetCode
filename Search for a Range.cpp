//Find First and Last Position of Element in Sorted Array
//8 ms
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //binary search 
        int ret = binarySearch(nums, target);
        std::cout<< ret << std::endl;
        if(ret == -1 ){
            vector<int> ans = {-1,-1};
            return ans;
        }
        int i, j;
        //get first index 
        for(i = ret; i-1>=0 && nums[i-1]==target ; i--);
        //get last index 
        for(j = ret;  j+1<nums.size() && nums[j+1]==target; j++);
        
        vector<int> ans = {i,j};
        return ans;            
    }
    
    int binarySearch(vector<int>& nums, int target)
    {        
        int low =0, high = nums.size() -1 ;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(nums[mid] < target)
                low = mid +1;
            else if(target < nums[mid])
                high = mid - 1;
            else 
                return mid;
        }
        return -1;
    }
        
        
};
