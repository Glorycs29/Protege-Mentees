//link- https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<int > distance(n, INT_MAX);
      distance[src]=0;
       for(int i =0;i<k+1;i++){
        vector<int> copy=distance;
        for( auto a: flights){

            int from=a[0];
            int to=a[1];
            int price=a[2];
            if(distance[from]!=INT_MAX && distance[from]+ price<copy[to]){
                copy[to]=price+distance[from];
            }
        }
        distance= copy;
       } 
       if(distance[dst]==INT_MAX) return -1;
    return distance[dst];
    }
};
