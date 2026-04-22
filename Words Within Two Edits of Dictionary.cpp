class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        int m=dictionary.size();
        vector<string>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int s=queries[i].size();
                int count=2;
                for(int k=0;k<s;k++ ){
                    if(queries[i][k]!=dictionary[j][k]){
                        count--;
                    }
                }
                if(count>=0){
                    res.push_back(queries[i]);
                    break;
                }
            }
        }
        return res;
    }
};
