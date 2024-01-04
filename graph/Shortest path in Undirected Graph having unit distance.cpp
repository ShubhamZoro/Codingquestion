//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>result(N,INT_MAX);
        vector<int>visited(N,0);
        unordered_map<int,vector<pair<int,int>>>umap;
        for(auto vec:edges){
            umap[vec[0]].push_back({vec[1],1});
            umap[vec[1]].push_back({vec[0],1});
        }
        result[src]=0;
       queue<pair<int,int>>q;
       q.push({0,src});
        while(!q.empty()){
            int d=q.front().first;
            int node=q.front().second;
            q.pop();
            for(auto vec:umap[node]){
                int dist=vec.second;
                int adjnode=vec.first;
                if(!visited[adjnode]){
                    if(d+dist<result[adjnode]){
                    result[adjnode]=d+dist;
                    q.push({d+dist,adjnode});
                    visited[adjnode]=1;
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            if(result[i]==INT_MAX){
                result[i]=-1;
            }
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
