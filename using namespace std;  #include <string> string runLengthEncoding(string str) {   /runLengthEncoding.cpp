using namespace std;

#include <string>
string runLengthEncoding(string str) {
  // Write your code here.
  string res="";
  for(int i=0;i<str.size();i++){
    int count=1;
    while(count<9&&str[i]==str[i+1]){
      count++;
      i++;
    }
    res+=to_string(count)+str[i];
  }
  return res;
}
