class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>row_zero;
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]==0){
                    count++;
                }
                else{
                    break;
                }

            }
            row_zero.push_back(count);
        }
        int steps=0;
        for(int i=0;i<n;i++){
            int need=n-i-1;
            int j=i;
            while(j<n&&row_zero[j]<need){
                j++;
            }
            if(j==n){
                return -1;
            }
            steps+=j-i;
            while(j>i){
                swap(row_zero[j],row_zero[j-1]);
                j--;
            }
        }
return steps;
    }
};
