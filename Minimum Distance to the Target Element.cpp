class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        int min1=INT_MAX;
        for(int i=start;i<n;i++ ){
            if(nums[i]==target){
                min1=min(min1,abs(i-start));
            }
        }
        for(int i=start;i>=0;i-- ){
            if(nums[i]==target){
                min1=min(min1,abs(i-start));
            }
        }
        return min1;
    }
};
