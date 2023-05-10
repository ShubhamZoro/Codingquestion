#include<iostream>
#include<vector>
using namespace std;

int levenshteinDistance(string str1, string str2) {
  int r=str2.size()+1;
  int c=str1.size()+1;
  vector<vector<int>>arr(str2.size()+1,vector<int>(str1.size()+1,0));
  for(int i=0;i<r;i++){
    arr[i][0]=i;
  }
  for(int i=0;i<c;i++){
    arr[0][i]=i;
  }
  for(int i=1;i<r;i++){
    for(int j=1;j<c;j++){
      if(str2[i-1]==str1[j-1]){
        arr[i][j]=arr[i-1][j-1];
      }
      else{
        arr[i][j]=1+min(min(arr[i][j-1],arr[i-1][j]),arr[i-1][j-1]);
      }
    }
  }
  return arr[str2.size()][str1.size()];
}

int main(){
cout<<levenshteinDistance("abc","sabd");
}
