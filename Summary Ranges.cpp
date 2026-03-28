class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string>res;
        int l=0;

        int r=0;
        int n=nums.size();
        if(n==0){
            return {};
        }
        for(int i=0;i<n-1;i++){
            if((long)nums[i+1]-nums[i]==1){
                r++;
            }
            else{
                if(nums[l]==nums[r]){
                    res.push_back(to_string(nums[l]));
                }
                if(nums[l]!=nums[r]){
                    res.push_back(to_string(nums[l])+"->"+to_string(nums[r]));
                }
                
                l=r=i+1;
            }
        }
         if(nums[l]==nums[r]){
                    res.push_back(to_string(nums[l]));
                }
                if(nums[l]!=nums[r]){
                    res.push_back(to_string(nums[l])+"->"+to_string(nums[r]));
                }
                return res;
    }
};
