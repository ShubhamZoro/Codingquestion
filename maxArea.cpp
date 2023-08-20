class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0,e=height.size()-1;
        int res=0;
        int max1=0;
        while(e>s){
            res=(e-s)*min(height[s],height[e]);
            max1=max(res,max1);
            if(height[s]<height[e]){
                s++;
            }
            else{
                e--;
            }
        }
        return max1;
    }
};
