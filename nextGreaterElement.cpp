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

/////////////// python

from typing import List

def next_largest_number_to_the_right(nums: List[int]) -> List[int]:
    # Write your code here
    st=[]
    n=len(nums)
    res=[-1]*n
    for i in range(n-1,-1,-1):
        while(len(st)!=0 and st[-1]<=nums[i]):
            st.pop()
        
        if(len(st)==0 ):
            res[i]=-1
        else:
            res[i]=st[-1]
        
        
        st.append(nums[i])
    return res
