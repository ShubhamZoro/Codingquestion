using namespace std;
int expandAroundCenter(string s,int left,int right){
  while(left>=0 && right<s.size() && s[left]==s[right]){
    left--;
    right++;
  }
  return right-left-1;
}
string longestPalindromicSubstring(string str) {
  int start=0,end=0;
  for (int i=0;i<str.size();i++){
    int len=max(expandAroundCenter(str,i,i),expandAroundCenter(str,i,i+1));
    if(len>end-start){
      start=i-(len-1)/2;
      end=i+len/2;
    }
  }
  return s.substr(start,end-start+1);
}
