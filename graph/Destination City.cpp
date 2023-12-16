class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>umap;
        for(auto i:paths){
            string s=i[0];
            umap[s]=1;
        }
        for(auto i:paths){
            string s=i[1];
            if(umap[s]!=1){
                return s;
            }
            
        }
        return "";
    }
};
