class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            unordered_set<int>us;
            for(int j=i;j<n;j++){
               us.insert(nums[j]);
               sum+=us.size()*us.size();
            }
        }
        return sum;
    }
};
