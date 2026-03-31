class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<int>curr=points[0];
        int count=1;
        int n=points.size();
        for(int i=1;i<n;i++){
            if(points[i][0]>curr[1]){
                count++;
                curr=points[i];
            }
            else{
                curr[0]=max(curr[0],points[i][0]);
                curr[1]=min(curr[1],points[i][1]);
            }
        }
        return count;
    }
};
