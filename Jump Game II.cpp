class Solution {
public:
    int dp[10001];
    int n;
    int solve(int i,vector<int>& nums){
       if (i >= n - 1)
            return 0;

        
        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        
        for (int jump = 1; jump <= nums[i]; jump++) {
            if (i + jump < n) {
                int next = solve(i + jump, nums);
                if (next != INT_MAX)
                    ans = min(ans, 1 + next);
            }
        }

        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, nums);
    }
};
