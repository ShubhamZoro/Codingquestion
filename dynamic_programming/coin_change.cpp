#include<iostream>
#include<vector>
using namespace std;

int min_coins(int d,vector<int>coins){
vector<int>res(d+1,INT_MAX);
res[0]=0;
for(auto i:coins){
    for(int j=1;j<=d;j++){
        int curr=res[j-i];
        if(j>=i&& curr!=INT_MAX){
            res[j]=min(res[j],curr+1);
        }
    }

}
return res[d];
}

int main(){
vector<int>coins={1,2,3,4};
int d=7;
cout<<min_coins(d,coins);
}
