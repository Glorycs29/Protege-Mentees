//LINK ->https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
//G-36
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
   
        int n=grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        // vector<int> x={0,1,-1,1,0,-1,-1,-1}; //-error was that i was using wrong direction arrays
        // vector<int> y={-1, -1,0,1,1,1,0,-1};
        vector<int> x = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> y = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<pair<int, pair<int,int>>>q;
        q.push({1,{0,0}});

        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
dist[0][0]=1;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int i= it.second.first;
            int j=it.second.second;

             if (i == n-1 && j == n-1) return dist[i][j];

            for(int k=0;k<8;k++){
                int nodei=i+x[k];
                int nodej=j+y[k];


                if(nodei>=0 && nodei<n && nodej>=0 && nodej<n && grid[nodei][nodej]==0) //not out of bounds and ==0
                {
                    if(dist[nodei][nodej]>  d + 1){
                        q.push({d+1, {nodei , nodej}});
                        dist[nodei][nodej]=d+1;
                    }
                    //if(nodei==n-1 && nodej==n-1) //destination reached
                    //    return dist[nodei][nodej];
                }
            }
        }
       return -1;
    }
};
