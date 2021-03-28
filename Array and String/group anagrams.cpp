// map 함수 : map[key] = val
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hashMap; 
        vector<vector<string>> output;

        // 각 원소에 대해서 check
        int iSize = strs.size();
        for (int i = 0; i < iSize; i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());

            //해당 str이 hashmap에 없는 경우 
            if (hashMap.count(str) == 0)
            {
                vector<string> tmp;                 
                hashMap[str] = tmp;
            }
            hashMap[str].push_back(strs[i]);
        }

        int size = hashMap.size();
        map<string, vector<string>>::iterator it;
        for (it = hashMap.begin(); it != hashMap.end(); it++)
        {
            vector<string> tmp = it->second;
            output.push_back(tmp);
        }
        return output;
    }
};

int main() {
    Solution sol;
    vector<string> str = { "eat", "tea", "tan", "ate", "nat", "bat" };
    
    vector<vector<string>>  ans = sol.groupAnagrams(str) ;
    for (auto val : ans)
    {
        for (auto val1 : val)
            cout << val1 << endl;
    }

    return 0; 
}
