//QLINK-> https://leetcode.com/problems/number-of-enclaves/ 
//JUST DFS ON  BOOUNDARIES 
class Solution {
public:
    void dfs(int r, int c, vector<vector<int> >& grid ,  vector<vector<int>> &vis){
        vis[r][c]=1;

        int n=grid.size();
        int m=grid[0].size();
        int delta[]={1,0,-1,0,1};
        for(int i=0;i<4;i++){
            int nrow=r+delta[i];
            int ncol=c+delta[i+1];
            if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && vis[nrow][ncol]!=1 && grid[nrow][ncol]==1){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
      
        int n =grid.size();
        int m =grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 )
                dfs(i, 0, grid,  vis);
            if(grid[i][m-1]==1){
                   dfs(i, m-1, grid,vis);
            }
        }
        for(int i=1;i<m-1;i++){
          if(grid[0][i]==1 )
                dfs(0, i, grid, vis);
            if(grid[n-1][i]==1){
                   dfs(n-1, i, grid, vis);
            }
        }
        //counting the no of unvisited 1s:)
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0 ) ans++;
            }
        }
        return ans;
           
    }
};
