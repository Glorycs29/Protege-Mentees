//link-  https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //create graph
        vector<vector<pair<int,int>>> arr(n);
        for( auto i: flights){
            int from=i[0];
            int to=i[1];
            int w=i[2];
            arr[from].push_back({to, w});

        }
        vector<int> distance(n, 1e9);


        //DONT KEEP SRC AS 0 
        distance[src]=0;
       // priority_queue<<pair<pair<int, int>> pq; //priority queue 
       queue<pair<pair<int,int>, int>> q;
        q.push({{0, src}, 0});
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int stops =it.first.first;
            int node = it.first.second;
            int cost=it.second;
            if(stops>k) continue;
        //    if(node == dst) return 
            for(auto nei: arr[node]){
                int to =nei.first;
                int weight= nei.second;
                if( weight+ cost<=distance[to] &&  stops<=k+1){
                        distance[to]=weight+ cost;
                        q.push({{ stops+1, to },distance[to]});
                }
            }
        }
        if(distance[dst] == 1e9) return -1;
        else return distance [dst];
    }
};
