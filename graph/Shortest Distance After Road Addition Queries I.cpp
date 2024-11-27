class Solution {
public:

   void solve(unordered_map<int, vector<int>> &umap, int &path, int n) {
    queue<int> q;
    vector<int> result(n, INT_MAX);
    q.push(0);
    result[0] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : umap[node]) {
            if (result[neighbor] > result[node] + 1) {
                result[neighbor] = result[node] + 1;
                q.push(neighbor);
            }
        }
    }

    path = (result[n - 1] == INT_MAX) ? -1 : result[n - 1]; 
}

    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>umap;
        for(int i=0;i<n-1;i++){
            umap[i].push_back(i+1);

        }
        vector<int>res(queries.size(),0);
        int k=0;
        for(auto i:queries){
            int path=INT_MAX;
            umap[i[0]].push_back(i[1]);
            solve(umap,path,n);
            res[k]=path;
            k++;
        }
        return res;
    }
};
