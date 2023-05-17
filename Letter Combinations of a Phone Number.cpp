#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char,vector<char>>digits{
  {'0',{'0'}},
  {'1',{'1'}},
{'2',{'a','b','c'}},
  {'3',{'d','e','f'}},
{'4',{'g','h','i'}},
  {'5',{'j','k','l'}},
{'6',{'m','n','o'}},
  {'7',{'p','q','r','s'}},
{'8',{'t','u','v'}},
  {'9',{'w','x','y','z'}}
};
void phoneNumberMnemonicsHelper(int idx, string phoneNumber,vector<string>currentMnemonic,vector<string>&mnemonicsFound){
  if (idx==phoneNumber.size()){
    string mnemonic="";
    for(auto i:currentMnemonic){
      mnemonic+=i;
    }
    mnemonicsFound.push_back(mnemonic);
  }
  else{
    char digit=phoneNumber[idx];
    vector<char> letters=digits[digit];
    for(auto letter:letters){
      currentMnemonic[idx]=letter;
      phoneNumberMnemonicsHelper(idx+1,phoneNumber,currentMnemonic,mnemonicsFound);
    }
  }
}

vector<string> phoneNumberMnemonics(string phoneNumber) {
  vector<string>currentMnemonic(phoneNumber.size(),"0");
  vector<string>mnemonicFound;
  phoneNumberMnemonicsHelper(0,phoneNumber,currentMnemonic,mnemonicFound);
  return mnemonicFound;
}

int main(){
vector<string>res=phoneNumberMnemonics("1234");
cout<<res.size()<<endl;
for(auto i:res){
    cout<<i<<endl;
}
return 0;
}
