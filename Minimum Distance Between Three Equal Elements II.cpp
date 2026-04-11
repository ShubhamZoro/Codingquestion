class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }

        int max=INT_MAX;
        for(auto i:m){
            if(i.second.size()>=3){
                for(int j=0;j<=i.second.size()-3;j++){
                    int curr=abs(i.second[0+j]-i.second[1+j])+abs(i.second[2+j]-i.second[1+j])+
                abs(i.second[0+j]-i.second[2+j]);
                max=min(max,curr);
                }
                
            }
        }
        if(max==INT_MAX){
            return -1;
        }
        return max;
    }
};
/////

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        int result = INT_MAX;

        for(int k = 0; k < n; k++) {
            mp[nums[k]].push_back(k);

            if(mp[nums[k]].size() >= 3) {
                vector<int> &vec = mp[nums[k]];
                int siz = vec.size();

                int i = vec[siz-3];
                result = min(result, k-i);
            }
        }

        return result >= INT_MAX ? -1 : 2*result;
    }
};
