class Solution {
public:
int t[10001];
    bool DP(vector<int>&nums,bool &canjum,int i){
        if(i==nums.size()-1){
            
            canjum= true;
            return true;
        }
        if(t[i]!=-1){
            return t[i];
        }

        if(i>=nums.size()){
            return false;
        }

        for(int j=1;j<=nums[i];j++){
            if(DP(nums,canjum,i+j)){
                  return t[i]=true;
            }
            
        }

        return t[i]=false;
    }
    bool canJump(vector<int>& nums) {
        if(nums[0]==0 && nums.size()==1){
            return true;
        }
        bool canjum=false;
        memset(t,-1,sizeof(t));
        DP(nums,canjum,0);
        return canjum;
    }

};
-----------------------------------------------------
    class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n = nums.size();
        
        vector<int> t(n, false);
        
        
        t[0] = true;
        
        for(int i = 1; i<n; i++) {
            for(int j = i-1; j>=0; j--) {
                if(j + nums[j] >= i && t[j]) {
                    t[i] = true;
                    break;
                }
            }
        }
        
        
        return t[n-1];
    }
};

-------------------------------------------------------------------

    class Solution {
public:
    bool canJump(vector<int>& nums) {
       int goal=nums.size()-1;
       for(int i=nums.size()-1;i>=0;i--) {
           if(i+nums[i]>=goal){
               goal=i;
           }
       }
       if(goal==0){
           return true;
       }
       return false;
    }
};
