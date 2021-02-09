//https://leetcode.com/problems/string-to-integer-atoi/solution/
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=0; 
        int result=0;
        if(s.length()==0) return 0;
        
        // discard whitespace
        while(s[i]==' ') // + 
            i++;
        
        //check sign
        if(s[i]=='-'){
            sign = 1;
            i++;
        }
        
        //make result with 0<=str[i]<=9, in range 
        
        while(s[i]>='0' && s[i]<='9'){
            if(result>INT_MAX/10 || result<INT_MIN/10)
                return (sign==1)? INT_MIN : INT_MAX;

            result = result*10 + (s[i]-'0');
            i++;
        }

        return (sign==1)? -1*result : result;
    }
};
