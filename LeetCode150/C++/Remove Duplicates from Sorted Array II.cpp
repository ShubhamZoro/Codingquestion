class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1;
        for(int i=1;i<nums.size();i++){
            if (nums[i]==nums[i-1]){
                j++;
            }
            else{
                j=1;
            }

            if(j>2){
                nums.erase(nums.begin()+i);
                i--;
            }

        }
        return nums.size();
    }
};
