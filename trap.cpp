class Solution {
public:
    int trap(vector<int>& height) {
        // int n=height.size();
        // vector<int>Lmax(n,0);
        // vector<int>Rmax(n,0);
        // for(int i=1;i<n;i++){
        //     Lmax[i]=max(Lmax[i-1],height[i-1]);
        // }
        // for(int i=n-2;i>=0;i--){
        //     Rmax[i]=max(Rmax[i+1],height[i+1]);
        // }
        // vector<int>LRmin;
        // for(int i=0;i<n;i++){
        //     LRmin.push_back(min(Rmax[i],Lmax[i]));
        // }
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     if(LRmin[i]-height[i]>=0){
        //         sum+=LRmin[i]-height[i];
        //     }
        // }
        // return sum;
        int n=height.size();
        if(n==0){
            return 0;
        }
        int l=0,r=n-1;
        int leftmax=height[l],rightmax=height[r];
        int res=0;
        while(l<r){
            if(leftmax<rightmax){
                l+=1;
                leftmax=max(leftmax,height[l]);
                res+=leftmax-height[l];
            }
            else{
                r-=1;
                rightmax=max(rightmax,height[r]);
                res+=rightmax-height[r];
            }
        }
        return res;
    }
};
