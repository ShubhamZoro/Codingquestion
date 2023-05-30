#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
  // Write your code here.
  vector<int>product(array.size(),1);
  vector<int>left(array.size(),1);
  vector<int>right(array.size(),1);
  int lefts=1;
  for(int i=0;i<array.size();i++){
    left[i]=lefts;
      lefts*=array[i];
  }
  int rights=1;
  for(int i=array.size()-1;i>=0;i--){
    right[i]=rights;
    rights*=array[i];
  }
  for(int i=0;i<array.size();i++){
    product[i]=right[i]*left[i];
  }
  return product;
}
