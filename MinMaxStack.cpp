#include<stack>
using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
public:
stack<int>minmaxstack;
  stack<int>max;
  stack<int>min;
  
  int peek() {
    
    return minmaxstack.top();
  }

  int pop() {
    int p=minmaxstack.top();
    minmaxstack.pop();
    if(min.top()==p){
      min.pop();
    }
    if(max.top()==p){
      max.pop();
    }
    
    return p;
  }

  void push(int number) {
    minmaxstack.push(number);
    if(max.empty() || number>=max.top()){
      max.push(number);
    }
    if(min.empty()||number<=min.top()){
      min.push(number);
    }
  }

  int getMin() {
    // Write your code here.
    return min.top();
  }

  int getMax() {
    // Write your code here.
    return max.top();
  }
};
