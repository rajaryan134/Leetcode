class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }

    void recursion(TreeNode* root, int level, vector<int>& res) {
        if (root == NULL)
            return;

        // First node we see at this level is visible from right
        if (res.size() == level)
            res.push_back(root->val);

        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }
};