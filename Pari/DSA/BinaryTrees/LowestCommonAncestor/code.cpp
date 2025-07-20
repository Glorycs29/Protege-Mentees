//link- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       //base case
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        //inshort if(root==NULL || root==q || root==p ) return root;
        TreeNode* left=lowestCommonAncestor(root->left, p,q);
        TreeNode* right=lowestCommonAncestor(root->right, p,q);

        if(left && right) return root; //WE found our result as left and right- arent null
        else if(left ) return left;
        return right;
    }
};
