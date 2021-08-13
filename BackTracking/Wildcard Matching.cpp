class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0, j=0; 
        int match = 0, star = -1;
        while(i < s.length())
        {
            // 진행
            if(j < p.length() && (p[j] == '?' || s[i] == p[j]) )
            {
                i++;
                j++;
            }
            // * 경우, star에 j 인덱스 저장, match에 i 인덱스 저장하고 index 값을 계속 올리기 
            else if(j < p.length() && p[j] == '*')
            {
                star = j;
                match = i;
                j++;
            }
            // star에 값이 있는 경우
            else if(star != -1)
            {
                j = star + 1; // j 고정
                ++match;
                i = match;
            }
            else
                return false; // 값이 다른 경우 
        }
        // 마지막에 j 가 있는 경우, j 인덱스의 값을 올려줌
        while(j<p.length() && p[j]=='*')
            j++;
        
        return j == p.length(); 
    }
};
