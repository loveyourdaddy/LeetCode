// 과거의 (min*curr,max*curr)을 비교 -> 현재 최대값 얻음 -> 지금까지 max값과 비교
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int historyMax=nums[0], historyMin=nums[0], currMax=nums[0], currMin = nums[0];
        int size = nums.size();
        for(int i=1; i<size; i++){
            //historyMax = currMax;             
            //historyMin = currMin; 
            int currMaxTemp = currMax;
            currMax = max(nums[i], max(currMaxTemp*nums[i], currMin*nums[i]));
            currMin = min(nums[i], min(currMaxTemp*nums[i], currMin*nums[i]));
            historyMax = max(historyMax, currMax);//max(currMax, historyMin*nums[i]);
            historyMin = min(historyMin, currMin);
        }
        return historyMax;
    }
};
