class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>res;
        if(n==0){
            return ;
        }

        int i=0;
        int j=0;
        while (j<m && i<n){
           
            if(nums1[j]>nums2[i]){
                res.push_back(nums2[i]);
                i++;
            }
            else{
                res.push_back(nums1[j]);
                j++;
            }
        }

        if(i==n){
            for(;j<m;j++){
                res.push_back(nums1[j]);
            }
        }

        if(j==m){
             for(;i<n;i++){
                res.push_back(nums2[i]);
            }
        }
        nums1=res;
    }
};


--------------------------------------------------------------------------------

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=n+m-1;
        
        while (j>=0 && i>=0){
           
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
            }
            else{
               nums1[k]=nums2[j];
                j--;
            }
            k--;
        }

        
            while (j>=0){
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        
    }
};

