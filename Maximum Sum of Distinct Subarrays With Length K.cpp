class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       int i=0;
       int n=nums.size();
        int j=0;
        long long res=0;
        long long sum=0;
        unordered_set<int>st;
        while(j<n){
            
            while(st.count(nums[j])){
                sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            sum += nums[j];
            st.insert(nums[j]);

            // Check if the window size is equal to k
            if (j - i + 1 == k) {
                res = max(res, sum);

                // Shrink the window from the left
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
        }
        return res;
    }
};
