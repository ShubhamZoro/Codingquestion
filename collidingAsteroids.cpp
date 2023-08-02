#include<stack>
using namespace std;

vector<int> collidingAsteroids(vector<int> asteroids) {
  stack<int>ans;
  for(auto i: asteroids){
    if(i>0){
      ans.push(i);
    }
    else{
      while(!ans.empty() && ans.top()>0 && (ans.top()<abs(i))){
        ans.pop();
      }
      if(ans.empty()||ans.top()<0){
        ans.push(i);
      }
      else if(!ans.empty() && (ans.top()==abs(i))){
        ans.pop();
      }
    }
  }
  vector<int>res;
  while(!ans.empty()){
    res.push_back(ans.top());
    ans.pop();
  }
  reverse(res.begin(),res.end());
  return res;
}
