#include<stack>
using namespace std;


string bestDigits(string number, int numDigits) {
  if(numDigits==0){
    return number;
  }
  stack<char>res;
  int i=0;
  res.push(number[i]);
  i++;
  for(;i<number.size();i++){
    while(!res.empty()&&number[i]>=res.top() && numDigits>0){
      res.pop();
      numDigits--;
    }
    res.push(number[i]);
  }
  while(numDigits>0){
    res.pop();
    numDigits--;
  }
  string ans="";
  while(!res.empty()){
    ans=res.top()+ans;
    res.pop();
  }
  return ans;
  
}
