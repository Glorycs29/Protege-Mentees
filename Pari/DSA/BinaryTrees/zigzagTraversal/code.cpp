//link -https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        //bfs-> level order traversal
        vector<vector<int>> ans;
        queue<TreeNode*> pendingnodes;
        pendingnodes.push(root);
        bool flag=true; 
        //true->left-right
        //false->right->left
        while(!pendingnodes.empty()){
            int n=pendingnodes.size();
            vector<int> temp_row(n);
            for(int i=0;i<n;i++){
                auto node=pendingnodes.front();
                pendingnodes.pop();
                if(node->left!= NULL) pendingnodes.push(node->left);
                if(node->right!= NULL) pendingnodes.push(node->right);

                if(flag){
                    temp_row[i]=node->val;
                }
                else{ //bool is false
                    temp_row[n-1-i]=node->val;
                }
            }
            ans.push_back(temp_row);
            flag=!flag;
        }
        return ans;
    }
};
