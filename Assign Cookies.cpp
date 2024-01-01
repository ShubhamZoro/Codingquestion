class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int sum=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int n=g.size();
        int m=s.size();
        int j=0;
        for(int i=0;i<n;){
            if(j>=m){
                break;
            }
            if(s[j]>=g[i]){
                i++;
                sum++;
            }
            
                j++;
           
        }
        return sum;
    }
};
