//link- https://www.naukri.com/code360/problems/longest-common-substring_1214702?leftPanelTabValue=PROBLEM

int LCSubStr(string &str1, string &str2)
{
    //tabulation to solve it
    vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1, 0) );
    //AS WE DO SHIFTING SO size of dp will be from 0 to arr.size()+1 to store values till n-1 th index of array
    int n=str1.size(), m=str2.size();
      //base case
  for(int i =0;i<n;i++){
        dp[i][0]=0; //basically for( if j<0 wala base case)
    }
    for(int j=0;j<m;j++){
        dp[0][j]=0;
    }
    int maxi=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
               dp[i][j]= dp[i-1][j-1]+1;
               maxi=max(maxi, dp[i][j] ); //TAKING MAX VALUE
            }
            else{dp[i][j]=0; //characters dont match
            } 
        }
    }
    
 return maxi;
}

