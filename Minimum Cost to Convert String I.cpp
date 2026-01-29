class Solution {
public:
    void diji(char &ch,vector<vector<long long>> &cm,unordered_map<char,vector<pair<char,int>>>&umap){
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
        pq.push({0,ch});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto i:umap[node]){
                char adjnode=i.first;
                int w=i.second;
                if(d+w<cm[ch-'a'][adjnode-'a']){
                    cm[ch-'a'][adjnode-'a']=d+w;
                    pq.push({d+w,adjnode});
                }

            }
        }
        return ;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char,vector<pair<char,int>>>umap;
        int n=original.size();
        for(int i=0;i<n;i++){
            umap[original[i]].push_back({
                changed[i],cost[i]
            });
        }
         vector<vector<long long>> costMatrix(26, vector<long long>(26, INT_MAX));
         for(int i=0;i<source.length();i++){
            char ch=source[i];
            diji(ch,costMatrix,umap);
         }

         long long ans = 0;

        for(int i = 0; i < source.length(); i++) {
            if(source[i] == target[i]) {
                continue;
            }

            if(costMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }

            ans += costMatrix[source[i] - 'a'][target[i] - 'a'];

        }

        return ans;
    }
};
