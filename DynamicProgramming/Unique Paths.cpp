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
//DP
//0ms 
class Solution {
public:
    int uniquePaths(int m, int n) {
        //int[][] area = new int[n][m];
        int area[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i ==0 || j==0)
                    area[i][j] =1;
                else // i & j >= 1
                    area[i][j]=area[i-1][j] + area[i][j-1];
            }
        }
        return area[m-1][n-1];
    }
    
};
