//problem link-> https://www.naukri.com/code360/problems/distinct-islands_630460
//INTUTION

#include <vector>
void dfs(int r, int c, int**arr, vector<vector<int>> & vis,vector<int> &ans, int base_r, int base_c){
   
    vis[r][c]=1;    
    ans.push_back({r-base_r, c-base_c});

    int delx={0,1,0,-1  };
    int dely={1,0,-1,0}; 
    for(int i=0;i<4;i++) { //4 sides of the block me dfs for identifying the pattern
    int nrow=r+delx[i];
    int ncol=c+dely[i];
    if(nrow>=0 && ncol>=0 && ncol<arr[0].size() && nrow<arr.size() && vis[nrow][ncol]!=1 && arr[nrow][ncol]==1 )
dfs(r+nrow, c+ncol,arr, vis, ans, base_r, base_c ) ;
    }
}
int distinctIslands(int** arr, int n, int m)
{
    vector<vector<int>> vis(n,vector<in>(m,0));

//vector<vector<int>> ans(n,vector<int> (m));
set<vector<pair<int,int>>>sett;

    int n =arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]!=1 && arr[i][j]==1){
                vector<pair<int,int>> ans;
               dfs(i, j ,arr,vis,ans, i, j);  //first one is base ones and the 2nd ones r real ones
               sett.insert(ans);
            }
        }
    }
    return sett.size();
}
