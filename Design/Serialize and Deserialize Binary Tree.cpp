//dynamic programming / greedy 
// 12 ms
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
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}    
}; 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "";
        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            if (!cur) // cur is null 
            {
                ret += "N ";
                continue;
            }
            else
            {
                ret += to_string(cur->val);
                ret += " ";
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return ret;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data[0] == 'N')
            return nullptr;
        string tmp = "";
        vector<string> v;

        //remove tmp
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == ' ')
            {
                v.push_back(tmp);
                tmp = "";
                continue;
            }
            tmp += data[i];
        }
        TreeNode* newRoot = new TreeNode(stoi(v[0]));
        //bfs
        queue<TreeNode*> q;
        q.push(newRoot);
        int i = 1;
        int size = v.size();
        while (!q.empty() && i < size)
        {
            TreeNode* parent = q.front();
            q.pop();
            if (v[i] != "N")
            {
                parent->left = new TreeNode(stoi(v[i]));
                q.push(parent->left);
            }
            i++;
            if (v[i] != "N")
            {
                parent->right = new TreeNode(stoi(v[i]));
                q.push(parent->right);
            }
            i++;
        }
        return newRoot;
    }
};


int main() {
    Codec sol;

	TreeNode* root = new TreeNode(1);
	TreeNode* l = new TreeNode(2);
	TreeNode* r = new TreeNode(3);
    root->left = l; root->right = r;
	TreeNode* rl = new TreeNode(4);
	TreeNode* rr = new TreeNode(5);
    r->left = rl; r->right = rr;

	Codec ser, deser;
    string tmp = ser.serialize(root);
	TreeNode* ans = deser.deserialize(tmp);

    return 0; 
}

#endif //LEETCODE

//python 
