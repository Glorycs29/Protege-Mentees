// lc q link->https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                 else{
                    vis[i][j]=0;
                }
            }
        }
            int delrow[]= {  0,1,0,-1};
            int delcol[]={1,0,-1,0};
            int tm=0;
        while(!q.empty()){
            int r =q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm= max(tm,t);
            q.pop();
            
            
            for(int i=0;i<4;i++){
                int row=r+delrow[i];
                int col=c+delcol[i];
                if(row>=0&& row<m&& col>=0 && col<n && vis[row][col]!=2 && grid[row][col]==1){
                    q.push({{row,col},t+1});
                    vis[row][col]=2;

                }
               
            }
        
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]!=0) return -1;
            }
        }
   return tm;
    }
};
