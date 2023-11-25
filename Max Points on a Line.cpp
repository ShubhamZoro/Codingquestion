// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         long long max1=INT_MIN;
//         int n=points.size();
//         if(points.size()==1){
//             return 1;
//         }
        
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 long long count=0;
//                 for(int k=0;k<n;k++){
//                     long long eq1=(points[k][1]-points[i][1])*(points[j][0]-points[i][0]);
//                     long long eq2=(points[k][0]-points[i][0])*(points[j][1]-points[i][1]);
//                     if(eq1==eq2){
//                         count++;
//                     }
//                 }
//                 max1=max(max1,count);
//             }
            
//         }
//         return max1;
//     }
// };

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1){
            return 1;
        }
        int res=0;
        for(int i=0;i<n;i++){
            unordered_map<double,int>umap;
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                auto dx=points[i][0]-points[j][0];
                auto dy=points[i][1]-points[j][1];
                auto slope=atan2(dy,dx);
                umap[slope]++;
            }
            for(auto &it:umap){
                res=max(res,it.second+1);
            }
        }
        return res;
    }
};
