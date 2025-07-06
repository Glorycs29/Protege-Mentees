//link- https://leetcode.com/problems/distinct-subsequences/description/
//hard but easy intuition
class Solution {
public:
    int f(int i, int j, string s,string t, vector<vector<int>>&dp){
        //base case

        if(j<0) return 1; //s2 exhausted means all well
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        //IF MATCHED
        if(s[i]==t[j]){
            return dp[i][j]=f(i-1,j-1,s,t,dp)+ f(i-1, j ,s,t,dp);
        }
        else{ //not matched so go back/next in s1
            return dp[i][j]=f(i-1,j,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(s.size(),vector<int> (t.size(), -1));
        return f(n-1, m-1, s,t,dp);
    }
};
