#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
  // Write your code here.
  int s=0,e=array.size();
  while(s<=e){
    int mid=(s+e)/2;
    if(array[mid]==target){
      return mid;
    }
    else if(array[mid]>target){
      e=mid-1;
    }
    else{
      s=mid+1;
    }
  }
  
  return -1;
}
