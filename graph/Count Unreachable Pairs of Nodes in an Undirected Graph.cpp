class Solution {
public:

    void dfs(vector<bool>&visited,unordered_map<int,vector<int>>&umap,long long &size,int node){
        visited[node]=true;
        size++;
        for(auto i:umap[node]){
            if(!visited[i]){
                dfs(visited,umap,size,i);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>umap;
        for(auto i:edges){
            umap[i[0]].push_back(i[1]);
            umap[i[1]].push_back(i[0]);
        }
        vector<bool>visited(n,false);
        long long result=0;
        int rem=n;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                long long size=0;
                dfs(visited,umap,size,i);
                result+=size*(rem-size);
                rem-=size;
            }
        }
        return result;
    }
};
