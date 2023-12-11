class Solution {
public:
    void dfs(vector<int>&visited,unordered_map<int,vector<int>>umap,int src){
        visited[src]=1;
        for(auto &i:umap[src]){
            if(!visited[i]){
                dfs(visited,umap,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>>umap;
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(i!=j && isConnected[i][j]==1){
                    umap[i].push_back(j);
                }
            }
        }
        vector<int>visited(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                sum++;
                dfs(visited,umap,i);
            }
        }
        return sum;
    }
};
