class Solution {
public:
typedef long long ll;
typedef pair<ll,string>P;
ll BIG_VALUE=1e10;
unordered_map<string,vector<pair<string,ll>>>adj;
unordered_map<string, unordered_map<string, ll>> dijkstraMemo;

    vector<ll> dpMemo;

    string sourceStr;
    string targetStr;
    set<int> validLengths;

    ll dijkstra(string start,string end){
        unordered_map<string,ll>result;
        priority_queue<P, vector<P>, greater<P>> pq;
        if(dijkstraMemo[start].count(end)){
            return dijkstraMemo[start][end];
        }
        result[start]=0;
        pq.push({0, start});

        while(!pq.empty()) {
            ll currCost = pq.top().first;
            string node = pq.top().second;
            pq.pop();

            if(node == end) {
                break;
            }

            for(auto &edge : adj[node]) {
                string adjNode = edge.first;
                ll edgeCost = edge.second;

                if(!result.count(adjNode) || currCost + edgeCost < result[adjNode]) {
                    result[adjNode] = currCost + edgeCost;
                    pq.push({currCost+edgeCost, adjNode});
                }
            }
        }
        ll finalCost = result.count(end) ? result[end] : BIG_VALUE;
         return dijkstraMemo[start][end] = finalCost;
    }

    ll solve(int idx){
        if(idx>sourceStr.length()){
            return 0;
        }
        if(dpMemo[idx]!=-1){
            return dpMemo[idx];
        }
        ll minCost=BIG_VALUE;
        if(sourceStr[idx] == targetStr[idx])
            minCost = solve(idx+1);
        
        for(auto &len:validLengths){
            if(idx + len > sourceStr.length()) {
                break;
            }
            string srcSub = sourceStr.substr(idx, len);
            string tgtSub = targetStr.substr(idx, len);

            if(!adj.count(srcSub)) {
                continue;
            }

            ll minPathCost=dijkstra(srcSub,tgtSub);
            if(minPathCost==BIG_VALUE){
                continue;
            }
            minCost=min(minCost,minPathCost+solve(idx+len));

        }
        return dpMemo[idx]=minCost;
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        sourceStr = source;
        targetStr = target;
        dpMemo.assign(10001, -1);
        int n=original.size();
        for(int i=0;i<n;i++){
            adj[original[i]].push_back({changed[i],cost[i]});
            validLengths.insert(original[i].length());
        }
        ll result = solve(0);

        return result == BIG_VALUE ? -1 : result;
        
    }
};
