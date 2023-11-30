class Solution {
public:

    bool canPlace(vector<vector<int>>board,int i,int j,int n){
        for(int k=0;k<i;k++){
            if(board[k][j]==1){
                return false;
            }
        }

        int x=i;
        int y=j;
        while(x>=0 &&y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        x=i;
        y=j;
        while(x>=0 && y<n){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y++;
        }
        return true;
    }
    int nqueen(vector<vector<int>>board,int i,int n){
        if(i==n){
            return 1;
        }
        int ways=0;
        for(int j=0;j<n;j++){
            
            if(canPlace(board,i,j,n)){
                board[i][j]=1;
                ways+=nqueen(board,i+1,n);
                board[i][j]=0;
            }
        }
        return ways;
    }
    int totalNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        return nqueen(board,0,n);
    }
};
