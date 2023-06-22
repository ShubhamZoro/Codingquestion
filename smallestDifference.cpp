#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
  sort(arrayOne.begin(),arrayOne.end());
  sort(arrayTwo.begin(),arrayTwo.end());
  int i=0;
  int j=0;
  int min=INT_MAX;
  vector<int>res(2,0);
  while(i<arrayOne.size()&&j<arrayTwo.size()){
    if(arrayOne[i]-arrayTwo[j]==0){
       res[0]=arrayOne[i];
        res[1]=arrayTwo[j];
      return res;
    }
    else{
      
      if(abs(arrayOne[i]-arrayTwo[j])<min){
        
        min=abs(arrayOne[i]-arrayTwo[j]);
      res[0]=arrayOne[i];
        res[1]=arrayTwo[j];
        
      }
      
    }
    if(arrayOne[i]<arrayTwo[j]){
      i++;
    }
    else{
      j++;
    }
  }
  return res;
}
