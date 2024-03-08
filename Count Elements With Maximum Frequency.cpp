class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>umap;
        int max1=-1;
        for(auto i:nums){
            umap[i]++;
            max1=max(umap[i],max1);
        }
        int res=0;
        for(auto i:umap){
            if(i.second==max1){
                res+=max1;
            }
        }
        return res;
    }
};
