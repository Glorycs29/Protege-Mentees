//link https://www.geeksforgeeks.org/problems/number-of-islands/1  (GFG) MEDIUM
class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int num){
        parent.resize(num+1,0);
        size.resize(num+1);
        for(int i=0;i<=num;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findparent(int u){
        //base case
        if(parent[u]==u) return u;
        return parent[u]=findparent(parent[u]);
    }
    void unionBYsize(int u, int v){
        int ulp_u=findparent(u);
        int ulp_v=findparent(v);
      if(ulp_u==ulp_v) return; //means are of same component only
            if(size[ulp_u]>size[ulp_v]){
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
            else {
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
    }
};

class Solution {
    private:
    bool isValid(int row, int col , int n, int m){
        if(row>=n || col>=m || row<0 || col<0) return false;
        return true;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
  
        DisjointSet ds(n*m);
        
        int cnt=0;
        vector<int> ans_arr;
        vector<vector<int>> vis(n, vector<int> (m,0)); //0=not visited
        for(auto ele: operators){
            int row=ele[0];
            int col= ele[1];
            if(vis[row][col]==1) {
                ans_arr.push_back(cnt);
                continue;
            }
            vis[row][col]=1; //mark vis
            cnt++; ///for each element
            int num=m*row+ col;
            int delx[]={0,1,-1,0};
            int  dely[]={1,0,0,-1};
            //exploring the neighbours
            for(int a=0;a<4;a++){
                int adjr=delx[a]+row;
                int adjc=col+dely[a];
             if(isValid(adjr,adjc, n, m) && vis[adjr][adjc]==1 ){ //MISTAKE I MADE WAS I FORGOT TO CHECK IT SHOULD BE A LAND AS WELL
             
                 int adjele_n=m*adjr+ adjc;
                 int ulp_ele=ds.findparent(adjele_n);
                 int ulp_num=ds.findparent(num);
                 if(ulp_ele!=ulp_num){
                     cnt--; //merged components
                    ds.unionBYsize(adjele_n, num);
                   // ans_arr.push_back(cnt);
                    
                 }
                //  else{
                //     // ans_arr.push_back(cnt);
                //      continue;
                //  }
             }
            }
            ans_arr.push_back(cnt);
            
        }
        return ans_arr;
    }
};
