class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int max1=INT_MIN;
        int n=colors.size();
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                if(colors[i]!=colors[j]){
                    max1=max(max1,abs(i-j));
                }
                
            }
        }
        return max1;
    }
};
