class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>res;
        if(n==0){
            return ;
        }

        int i=0;
        int j=0;
        for(;j<m+n;){
            if(i==n){
                break;
            }
            if(j==m){
                break;
            }
            if(nums1[j]>nums2[i]){
                res.push_back(nums2[i]);
                i++;
            }
            else{
                res.push_back(nums1[j]);
                j++;
            }
        }

        if(i==n){
            for(;j<m;j++){
                res.push_back(nums1[j]);
            }
        }

        if(j==m){
             for(;i<n;i++){
                res.push_back(nums2[i]);
            }
        }
        nums1=res;
    }
};