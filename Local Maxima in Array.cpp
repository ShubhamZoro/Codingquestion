class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return 0;
        }

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1] && i==n-1){
                return i;
            }
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                return i;
            }
        }
        return 0;
    }
};

/////////////////////////////////////

class Solution {
public:
    int findPeakElement(vector<int>& nums){
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]<nums[mid+1]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
};
