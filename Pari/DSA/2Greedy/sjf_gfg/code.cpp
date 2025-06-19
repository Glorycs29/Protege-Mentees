//Link= https://www.geeksforgeeks.org/problems/shortest-job-first/1
  //earlier took an array but can be done without array
class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n=bt.size();
        sort(bt.begin(),bt.end());
        //vector<int> arr;
        int t=0,waitingt=0;
     
        for(int i=0;i<n;i++){
           // int waitingtime=arr.back()+bt[i];
         //  arr.push_back(waitingtime); //arr.back()+
         waitingt+=t;
         t+=bt[i];
        } 
        return waitingt/n;
    }
};
