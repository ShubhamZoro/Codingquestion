class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>res;
        int n=temperatures.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            while(!res.empty() && temperatures[res.top()]<temperatures[i]){
                ans[res.top()]=i-res.top();
                res.pop();
            }
            res.push(i);
        }
        return ans;
    }
};
