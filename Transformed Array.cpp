class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int j=(nums[i]+i)%n;
                 res[i]=nums[j];
            }else if(nums[i]<0){
                int j = ((i + nums[i]) % n + n) % n;;
                res[i]=nums[j];
            }
            else{
                 res[i]=nums[i];
            }
        }
        return res;
    }
};
