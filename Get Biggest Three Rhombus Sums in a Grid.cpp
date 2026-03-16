class Solution {
public:
     vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        set<int, greater<int>> res;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                res.insert(grid[i][j]); 

                for(int k=1; i-k>=0 && i+k<n && j-k>=0 && j+k<m; k++){

                    int sum = 0;

                    int r=i-k, c=j;

                    
                    for(int t=0;t<k;t++)
                        sum+=grid[r+t][c+t];

                   
                    for(int t=0;t<k;t++)
                        sum+=grid[r+k+t][c+k-t];

                   
                    for(int t=0;t<k;t++)
                        sum+=grid[r+2*k-t][c-t];

                    
                    for(int t=0;t<k;t++)
                        sum+=grid[r+k-t][c-k+t];

                    res.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(auto x:res){
            ans.push_back(x);
            if(ans.size()==3) break;
        }

        return ans;
    }
};
