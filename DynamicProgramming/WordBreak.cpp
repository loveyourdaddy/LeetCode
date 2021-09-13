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
