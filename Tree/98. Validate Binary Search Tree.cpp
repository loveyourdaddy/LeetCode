/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 1d vector로 만들어서 ascending order 인지 확인
    void inorder(TreeNode* root, vector<int>& v){
        if(root==NULL) return ;
        inorder(root->left, v);
        v.push_back(root->val);       
        inorder(root->right, v);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;              
        vector<int> vec;
        inorder(root, vec);
        for(int i=1; i<vec.size(); i++){
            if(vec[i-1]>=vec[i]) return false;            
        }
        return true;
    }
    
};
