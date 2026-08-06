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
    int diameterOfBinaryTree(TreeNode* root) {
        int Diameter=0;
        height(root,Diameter);
        return Diameter;

    }

    private: 

    int height(TreeNode* node,int& Diameter){
        if(!node){
            return 0;
        }

        int lh=height(node->left,Diameter);
        int rh=height(node->right,Diameter);
        Diameter=max(Diameter,lh+rh);
        return 1+max(lh,rh);
    }
};