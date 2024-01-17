class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>s;
        for(int i=0;i<arr.size();i++){
            s[arr[i]]++;
        }
        set<int>k;
        for(auto i:s){
            if(k.find(i.second)!=k.end()){
                return false;
            }
            k.insert(i.second);
        }
        return true;
    }
};
