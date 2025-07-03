//link https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
class Solution {
public:
//easy if lps,lcs is clear
    int lcpSubseq(int i, int j ,string pehli, string doosri, vector<vector<int>>& dp){
        //tabulation // can be done with memo too as 
        //base case
        for(int a=0;a<=pehli.size();a++){
            dp[a][0]=0;
            dp[0][a]=0;
        }
        for(int a=1;a<=pehli.size();a++){
            for(int b=1;b<=pehli.size();b++){ //dont forget <= as we have done shifting
                if(pehli[a-1]==doosri[b-1]){
                    dp[a][b]=1+dp[a-1][b-1];

                }
                else{
                    dp[a][b]=max(dp[a-1][b], dp[a][b-1]);
                }
            }
        }
        int n=pehli.size();
        return dp[n][n]; //length of longest common subsequence of str and its rev-> which is automatically palindromic as is common in both revstr and str
    }
    int minInsertions(string s) {
        string rev=s;
       reverse(s.begin(), s.end());
       if(rev==s) return 0;
        int n=s.size();
       //ans=n- length of longest common subsequence which is palindrome
       vector<vector<int>>dp(n+1, vector<int> (n+1,0));
        int llcps=lcpSubseq(0,0,s, rev, dp);
        int ans=n-llcps;
        return ans;
    }
};
