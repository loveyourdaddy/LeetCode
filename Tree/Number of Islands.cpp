// 8 ms / 9.5 MB
// https://hongku.tistory.com/160
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

// Definition for a binary tree node.
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0; 
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    mark(grid, i, j);
                    count++;
                }
            }
        }
        return count;
	}
	void mark(vector<vector<char>>& grid, int row, int col) {
		grid[row][col] = '-';

		if (row > 0 && grid[row - 1][col] == '1') {
			grid[row - 1][col] = '-';     // check up
			mark(grid, row - 1, col);
		}
		if (row < grid.size() - 1 && grid[row + 1][col] == '1') {
			grid[row + 1][col] = '-';   // check down 
			mark(grid, row + 1, col);
		}

		if (col > 0 && grid[row][col - 1] == '1') {
			grid[row][col - 1] = '-';   // check left 
			mark(grid, row, col - 1);
		}
		if (col < grid[row].size() - 1 && grid[row][col + 1] == '1') {
			grid[row][col + 1] = '-';   // check right 
			mark(grid, row, col + 1);
		}

	}
};

int main() {
    Solution sol;

    // TreeNode tree3(3), tree2(2, &tree3, nullptr), tree1(1, nullptr, &tree2);  
    
//    vector<int> rid = { 1, 1, 1, 1, 0 };
//    char ch(1);
    vector<vector<char>> grid = {
        vector<char>{'1', '1', '1', '1', '0'},
        vector<char>{'1', '1', '0', '1', '0'},
        vector<char>{'1', '1', '0', '0', '0'},
        vector<char>{'0', '0', '0', '0', '0'} 
    };
	
    int ans = sol.numIslands(grid);

    cout << ans << endl;
    
    return 0; 
}

// 이렇게 직접 입력해줘도 됨. 
//vector<vector<int>> v8({
//  vector<int>({1, 2, 3}),
//  vector<int>({4, 5, 6, 7, 8}),
//  vector<int>({9, 10}),
//  vector<int>({11, 12, 13})
//    });
