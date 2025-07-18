//link https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/0
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        queue<pair<Node*,int>>q; //node and vertical level
        map<int, int>mp;
        q.push({root,0});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            Node* node=curr.first;
            int level=curr.second;
            if(mp.find(level)==mp.end()){
                mp[level]=node->data;
            }
            if(node->left!=NULL) q.push({node->left, level-1});
            if(node->right!=NULL) q.push({node->right, level+1});
        }
        vector<int> ans;
        for(auto a: mp){
            ans.push_back(a.second);
        }
        return ans;
    }
};
