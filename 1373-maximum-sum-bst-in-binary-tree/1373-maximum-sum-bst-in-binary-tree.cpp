class Solution {
private:
    struct NodeValue {
        int minNode;
        int maxNode;
        int maxSum;

        NodeValue(int minNode, int maxNode, int maxSum) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSum = maxSum;
        }
    };

    NodeValue maxSumBSTHelper(TreeNode* root) {
        // Empty tree
        if (root == NULL) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Get information from left and right subtrees
        NodeValue left = maxSumBSTHelper(root->left);
        NodeValue right = maxSumBSTHelper(root->right);

        // Check if current tree is a BST
        if (left.maxNode < root->val &&
            root->val < right.minNode) {

            int sum = left.maxSum + right.maxSum + root->val;

            // Update answer
            ans = max(ans, sum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                sum
            );
        }

        // Not a BST
        return NodeValue(
            INT_MIN,
            INT_MAX,
            0
        );
    }

    int ans = 0;

public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        maxSumBSTHelper(root);
        return ans;
    }
};