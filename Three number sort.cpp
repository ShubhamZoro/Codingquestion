#include <vector>
using namespace std;

vector<int> threeNumberSort(vector<int> array, vector<int> order) {
  int x=0,y=0,z=0;
  for(int i=0;i<array.size();i++){
    if(order[0]==array[i]){
      x++;
    }
    else if(order[1]==array[i]){
      y++;
    }
    else if(order[2]==array[i]){
      z++;
    }
  }
  for(int i=0;i<array.size();i++){
    if(x>0){
      x--;
      array[i]=order[0];
    }
    else if(y>0){
      y--;
      array[i]=order[1];
    }
    else if(z>0){
      z--;
      array[i]=order[2];
    }
  }
  return array;
}
