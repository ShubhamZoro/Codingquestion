class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int max1=0;
        for(int i=0;i<n;i++){
            int even=0,odd=0;
            unordered_set<int>eu;
            unordered_set<int>ou;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    eu.insert(nums[j]);
                }
                else{
                    ou.insert(nums[j]);
                }
                if(ou.size()==eu.size()){
                max1=max(j-i+1,max1);
             }
            }
            
        }
        return max1;
    }
};
