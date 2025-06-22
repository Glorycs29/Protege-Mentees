//link- https://leetcode.com/problems/swim-in-rising-water/
class DSU{
      vector<int> size,parent;
    public:
    DSU(int n){
        size.resize(n,1);
        parent.resize(n); //important to change parent's values
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
  
    int findpar(int a){
        if(parent[a]==a) return a;
        return parent[a]=findpar(parent[a]);

    }
    void unionbysize(int u, int v){
        int ult_u=findpar(u);
        int ult_v=findpar(v);
        if(ult_u==ult_v) return ;
        if(size[ult_u]>size[ult_v]){
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
        else{
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
    }
};
//INTUITION -connect using kruskal
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //2d array to 1d
        vector<int> positions;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                positions.push_back(i*n+j);
            }
        }
            sort(positions.begin(), positions.end(),[&](int a, int b){
                return grid[a/n][a%n] < grid[b/n][b%n];
            });
    //after soritng based on grid's value

        DSU dsu(n*n);
        //kruskal's as making a kinda mst for going from 0,0 to n-1, n-1
        for(auto edge: positions){
            int row=edge/n;
            int col=edge%n;
            vector<int> delta={0,1,0,-1,0};
            //based on condition do union with adjacet squares
            for(int i=0;i<4;i++){
                int nr=row+delta[i];
                int nc=col+delta[i+1];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] <grid[row][col]){
                    dsu.unionbysize(edge, nr*n+nc);
                }
            }
            if(dsu.findpar(0)==dsu.findpar(n*n-1)){
                //all edges of minimum time to n-1,n-1 joined ence return the current cell val
                return grid[row][col];
            }
        }
        return -1;
    }
};
