class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int tmp;
		int n = matrix.size(); 		
		
		for (int i = 0; i < n/2; i++) //layer 마다  (i = 0, 1)
		{	
			for (int j = 0; j < n-2*i-1; j++) //줄 하나안에서의 index  (j = 0, 1) 
			{				
				tmp = matrix[i][j + i];
				matrix[i][i + j] = matrix[n - 1 - j - i][i];
				matrix[n - 1 - j - i][i] = matrix[n - i - 1][n - 1 - j - i];
				matrix[n - i - 1][n - 1 - j - i] = matrix[j + i][n - i - 1];
				matrix[j + i][n - i - 1] = tmp;
				//matrix[i*2-1 + j][i*2] = matrix[i*2-1][i*2-1 + j];
			}		
		}

		
	}
};
