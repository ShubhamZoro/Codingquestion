class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=prices[0];
        
        int max1=-1;
        for(int j=1;j<n;j++){
            if(i>prices[j]){
                i=prices[j];
            }
            else{
                max1=max(prices[j]-i,max1);
            }
        }
        if(max1<0){
            return 0;
        }
        return max1;
    }
};
