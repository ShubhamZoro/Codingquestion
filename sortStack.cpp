#include <vector>
#include <stack>
using namespace std;

vector<int> sortStack(vector<int> &Stack) {
  stack<int>input;
  stack<int>temp;
  int indx=Stack.size()-1;
  while(indx>=0){
    input.push(Stack[indx]);
    indx--;
  }

  while(!input.empty()){
    int top=input.top();
    input.pop();
    while(!temp.empty()&&top<temp.top()){
      input.push(temp.top());
      temp.pop();
    }
    temp.push(top);
  }
  while(!temp.empty()){
    input.push(temp.top());
    temp.pop();
  }
  vector<int>out;
  while(!input.empty()){
    out.push_back(input.top());
    input.pop();
  }
  return out;

}
