#include<bits/stdc++.h>
using namespace std;
int issafe(vector<string> arr, int i, int j){
    if(i>=0 && i<arr.size()&&j>=0&&j<arr[0].size()&&arr[i][j]=='0'){
        return 1;
    }
    return 0;
}
int solvemaze(vector<string> arr,vector<vector<int>>&rat,int i, int j){
    if(i==arr.size()-1 && j==arr[0].size()-1){
        rat[i][j]=1;
        return 1;
    }
    if(issafe(arr,i,j)){
        rat[i][j]=1;
        if(solvemaze(arr,rat,i+1,j)){
            return 1;
        }
        if(solvemaze(arr,rat,i,j+1)){
            return 1;
        }
        rat[i][j]=0;
        return 0;
    }
    return 0;
}
vector<vector<int>> ratAndMice(vector<string> arr) {
    vector<vector<int>>rat(arr.size(),vector<int>(arr[0].size(),0));
    solvemaze(arr,rat,0,0);
    return rat;
}
int main(){
    vector<string> arr{ "0X00", "000X",
                                     "X0X0", "X00X", "XX00" };

    vector<vector<int>>maze=ratAndMice(arr);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout<<maze[i][j]<< " ";
        }
        cout<<endl;
    }

}
