// unordered_map: hash 형태의 map : for문은 auto로 접근
// priority_queue: 자동으로 sorting 되는 map : top()으로 가장 위의 값 가져오기 
// 16 ms
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

// char to string : string(1, char)
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) { 
        // <value, 반복횟수> map을 만들어줌. 
        unordered_map<int, int> map;
        
        for (auto n : nums)
            map[n]++;

        // value을 중심으로 descending order로 sorting 함 
        priority_queue<pair<int, int>> pq;
        for (auto m : map) {            
            pq.push({ m.second, m.first});
        }               

        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
	}
};

int main() {
    Solution sol;

    vector<int> input = { 1,1,1,2,2,3 };
    int k = 2;
    vector<int> ans = sol.topKFrequent(input, k);

    return 0; 
}
