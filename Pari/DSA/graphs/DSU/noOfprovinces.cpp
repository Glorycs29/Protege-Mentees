//link  https://www.geeksforgeeks.org/problems/number-of-provinces/1
class Disjointset{
  vector<int> parent, rank;
  public:
  Disjointset(int n){
      parent.resize(n+1);
      rank.resize(n+1);
      for(int i=0;i<n;i++){
          parent[i]=i;
          rank[i]=0;
      }
  }
  int findPar(int u){
      if(u==parent[u] )return u;
      return parent[u]=findPar(parent[u]);
  }
  void unionBYrank(int u , int v){
      int ulp_u=findPar(u);
      int ulp_v=findPar(v);
      if(ulp_u==ulp_v) return;
      if(rank[ulp_u]> rank[ulp_v]){
          parent[ulp_v]= ulp_u;
          //rank[ulp_u]
      }
      else if(rank[ulp_v]> rank[ulp_u]){
          parent[ulp_u]=ulp_v;
      }
      else{
          parent[ulp_u]=ulp_v;
          rank[ulp_v]++;
      }
  }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int cnt=V;
       // vector<pair<int, int> edges(V+1);
        Disjointset ds(V);
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){ //j=0 or optimisation j=i+1
              
                if(adj[i][j]==1 && i!=j){
                    //edges.push_back(i, j);
                    if(ds.findPar(i)!=ds.findPar(j)){
                        cnt--;
                        ds.unionBYrank(i,j);
                    }
                }

            }
        }
        return cnt;
    }
};

//OPTIMISATION
// to avoid visiting same cells, sTART with j=i+1
