class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return {};
        }

        long l=nums[0],r=nums[0];
        vector<string>ans;
        for(int i=1;i<n;i++){
            if((long)nums[i]-nums[i-1]!=1){
                if(r==l){
                    ans.push_back(to_string(l));
                }
                else{
                    ans.push_back(to_string(l)+"->"+to_string(r));
                }
                l=r=nums[i];
            }
            else{
                r=nums[i];
            }
        }
        if(r==l){
            ans.push_back(to_string(l));
        }
        else{
            ans.push_back(to_string(l)+"->"+to_string(r));
        }
        return ans;
    }
};
