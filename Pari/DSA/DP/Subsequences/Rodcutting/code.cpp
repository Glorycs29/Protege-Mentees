//link=https://www.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution {
  public:
    int f(int ind, int n, vector<int> & price){
        //base case
        if(ind==0){
            if(n==0) return 0;
            //else if(ind+1== n) return price[ind]; WRONG THINK OF CORRECT BASE CASE
            if(n%(ind+1)==0) return n/(ind+1)*(price[0]); //that many times the arr[0] would be taken
            return INT_MIN;
        }
        if(ind<0 ) return INT_MIN;
        if(n==0 )return 0;
        
        int nonpick=f(ind-1, n,price);
        int pick=INT_MIN;
        if(n>=ind+1) {
           pick= price[ind]+f(ind,n-ind-1, price); //as can cut the rod any no of times of same size
        }
        return max(pick,nonpick);
    }
    int cutRod(vector<int> &price) {
        int n=price.size();
      //  return f(n-1, n,price );
      
      //TABULATION
      vector<vector<int>> dp(n, vector<int> (n+1,0));
      //base case= FILLING 1ST ROW TARGET VALS
      for(int i=1;i<=n;i++){ 
         // if(i%(i+1)==0) 
          dp[0][i]= price[0]*(i);
        //  else dp[0][i]=INT_MIN;
      }
      dp[0][0]=0;
      for(int ind=1;ind<n;ind++){
          for(int tar=0;tar<=n;tar++){
               int nonpick=dp[ind-1][tar];
                int pick=INT_MIN;
                if(tar>=ind+1) {
                    pick= price[ind]+dp[ind][tar-ind-1]; //as can cut the rod any no of times of same size
             }
             dp[ind][tar]=max(pick,nonpick);
          }
      }
     return dp[n-1][n];
    }
};
