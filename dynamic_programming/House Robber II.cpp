class Solution {
public:
    int solve(vector<int>&nums,int i,int n){
        int maxsum=0;
        int first=nums[i];
        int second=nums[i+1];
        for(int k=i;k<n;k++){
            if(k==i){
                maxsum=first;
            }
            else if(k==1+i){
                maxsum=max(first,second);
                second=maxsum;
            }
            else{
                maxsum=max(second,nums[k]+first);
                first=second;
                second=maxsum;
            }
        }
        return maxsum;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        int take_0=solve(nums,0,n-1);
        int take_1=solve(nums,1,n);
        return max(take_0,take_1);

        
    }
};
