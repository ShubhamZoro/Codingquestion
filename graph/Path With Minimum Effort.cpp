class Solution {
public:
    vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        result[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int max1=INT_MIN;
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            int diff=node.first;
            int x=node.second.first;
            int y=node.second.second;
            for(auto dir:dirs){
                int x_=x+dir[0];
                int y_=y+dir[1];
                if(x_>=0 && x_<n && y_>=0 && y_<m){
                    
                    int newDiff = max(diff, abs(heights[x][y] - heights[x_][y_]));
		            if(result[x_][y_] > newDiff) {
			            result[x_][y_] = newDiff;
			            pq.push({result[x_][y_], {x_, y_}});
		             }
                }
            }
    }
    
        
        return result[n-1][m-1];
    }
};
