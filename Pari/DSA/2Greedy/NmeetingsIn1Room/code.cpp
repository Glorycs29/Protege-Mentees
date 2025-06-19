//link https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
class Solution {
  public:
      static bool comp(pair<int, int>a, pair<int, int> b){ //so that can use without making obj
        return a.second<b.second;
    }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> p;
        for(int i=0;i<end.size();i++){
            p.push_back({start[i], end[i]});
        }
        sort(p.begin(), p.end(), comp);
        int n=p.size();
        int cnt=1;
        int lastend=p[0].second ;
       for(int i=1;i<n;i++){
           if(p[i].first >lastend){
               cnt++;
               lastend=p[i].second;
           }
       }
       return cnt;
    }
};
