// using extra space

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>temp=intervals;
        temp.push_back(newInterval);
        sort(temp.begin(),temp.end());
        vector<vector<int>>res;
        vector<int>curr=temp[0];
        int n=temp.size();
        int i=1;
        int j=0;
        for(;i<n;i++){
            if(temp[i][0]>curr[1]){
                res.push_back(curr);
                curr=temp[i];
                j=i;
            }
            else{
                curr[0]=min(curr[0],temp[i][0]);
                curr[1]=max(curr[1],temp[i][1]);
            }
        }
        if(i-j==1){
            res.push_back(temp[n-1]);
        }
        else{
            
            res.push_back(curr);
        }
        return res;


    }
};
