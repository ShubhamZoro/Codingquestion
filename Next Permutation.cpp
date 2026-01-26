class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int p=nums.size()-2;
        while( p>=0 && nums[p]>=nums[p+1])
        {
            p-=1;
        }
        if(p==-1){
            return reverse(nums.begin(),nums.end());
        }
        int rm=nums.size()-1;
        while (nums[rm]<=nums[p]){
                rm-=1;
        }
        swap(nums[rm],nums[p]);
        reverse(nums.begin()+p+1,nums.end());
        
    }
};
