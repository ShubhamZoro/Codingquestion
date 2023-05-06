//Given an array of integers, what is the Length of Longest Subarray that contains no more than two distinct values such that the distinct values differ by no more than 1?
//Example:
//arr=[0,1,2,1,2,3]
//The largest such subarray has length 4:[1,2,1,2].
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int longestSubarray(vector<int> arr) {
    int j=0,ans=0;
    map<int,int>p;
    for(int i=0;i<arr.size();i++){
        p[arr[i]]++;
        while(p.size()>2 && j<i){
            p[arr[j]]--;
            if(p[arr[j]]==0){p.erase(arr[j]);}
            j++;
        }
        if(p.size()==1){
            ans=max(ans,i-j+1);
        }
        else if(p.size()==2){
            vector<int>v;
            for(auto x:p){
                v.push_back(x.first);
            }
            if(abs(v[0]-v[1])<=1){
                ans=max(ans,i-j+1);
            }
        }
    }
    return ans;
}
int main(){
    vector<int>arr={0,1,2,1,2,3};
    cout<<longestSubarray(arr);
}
