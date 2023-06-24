#include <vector>
using namespace std;
#include<unordered_map>

int firstDuplicateValue(vector<int> array) {
  unordered_map<int,int>umap;
  for(int i=0;i<array.size();i++){
    if(umap.find(array[i])!=umap.end()){
      return array[i];
    }
    umap[array[i]]+=1;
  }
  return -1; 
}
