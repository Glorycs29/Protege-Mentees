//Q -> https://leetcode.com/problems/surrounded-regions/
//Surrounded Regions | Replace O's with X's  G-14
class Solution {
public:

//THE ONLY TRICk is to apply dfs on the corner elements (WHICH ARE o ) as only the elements connected to them are to NOT TO BE CONVERTED TO X AND REST WILL FALL IN PLACE

    void dfs(int row, int col, vector<vector<char>>& board,vector<vector<char>>&ans , int n ,int m,vector<vector<int>>&vis){ 
        vis[row][col]=1;
        ans[row][col]='O';
        //traversing its 4 neighbours
        int change[]={1,0,-1,0,1};
        for(int i=0;i<4;i++){
            int nrow=row+change[i];
            int ncol=col+change[i+1]; //dont forget to increment it by 1
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                dfs(nrow, ncol , board, ans, n,m ,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<char>>ans(n, vector<char>(m,'X'));

        //IMPORTANT TO ADD VISITED ARRAY FOR AVOIIDING STACK OVERFLOW, otherwise gave stack overflow on the 3rd tc itself
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                 dfs(i,0, board, ans, n,m, vis); //i==i j==0
            }
           if(board[i][m-1]=='O'){
                 dfs(i,m-1, board, ans , n, m,vis);
            }
          
        }
        for(int i=1;i<m-1;i++){
            if(board[0][i]=='O')
                 dfs(0,i, board, ans, n,m,vis); //i==i j==0
            if(board[n-1][i]=='O') 
                dfs(n-1,i, board , ans,n, m, vis);
        }
        board=ans; //as void is the return type
    }
};
