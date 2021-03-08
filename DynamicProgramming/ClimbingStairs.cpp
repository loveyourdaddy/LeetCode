//bottom up 방식
class Solution {
public:
    int climbStairs(int n) {
        return climb_stairs(0, n);
    }
    int climb_stairs(int i, int n){
        if(i == n)
            return 1; 
        else if(i > n)
            return 0;
        else // 도달하지 못한 경우 
            return climb_stairs(i-1,n) + climb_stairs(i-2,n);
    }
};
