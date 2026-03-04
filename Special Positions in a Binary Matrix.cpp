class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<vector<int>>temp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    temp.push_back({i,j});
                }
            }
        }

        int res=0;
        for(auto t:temp){
            int count=0;
            int row=t[0];
            int col=t[1];
            for(int i=0;i<m;i++){
                
                if(mat[row][i]==1){
                    count++;
                }
            }
            if(count==0 || count>1){
                continue;
            }
            count=0;
            for(int i=0;i<n;i++){
                
                if(mat[i][col]==1){
                    count++;
                }
            }
            if(count==0 || count>1){
                continue;
            }
            res++;
        }
        return res;
    }
};
