class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n=arr.size();
        vector<int>res(n);
        int r=n-1;
        int k=n-1;
        int l=0;
        while(l<=r){
            if(arr[l]*arr[l]<=arr[r]*arr[r]){
                res[k]=arr[r]*arr[r];
               r--;
            }
            else{
                res[k]=arr[l]*arr[l];
                l++;
            }
            k--;
        }
        return res;
    }
};
