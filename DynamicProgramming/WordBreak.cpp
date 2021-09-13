/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map <int, int> map; // word index, end index 
        auto len = wordDict.size();        

        for (int i = 0; i < len; i++)
		{
			map.insert(pair<int, int>(i, 0));
		}

		for (int i = 0; i < len; i++)
		{
			// 초기화 
			for (int j = 0; j < len; j++)
			{
				int find = s.find(wordDict[j], 0);
				if (find == 0)
				{
					map.at(j) = wordDict[j].size();
				}
				else
					map.at(j) = 0;
			}

			int startIdx = map.at(i);
				//wordDict[i].size();
			for (int j = 0; j < len; j++)
			{
				//int index = map.at(j);
				int tmp = s.find(wordDict[j], startIdx);

				if (map.at(j) == s.length())
					return true;
				if (tmp == startIdx)
				{
					map.at(j) = startIdx + wordDict[j].size();
					startIdx = map.at(j);

					if (map.at(j) == s.length())
						return true;
					j = -1;
				}

			}
		}

		return false;
	}
};
*/


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    auto tmp1 = s.substr(j, i - j);
                    auto tmp2 = words.count(s.substr(j, i - j));

                    cout << "tmp:" << tmp1 << endl;
                    cout << "tmp:" << tmp2 << endl;
                    if (words.count(s.substr(j, i - j))) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }

        return dp[n];
	}
};
