class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int>t1;
        for(auto i:t){
            t1[i]++;
        }
        int x=0;
        for(auto i:s){
            if(t1.find(i)!=t1.end() && t1[i]>0){
                t1[i]--;
            }
            else{
                x++;
            }
        }
        return x;
    }
};
