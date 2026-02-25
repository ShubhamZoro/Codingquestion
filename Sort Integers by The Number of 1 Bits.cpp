class Solution {
public:
    int setbit(int a){
        int count=0;
        while(a>0){
            int r=a%2;
            a=a/2;
            count+=r;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<int>res;
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            int count=setbit(arr[i]);
            temp.push_back({count,arr[i]});

        }
    sort(temp.begin(),temp.end());
        for(auto j:temp){
            int element=j.second;
            res.push_back(element);
        }
        return res;
    }
};
