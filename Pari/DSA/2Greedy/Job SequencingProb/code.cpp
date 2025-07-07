//https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
class Solution {
  public:
bool static comp(pair<int,int>a , pair<int,int>b){
        return a.first>b.first;
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
     
         int n=profit.size();
         vector<pair<int,int>> arr(n);
        
        for(int i=0;i<n;i++){
            arr[i]={profit[i], deadline[i]};
        }
        sort(arr.begin(), arr.end() , comp);
        int maxprofit=0;
        int cnt=0;
        int maxdead=0;
        for(int i=0;i<n;i++){
            maxdead=max(maxdead, deadline[i]);
        }
        vector<int> vis(maxdead+1, 0);
        
        for(int i=0;i<n;i++){
            int start=min(n, arr[i].second);
            for(int j=start;j>0;j--){
              if(vis[j]==0) //empty( not used this slot hence job with the max possible profit placed
            {
                vis[j]=1;
                cnt++;
                maxprofit+=arr[i].first;
                break;
            } 
            }
        }
        return {cnt, maxprofit};
    }
};
