class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>res;
        for(auto i:nums){
            string s=to_string(i);
            for(auto j:s){
                res.push_back(j-'0');
            }
        }
        return res;
    }
};
