class Solution {
public:
    unordered_set<string>st;
    bool checkbinary(int n, string ans, string &res){
        
         if(ans.size() == n) {
            if(st.find(ans) == st.end()) {
                res = ans;
                return true; 
            }
            return false;
        }

        
        if(checkbinary(n, ans + "0", res)) return true;
        
        if(checkbinary(n, ans + "1", res)) return true;

        return false;

    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        int m=nums.size();
        string ans="";
        string res="";
        
        st.insert(nums.begin(),nums.end());
        checkbinary(n,ans,res);
        return res;
    }
};
