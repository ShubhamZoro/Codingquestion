#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int lis(vector<int>arr){
    int n=arr.size();
vector<int>dp(n,1);
for(int i=0;i<arr.size();i++ ){
    for(int j=i-1;j>=0;j--){
        if(arr[i]>arr[j]){
            dp[i]=max(dp[i],dp[j]+1);
        }
    }
}
return *max_element(dp.begin(),dp.end());
}
int main(){
vector<int>arr={50,4,10,8,30,100};
cout<<lis(arr);
}
