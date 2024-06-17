class Solution {
public:
    void permutation(set<vector<int>>&ans,vector<int> nums,int l,int r){
        if(l==r){
            ans.insert(nums);
            return ;
        }
        int i;
        for(i=l;i<=r;i++){
            swap(nums[i],nums[l]);
            permutation(ans,nums,l+1,r);
            swap(nums[i],nums[l]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>ans;
        vector<vector<int>> ans1;
        permutation(ans,nums,0,n-1);
        for(auto it=ans.begin();it!=ans.end();it++){
            ans1.push_back(*it);
        }
        return ans1;
    }
};
