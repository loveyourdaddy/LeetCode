// breadth first search 
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

 // //Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == nullptr) return ans;

		//queue 선언  // pair<tree, level >
		queue<pair<TreeNode*, int>> que;
		//level 선언
		int level = -1;
		que.push(make_pair(root, 0));

		while (!que.empty())
		{			
			//현재의 pair 선언 	//값이 있을 때 queue에 넣어줌
			pair<TreeNode*, int> cur = que.front();
			que.pop();
						
			if (cur.first->right != nullptr)
				que.push(make_pair(cur.first->left, cur.second + 1));
			if (cur.first->left != nullptr)
				que.push(make_pair(cur.first->right, cur.second + 1));

			//curLevel == pair의 level 이라면, ans의 해당 레벨에 넣어줌 (right 인 경우)
			if (level == cur.second) 
				ans[level].push_back(cur.first->val);
			//아니라면, 다음 레벨에 값을 넣어줌 (left인 경우)
			else
			{
				level++;
				vector<int> tmp; tmp.push_back(cur.first->val);
				ans.push_back(tmp);
			}
		}

		//index가 홀수라면 reverse 
		int index = 0; 
		while (index < ans.size())
		{
			reverse(ans[index].begin(), ans[index].end());
			index += 2; 
		}
		return ans;
    }
};

int main() {
    Solution sol;
	TreeNode tree1(15), tree2(7), tree3(20, &tree1, &tree2), tree4(9), tree5(3, &tree4, &tree3);
    	
    vector<vector<int>> ans = sol.zigzagLevelOrder(&tree5);

	for (int a=0; a<ans.size(); a++)
	{
		for (int b=0; b<ans[a].size(); b++)
		{
			cout << ans[a][b] << "\t" ;
		}		
		cout <<  endl;

	}
    
    
    return 0; 
}
