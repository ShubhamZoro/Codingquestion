class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>umap;
        int n=nums.size();
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            int freq=umap[nums[i]];
            if(freq==res.size()){
                res.push_back({});
            }
            res[freq].push_back(nums[i]);
            umap[nums[i]]++;
        }
        return res;
    }
};
