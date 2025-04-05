//QLink-> https://leetcode.com/problems/find-eventual-safe-states/
class Solution {
public:
    bool dfs(int node, vector<vector<int> >& adj, vector<int>& vis,vector<int> &pathvis,vector<int> &safe  ){
        vis[node]=1;
        pathvis[node]=1; //THIS PAth visited
        for(auto it: adj[node]){
            if(vis[it]==0){
               if(  dfs(it, adj, vis, pathvis, safe)==true){
                safe[node]=-1;
                //important left TO WRITE THIS
                return true;
               } 
        }
        else if(pathvis[it]==1){ //cycle detected so mark it
            safe[node]=-1;
            return true;
        
        }
    }
    pathvis[node]=0;  //it is not currently being used in the path
    return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> safe(n,0 );  //right now all are safe
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathvis, safe);
            }
           
        }
        //add the elements from safe(0) to the ans array to be returned
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(safe[i]==0) ans.push_back(i);
        }
        return ans;
    }
};
