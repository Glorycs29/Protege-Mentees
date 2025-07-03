//link- https://www.naukri.com/code360/problems/can-you-make_4244510?leftPanelTabValue=PROBLEM
//atoZ
int lcs_rec(int i, int j, string a, string b, vector<vector<int>>& dp){
    if(i<0 || j<0 )
    {
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]) return dp[i][j]= 1+lcs_rec(i-1, j-1 ,a,b,dp);
    else{
        return  dp[i][j]=max(lcs_rec(i-1, j, a,b,dp), lcs_rec(i,j-1, a,b,dp));
    }
return -1;
}
int canYouMake(string &s1, string &s2){
   
    //CAn remove/add characters only in s1
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

int ans=n+m- 2*(lcs_rec(n-1,m-1, s1,s2,dp));
 // we will not touch the common characters (for operations) from both and hence all will be removed from total operations
return ans;
}
