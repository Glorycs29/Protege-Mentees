//Leetcode-> https://leetcode.com/problems/making-a-large-island/
class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i =0;i<n;i++){
            parent[i]=i;
        }
    }
    int findpar(int i){
        if(parent[i]==i) return i;
        return parent[i]=findpar(parent[i]);
    }
    void unions(int u , int v){
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);
        if(ulp_u==ulp_v) return; //not continue
        else if(size[ulp_u]> size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];

        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};


class Solution {
public:
    bool isValid(int i, int j, int n , int m){ 
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;
    }
    int largestIsland(vector<vector<int>>& grid) {

         //1 connect already given components
         int n=grid.size();
         int m=grid[0].size();
         DisjointSet ds(n*m);
         for( int i=0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j]==1){
                    int num=i*m+j;
                    //iterate the 4 neighours
                    int del[]={1,0,-1,0,1};
                    for(int a=0;a<4;a++){
                        int adjr=i+del[a];
                        int adjc=j+ del[a+1];
                        if(isValid(adjr, adjc, n, m)==true && grid[adjr][adjc]==1){ //then combine the components
                            int nei=m*adjr+adjc;
                            ds.unions(nei, num);
                        }
                    }
                }
            }
         }
         int maxans=0;
// maximum size of island rn=
for(auto i: ds.size){
maxans=max(maxans, i);
}


//2 check the 0s =MAIN PART OF THE Q
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            if(grid[i][j]==0){
                int num=i*m+j;
                //iterate the 4 neighbours
                int del[]={1,0,-1,0,1};

                 int newsize=1;
                 unordered_set<int> ulp_parents;
                for(int a=0;a<4;a++){
                    int adjr=i+del[a];
                    int adjc=j+del[a+1]; //not del[a] -> was giving wrong ans
                    int neighbour=m* adjr+ adjc;
                  
                    if(isValid(adjr,adjc,n, m)==true && grid[adjr][adjc]==1 ){
                        //if(ds.findpar(neighbour)==)
                          int par=ds.findpar(neighbour);
                         if ( ulp_parents.find(par)==ulp_parents.end()){
                            newsize+=ds.size[par]; //increase the size of component by size of neighbour component
                            ulp_parents.insert(par);
                         }
                      
                    }
                }
                 maxans=max(newsize, maxans);
            }
        }
    }
    return maxans;
    }
};



//MISTAKES 1)WAS THINKIN UNION N THEN DISCONNECT(Which doesnt exist) InSTEAD OF JUST SUMMING UP THE SIZES
//2) while summing up -> didnt check if any of the neighbours have same Ult_parent (belong to same component) 
//3) for (2) use unordered_set to store ult_parent of the neighbours and check if they r same




