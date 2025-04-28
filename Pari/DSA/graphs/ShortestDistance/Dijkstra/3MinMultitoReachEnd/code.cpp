class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {  
        
    vector<int> distance_stops(1e5, 1e9);
    distance_stops[start]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 //queue<pair<int, int> > pq;
    pq.push({0, start});
   
while(!pq.empty()){
    auto fron= pq.top();
     pq.pop();
    int currStops= fron.first;
    int from=fron .second;
    
    if(end==from) return currStops;
    for(auto a: arr){
        int to =(a* from) % (int)1e5;
        // if(to>=1e5)
        //     to%=(int) 1e5;
        if(distance_stops[to]>currStops+1){
            pq.push({currStops+1, to});
            distance_stops[to]=currStops+1;
        }
    }
}
return -1; 
    }
};
