
class Solution {
public:
int m,n;
int t[71][71][71];
    int solve(vector<vector<int>>& grid,int row,int c1,int c2){
        if(row>=m){
            return 0;
        }
        if(t[row][c1][c2]!=-1){
            return t[row][c1][c2];
        }
        int cherry=grid[row][c1];
        if(c1!=c2){
            cherry+=grid[row][c2];
        }
        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int newRo
              
              w=row+1;
                int new_c1=c1+i;
                int new_c2=c2+j;
                if(new_c1>=0 &&new_c1<n && new_c2>=0 && new_c2<n){
                    ans=max(ans,solve(grid,newRow,new_c1,new_c2));
                }
            }
        }
        return t[row][c1][c2]=cherry+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        m=grid.size();
        n=grid[0].size();
        return solve(grid,0,0,n-1);
    }
};


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
          int m = grid.size();
        int n = grid[0].size();
        
        int t[71][71][71] = {0};

        t[0][0][n - 1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n - 1]; 
        
        for (int row = 1; row < m; row++) {
            for (int c1 = 0; c1 <= min(n-1, row); c1++) {      
                for (int c2 = max(0, n-1-row); c2 < n; c2++) { 
                    
                    int prev_max = 0;

                    for (int column1 = max(0, c1 - 1); column1 <= min(n - 1, c1 + 1); column1++) {
                        for (int column2 = max(0, c2 - 1); column2 <= min(n - 1, c2 + 1); column2++) {
                                prev_max = max(prev_max, t[row - 1][column1][column2]);
                        }
                    }
                    
                    if (c1 == c2)
                        t[row][c1][c2] = prev_max + grid[row][c1];
                    else
                        t[row][c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, t[m - 1][i][j]);    
            }
        }
        return res;
    }
};


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> prev(n, vector<int>(n));
        prev[0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1];
        
        for (int row = 1; row < m; row++) {

            vector<vector<int>> curr(n, vector<int>(n));

            for (int c1 = 0; c1 <= min(n-1, row); c1++) {      //min(n-1, row)   - Explained in video
                for (int c2 = max(0, n-1-row); c2 < n; c2++) { //max(0, n-1-row) - Explained in video
                    
                    int prev_max = 0;
                    //A Robot can come to current column from either column-1, column, or column+1 of prev row (row-1)
                    for (int column1 = max(0, c1 - 1); column1 <= min(n - 1, c1 + 1); column1++) {
                        for (int column2 = max(0, c2 - 1); column2 <= min(n - 1, c2 + 1); column2++) {
                                prev_max = max(prev_max, prev[column1][column2]);
                        }
                    }
                    
                    if (c1 == c2)
                        curr[c1][c2] = prev_max + grid[row][c1];
                    else
                        curr[c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
                }
            }
            prev = curr;
        }
        
        int res = 0;
        //return max in last row 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, prev[i][j]);    
            }
        }
        return res;
    }
};

