#include <vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> array) {

  vector<int>output(array.size(),-1);
  stack<int>s;

  int n=array.size()-1;
  for(int i=n;i>=0;i--){
    s.push(array[i]);
  }
  for(int i=n;i>=0;i--){
    while(!s.empty() && s.top()<=array[i]){
      s.pop();
    }
    if(s.empty()){
      s.push(array[i]);
      continue;
    }
    output[i]=s.top();
    s.push(array[i]);
  }
  return output;
}
