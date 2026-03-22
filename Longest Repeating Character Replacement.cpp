class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>umap;
        int i=0;
        int n=s.size();
        int j=0;
        int max_freq=0;
        int ans=0;
        while(i<n){
            umap[s[i]]++;
            max_freq=max(umap[s[i]],max_freq);
            int nc=i-j+1-max_freq;
            if(nc>k){
                
                umap[s[j]]--;
                j++;
                
            }
 ans=max(ans,i-j+1);

 i++;
        }
        return ans;
    }
};
