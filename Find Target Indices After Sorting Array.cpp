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

////

class Solution {
    int first(vector<int>&nums, int target){
        int low = 0 ; 
        int high = nums.size()-1;
        int ans = -1;
        while(low <=high){
            int mid = low + (high-low)/2;
            if(nums[mid]== target){
                 ans = mid;
                 high = mid -1;
            }else if(nums[mid]>target){
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    };
    int last(vector<int>&nums, int target){
        int low = 0 ; 
        int high = nums.size()-1;
        int ans = -1;
        while(low <=high){
            int mid = low + (high-low)/2;
            if(nums[mid]== target){
                 ans = mid;
                 low = mid + 1;
            }else if(nums[mid]>target){
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    };
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>arr = nums;
        sort(arr.begin(), arr.end());
        int f = first(arr, target);
        int l = last(arr, target);
        vector<int> res;
        if (f == -1) return res;  
        for(int i = f; i<=l;i++){
            res.push_back(i);
        }
        return res;
    }

};
