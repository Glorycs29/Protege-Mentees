//link= https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        //LEVEL order traversal
        queue<pair<Node*,int>> q;
        map<int, int> mymap;
        q.push({root,0});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            Node* node=curr.first;
            int level=curr.second;
            mymap[level]=node->data;  //updating the data at each level with the latest value at bottom
            if(node->left) q.push({node->left, level-1});
            if(node->right) q.push({node->right, level+1});
        }
        vector<int> ans;
        for (auto it: mymap){
            ans.push_back(it.second);
        }   
        return ans;
    }
};
