class Solution {
public:
bool dfs(int node , vector<vector<int>>& adj, vector<int > &visited,  vector<int >& Pathvisited ){
        visited[node]=1;
        Pathvisited[node]=1;
        for(auto nei: adj[node]){
            if(!visited[nei]){
                if(dfs(nei, adj, visited, Pathvisited)==false) return false;
            }
            else if(Pathvisited[nei]){
                Pathvisited[nei]=0;
                return false;
            }
        }
        Pathvisited[node]=0; // this path is completed
        return true;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //1 basically detect if there is any cycle or not
        //2 the edge is directed or not

        vector<vector<int>> adj(numCourses);
        for(auto edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }

        //Declaring visited array
        vector<int > visited(numCourses);
        vector<int > Pathvisited(numCourses);
        for(int i=0;i<numCourses ;i++){
            if(!visited[i]) {
                if(dfs(i, adj, visited, Pathvisited)== false )
                 return false;  //basically the function told that there is a cycle or an undirected edge
            }
        }
        return true;
    }
};
