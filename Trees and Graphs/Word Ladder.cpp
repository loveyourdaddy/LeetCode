// remeber: 
// queue: erase
// set: find(못찾으면 end 반환)
// string: compare(다르면 1, 같으면 0)
#ifndef LEETCODE
#define LEETCODE

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#include <math.h>
#include <deque>
#include <set>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dict(wordList.begin(), wordList.end());
        queue<string> que; // 찾은 단어들을 저장하고 pop 함
        que.push(beginWord);
		int result = 1;

        while (!que.empty())
        {
            int size = que.size();
            for (int q_size = 0; q_size < size; q_size++)
            {
                string cur = que.front();
                que.pop();
                dict.erase(cur);
                // endWord에 도달했다면
                if (cur.compare(endWord) == 0)
                    return result;

                // string의 내부 문자를 바꾸기 
                int stringSize = cur.size();
                for (int i = 0; i < stringSize; i++)
                {
                    char c = cur[i];
                    for (int s = 0; s < 26; s++) 
                    {
                        cur[i] = 'a' + s;
                        // 겹치는 것이 있다면 
                        if (dict.find(cur) != dict.end())
                        {
                            // que에는 쌓고 dict에서는 지움 
                            que.push(cur);
                            dict.erase(cur);
                        }
                    }
                    cur[i] = c;
                }
            }
            result++;

        }
        return 0;
	}
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");
    int ans = sol.ladderLength(beginWord, endWord, wordList);
    return 0; 
}

#endif //LETCODE

