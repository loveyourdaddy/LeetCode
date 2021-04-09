//0 ms
// 이걸 찾아낸 사람은 천재야.. 
// stack 에서 parent node을 저장하고 있기 때문에 pop만 해주면 parent을 확인하게 됨
// left 전부 ans 에 넣어준 후 -> right을 검색 

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {        
        stack<TreeNode*> _stack;
        vector<int> ans;

        TreeNode* curr = root;
        while (curr || _stack.size() ) // curr가 nullptr 이 아니고, stack size가 0이 아닐때 -> 빠져나가는조건: curr == null && stack.size == 0
        {
            while (curr ) {
                _stack.push(curr);
                curr = curr->left; // 왼쪽꺼부터 stack에 쌓아둠 
            }
            //stack 쌓아둔걸 pop -> ans 에 쌓기 
            curr = _stack.top(); 
            _stack.pop();
            ans.push_back(curr->val);
            curr = curr->right;            
            
        }

        return ans;
    }
};
