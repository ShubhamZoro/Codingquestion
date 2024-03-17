class Solution {
public:
    long long countSubstrings(string s, char c) {
        unordered_map<char,long long int>umap;
        long long count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==c){
                count=count+1+umap[s[i]];
            }
            umap[s[i]]++;
        }
        return count;
    }
};
