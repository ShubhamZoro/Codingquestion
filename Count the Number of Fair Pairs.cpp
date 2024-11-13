class Solution {
private:
    int getfirst(int i,int lower,int upper,vector<int>& nums){
        int s=i+1;
        int e=nums.size()-1;
        int ans=-1;
        while(s <= e){
            int mid=s + (e-s)/2;
            long long sum=nums[i] + nums[mid];
            if(sum < lower){
                s=mid+1;
            }else if(sum > upper){
                e=mid-1;
            }else{
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
    int getLast(int i,int lower,int upper,vector<int>& nums){
        int s=i+1;
        int e=nums.size()-1;
        int ans=-1;
        while(s <= e){
            int mid=s+(e-s)/2;
            long long sum=nums[i] + nums[mid];
            if(sum < lower){
                s=mid+1;
            }else if(sum > upper){
                e=mid-1;
            }else{
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int ele=nums[i];
            int first=getfirst(i,lower,upper,nums);
            int last=getLast(i,lower,upper,nums);
            if(last != -1 && first != -1)
                ans+=(last-first+1);

        }
        return ans;
    }
};
