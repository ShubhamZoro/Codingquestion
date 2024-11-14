class Solution {
public:

    bool possibleToDistr(int x,vector<int>& quantities,int shops){
        for(int &products:quantities){
            shops-=(products+x-1)/x ;//ceil(product/x)

            if(shops<0){
                return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
       int m=quantities.size();
       int l=1;
       int r=*max_element(quantities.begin(),quantities.end());
       int res=0;
       while(l<=r){
        int mid=l+(r-l)/2;
        if(possibleToDistr(mid,quantities,n)){
            res=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
       }
       return res;
    }
};
