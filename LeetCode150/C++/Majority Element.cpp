class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int m=nums[0];
        int j=1;
        for(int i=1;i<n;i++){

            if(nums[i]==m){
                j++;
            }
            else{
                j--;
            }
            if(j==0){
                j=1;
                m=nums[i];
            }
        }
        return m;
    }
};
