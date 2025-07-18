//link-https://leetcode.com/problems/symmetric-tree/
class Solution {
public:
bool helper(TreeNode* l, TreeNode* r){
    if(l==NULL && r==NULL) return true; 
    else if(l==NULL || r==NULL) return false; //if(l==NULL || r==NULL) return l==r;
    if(l->val!=r->val) return false; 
    return helper(l->right, r->left)
      &&  
      helper(r->right, l->left); //both node's left and right should be equal to right nd left of the other one
     //simultaneously calling both left and right of both sides
} 
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};
