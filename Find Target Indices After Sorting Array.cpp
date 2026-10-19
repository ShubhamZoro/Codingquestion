class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                res.push_back(i);
            }
        }
        return res;
    }
};
////


class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int s=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target){
                s++;
            }
            else if(nums[i]>target){
                l++;
            }
        }
        int n=nums.size();
        vector<int>res;
        for(int i=s;i<n-l;i++){
            res.push_back(i);
        }
        return res;
    }
};
