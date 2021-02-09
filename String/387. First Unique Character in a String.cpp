https://leetcode.com/problems/first-unique-character-in-a-string/
class Solution {
public:
    int firstUniqChar(string s) {
        int map[26] = {0};
        for(auto ch : s){
            ++map[ch - 'a'];             
        }
        int len = s.length();
        for(int i=0; i<len; i++){
            if(map[s[i]-'a'] == 1) return i;
        }
        
        return -1;
    }
};
