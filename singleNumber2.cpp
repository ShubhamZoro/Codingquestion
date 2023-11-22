// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int,int>umap;
//         for(auto i:nums){
//             umap[i]++;
//         }
//         for(auto i:umap){
//             if(i.second!=3){
//                 return i.first;
//             }
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0;k<=31;k++){
            int temp=(1<<k);
            int countones=0;
            for(int &num:nums){
                if((num & temp)==0){

                }
                else{
                    countones++;
                }
            }
            if(countones%3==1){
                result =(result|temp);
            }
        }
return result;
    }
};
