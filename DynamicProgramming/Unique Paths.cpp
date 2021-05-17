//factorial 
class Solution {
public:
    int uniquePaths(int m, int n) {
        return factorial(m + n - 2) / (factorial(m-1)*factorial(n-1));
    }
    
    int factorial(int n){
        if(n<=0)
            return 1;
        if(n<2)
            return n;
        else
            return n*factorial(n-1);
    }
};
