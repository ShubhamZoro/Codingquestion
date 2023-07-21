class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid){
        int n=grid[0].size();
        int m=grid.size();
        if(i>=0 && j>=0 && i<m && j<n && grid[i][j]=='1'){
            
                grid[i][j]='0';
                dfs(i,j-1,grid);
                dfs(i,j+1,grid);
                dfs(i-1,j,grid);
                dfs(i+1,j,grid);
           
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int num=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    num++;
                    dfs(i,j,grid);
                }
            }
        }
        return num;
    }
};
