//bottom up 방식
//brute force 
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
            return climb_stairs(i+1,n) + climb_stairs(i+2,n);
    }
};


//DP
class Solution {
public:
    int climbStairs(int n) {              
        int p_before = 1; 
        int p_next = 2;
            
        if(n == 1 || n == 2){
            return n;
        }
        else{
            for(int i=3; i<=n; i++){
                int tmp = p_next; 
                p_next = p_before + p_next;
                p_before = tmp;
                //swap(p1,p2)
                //p2=p1+p2
            }            
        }
        
        return p_next;
    }
    
};
