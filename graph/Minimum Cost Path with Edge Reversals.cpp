class Solution {
public:
typedef pair<int, int> P;
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>> adj;
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],2*i[2]});
        }
        vector<int> result(n, INT_MAX);
        result[0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int d=pq.top().first;
            int adjnode=pq.top().second;
            pq.pop();
            if(adjnode==n-1){
                return result[adjnode];
            }
            for(auto i:adj[adjnode]){
                int wt=i.second;
                int node=i.first;
                if(d+wt<result[node]){
                    result[node]=d+wt;
                    pq.push({d+wt,node});
                }
            }
        }
        return -1;
    }
};
