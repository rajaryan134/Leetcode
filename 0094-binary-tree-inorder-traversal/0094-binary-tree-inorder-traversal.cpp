class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr)
            return;

           // Root
        inorder(root->left, ans);  
        
        ans.push_back(root->val);// Left
        inorder(root->right, ans); // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};