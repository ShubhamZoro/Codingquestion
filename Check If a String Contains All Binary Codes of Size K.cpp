class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> un;
        int n=s.size();
        for(int i=0;i<n-k+1;i++){
            string c=s.substr(i,k);
            if(un.find(c)==un.end()){
                un.insert(c);
            }
        }
        if(un.size()==pow(2,k)){
            return true;
        }
        return false;
    }
};
