class Solution {
public:
    int helper(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1&&j==n-1){
            return 1;

        }
        if(i>=m||j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else{
            return dp[i][j]= helper(i+1,j,m,n,dp)+helper(i,j+1,m,n,dp);
        }
        
    }
    int uniquePaths(int m, int n) {
        // vector<int>row(n,1);
        // for(int i=0;i<m-1;i++){
        //     vector<int>newrows(n,1);
        //     for(int j=n-2;j>=0;j--){
        //         newrows[j]=newrows[j+1]+row[j];
        //     }
        //     row=newrows;
        // }
        // return row[0];

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,m,n,dp);

        // int N=n+m-2;
        // int r=m-1;
        // double res=1;
        // for(int i=1;i<=r;i++){
        //     res=res*(N-r+i)/i;
        // }
        // return (int)res;
    }
};
