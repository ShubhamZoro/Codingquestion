class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int min1=INT_MAX;
        vector<vector<int>>curr;
        for(int i=0;i<n-1;i++){
            int diff=abs(arr[i]-arr[i+1]);
            if(min1>diff){
                min1=diff;
                curr={};

            }
            else if(diff==min1){
                if(arr[i]>arr[i+1])
                {
                    curr.push_back({arr[i+1],arr[i]});
                }
                else{
                    curr.push_back({arr[i],arr[i+1]});
                }
            }
            if(curr.size()==0){
                if(arr[i]>arr[i+1])
                {
                    curr.push_back({arr[i+1],arr[i]});
                }
                else{
                    curr.push_back({arr[i],arr[i+1]});
                }
                
            }
            
        }
        return curr;
    }
};
