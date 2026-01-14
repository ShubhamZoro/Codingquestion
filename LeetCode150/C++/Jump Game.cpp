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
