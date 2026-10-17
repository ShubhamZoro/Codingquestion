class Solution {
public:
    int digsum(int n){
        int s=0;
        while(n>0){
           int  r=n%10;
            s+=r;
            n=n/10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
       
        vector<int>nsum=nums;
        auto lambda=[this](int num1,int num2){
        int sum1=digsum(num1);
        int sum2=digsum(num2);
        if(sum1!=sum2){
            return sum1<sum2;
        }
        return num1<num2;
       };
        
        sort(nsum.begin(),nsum.end(),lambda);
        
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]=i;
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nsum[i]){
                    int j=umap[nsum[i]];
                    umap[nums[i]]=j;
                    umap[nsum[i]]=i;
                    swap(nums[i],nums[j]);
                    count++;
            }
        }
        return count;
    }
};
