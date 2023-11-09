class Solution {
public:
    void fnc(vector<string>&ans,int n,int open,int close,string s){
        if(s.size()==n*2){
            ans.push_back(s);
            return ;
        }
        if(open<n){
            fnc(ans,n,open+1,close,s+"(");
        }
        if(close<open){
            fnc(ans,n,open,close+1,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        fnc(ans,n,0,0,"");
        return ans;
    }
};
