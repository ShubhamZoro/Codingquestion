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

---------------------------------------------------------------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int i=2;
        for(int j=2;j<nums.size();j++){
            if(nums[j]!=nums[i-2]){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};
