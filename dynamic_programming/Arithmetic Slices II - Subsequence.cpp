class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        unordered_map<long int,long int>umap[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
               long  diff=(long)nums[i]-nums[j];
                auto it=umap[j].find(diff);
                int count_at_j;
                if(it==umap[j].end()){
                    count_at_j=0;
                }
                else{
                    count_at_j=it->second;
                }
                umap[i][diff]+=count_at_j+1;
                result+=count_at_j;
            }
        }
        return result;
    }
};
