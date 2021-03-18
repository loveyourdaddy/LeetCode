class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		vector<pair<int, int>> zeroArray;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i][j] == 0) {
					pair<int, int> zero;
					zero.first = i; zero.second = j;
					zeroArray.push_back(zero);
				}
			}
		}				

		for (int idx = 0; idx < zeroArray.size(); idx++)
		{
			// 가로를 바꿔줌.		
			for (int i = 0; i < matrix[0].size(); i++)
			{
				matrix[zeroArray[idx].first][i] = 0;
			}
			// 세로를 바꿔줌.		
			for (int i = 0; i < matrix.size(); i++)
			{
				matrix[i][zeroArray[idx].second] = 0;
			}
		}

    }
};
