class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>umap;
        stack<int>st;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                umap[nums2[i]]=-1;
            }
            else{
                umap[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        n=nums1.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(umap[nums1[i]]);
        }
        return res;
    }
};
