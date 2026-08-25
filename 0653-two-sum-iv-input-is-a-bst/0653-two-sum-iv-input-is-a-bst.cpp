class BSTIterator{
    stack<TreeNode*> st;
    bool right;
    void push(TreeNode* root){
        while(root){
            st.push(root);
            if(!right){
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
    }
    public:
    BSTIterator(TreeNode* root,bool right=false){
        this->right=right;
        push(root);
    }
    int next(){
        int ans=st.top()->val;
        TreeNode* root=st.top();
        st.pop();
        if(!right){
            push(root->right);
        }
        else{
            push(root->left);
        }
        return ans;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root);
        BSTIterator r(root,1);
        int nodel=l.next();
        int noder=r.next();
        while(nodel<noder){
            int sum=nodel+noder;
            if(sum==k)
                return true;
            if(sum>k){
                noder=r.next();
            }
            else{
                nodel=l.next();
            }
        }
        return false;
    }
};