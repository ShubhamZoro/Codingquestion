#include<iostream>
using namespace std;

void subset(string k){
    int n=k.length();


for(int i=0;i<n;i++){
    for(int j=i+1;j<=n;j++){
        for(int l=i;l<=j-1;l++){
            cout<< k[l];

    }
    cout<<", ";
}
}
}
int main(){
    subset("abcde");
}
