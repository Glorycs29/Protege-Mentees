// LINK-> https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card


//MOST OPTIMAL
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
 
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
       vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),0));
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>> vis(n, vector<int>(m,0));
        //queue< pair< pair<int, int>,int>> q; 
        //queue< pair<pair<int, int>, int> > q;  // Correct

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
       // bfs(); dont define it (make it in the main fnc only)
        while(!q.empty()){
            int r=q.front().first.first;
            int c= q.front().first.second;
            int dist=q.front().second;
            q.pop();
            ans[r][c]=dist;
            int delx[]={0,-1,0,1};
            int dely[]={1,0,-1,0};
             for(int i=0;i<4;i++){
                 int nr=r+delx[i];
                 int nc=c+ dely[i];
                 if(nr<n && nr>=0 && nc>=0 && nc<m && vis[nr][nc]!=1 && grid[nr][nc]==0 )
                 {   q.push({{nr,nc},dist+1});
                    vis[nr][nc]=1;
                 }
             }
        }
        
        return ans;
        
        
        
        
       
    }
};
