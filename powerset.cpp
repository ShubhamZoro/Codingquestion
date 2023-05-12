#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> powerset(vector<int> array) {
  vector<vector<int>>res;
  res.push_back({});
  for(int i=0;i<array.size();i++){
    int n=res.size();
      for(int j=0;j<n;j++){
        vector<int>curr;
    for(int k=0;k<res[j].size();k++){
        curr.push_back(res[j][k]);
    }
        curr.push_back(array[i]);
        res.push_back(curr);
    }



    }
   return res;
}

int main(){
vector<int>input={1,2,3};
vector<vector<int>>res=powerset(input);
for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++){
        cout<<res[i][j];
    }
    cout<<endl;
}
return 0;
}
