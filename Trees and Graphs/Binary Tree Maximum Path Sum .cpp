
class Solution {
public:
    int maxVal = INT_MIN;
    int maxPathSum(TreeNode* root) {
        find(root);
		return maxVal;
    } 

    int find(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int leftSum = max(find(node->left), 0);
        int rightSum = max(find(node->right), 0);
        maxVal = max(node->val + leftSum + rightSum, maxVal);
	return max(leftSum, rightSum) + node->val;
    }
};
int main() {
    Solution sol;
    TreeNode l(2);
    TreeNode r(3);
    TreeNode top(1, &l, &r);
    bool ans = sol.maxPathSum(&top);
    return 0; 
}
