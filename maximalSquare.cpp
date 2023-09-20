class Solution {
public:
    // int solve(vector<vector<char>>& matrix,int i,int j,int &maxi){
    //     if(i>=matrix.size()||j>=matrix[0].size()){
    //         return 0;
    //     }
    //     int right=solve(matrix,i,j+1,maxi);
    //     int diagonal=solve(matrix,i+1,j+1,maxi);
    //     int down=solve(matrix,i+1,j,maxi);
        
    //     if(matrix[i][j]=='1'){
    //         int ans=1+min(right,min(diagonal,down));
    //         maxi=max(ans,maxi);
    //         return ans;
    //     }
    //     else{
    //         return 0;
    //     }
    // }

    // int solve(vector<vector<char>>& matrix,int i,int j,int &maxi,vector<vector<int>>&dp){
    //     if(i>=matrix.size()||j>=matrix[0].size()){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int right=solve(matrix,i,j+1,maxi,dp);
    //     int diagonal=solve(matrix,i+1,j+1,maxi,dp);
    //     int down=solve(matrix,i+1,j,maxi,dp);
        
    //     if(matrix[i][j]=='1'){
    //         dp[i][j]=1+min(right,min(diagonal,down));
    //         maxi=max(dp[i][j],maxi);
    //         return dp[i][j];
    //     }
    //     else{
    //         return dp[i][j]=0;
    //     }
    // }

    //  int solve(vector<vector<char>>& matrix,int &maxi){
    //     int row=matrix.size();
    //     int col=matrix[0].size();
    //     vector<vector<int>>dp(row+1,vector<int>(col+1,0));
    //     for(int i=row-1;i>=0;i--){
    //         for(int j=col-1;j>=0;j--){
    //             int right=dp[i][j+1];
    //             int diagonal=dp[i+1][j+1];
    //             int down=dp[i+1][j];
        
    //          if(matrix[i][j]=='1'){
    //                  dp[i][j]=1+min(right,min(diagonal,down));
    //                  maxi=max(dp[i][j],maxi);
            
    //              }
    //              else{
    //                  dp[i][j]=0;
    //              }
    //          }
    //     }
    //     return dp[0][0];
        
    // }

    int solve(vector<vector<char>>& matrix,int &maxi){
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>curr(col+1,0);
        vector<int>next(col+1,0);
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int right=curr[j+1];
                int diagonal=next[j+1];
                int down=next[j];
        
        if(matrix[i][j]=='1'){
            curr[j]=1+min(right,min(diagonal,down));
            maxi=max(curr[j],maxi);
            
        }
        else{
            curr[j]=0;
        }
        }
        next=curr;
        }
        return next[0];
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        solve(matrix,maxi);
        return maxi*maxi;
    }
};
