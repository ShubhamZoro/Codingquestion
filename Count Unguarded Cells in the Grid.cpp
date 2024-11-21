class Solution {
public:

    void solve(int row,int col,vector<vector<int>>&res){
        for(int i=row-1;i>=0;i--){
            if(res[i][col]==2||res[i][col]==3){
                break;
            }
            res[i][col]=1;
        }
        for(int i=row+1;i<res.size();i++){
            if(res[i][col]==2||res[i][col]==3){
                break;
            }
            res[i][col]=1;
        }

        for(int i=col-1;i>=0;i--){
            if(res[row][i]==2||res[row][i]==3){
                break;
            }
            res[row][i]=1;
        }
         for(int i=col+1;i<res[0].size();i++){
            if(res[row][i]==2||res[row][i]==3){
                break;
            }
            res[row][i]=1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>res(m,vector<int>(n,0));
        for(auto g:guards){
            int i=g[0];
            int j=g[1];
            res[i][j]=2;
        }

        for(auto w:walls){
            int i=w[0];
            int j=w[1];
            res[i][j]=3;
        }
        
        for(auto g:guards){
            int i=g[0];
            int j=g[1];
            solve(i,j,res);
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(res[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};
