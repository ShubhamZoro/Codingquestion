O(n*n)
using namespace std;

vector<int> sunsetViews(vector<int> arr, string direction) {
vector<int>res;
int n=arr.size();
  if(direction=="WEST"){
    for(int i=0;i<n;i++){
      bool flag=true;
      for(int j=i-1;j>=0;j--){
        if(arr[i]<=arr[j]){
          flag=false;
          break;
        }
      }
      if(flag){
        res.push_back(i);
      }
    }
  }
  else{
    
    for(int i=n-1;i>=0;i--){
      bool flag=true;
      for(int j=i+1;j<n;j++){
        if(arr[i]<=arr[j]){
          flag=false;
          break;
        }
      }
      if(flag){
        res.push_back(i);
      }
    }
    reverse(res.begin(),res.end());
  }
  
  return res;
}

// increasing time complexity O(n)

using namespace std;

vector<int> sunsetViews(vector<int> arr, string direction) {
  int maxheight=0;
  vector<int>res;
  if(direction=="WEST"){
    for(int i=0;i<arr.size();i++){
      if(arr[i]>maxheight){
        maxheight=arr[i];
        res.push_back(i);
      }
    }
  }
  else{
    for(int i=arr.size()-1;i>=0;i--){
      if(arr[i]>maxheight){
        maxheight=arr[i];
        res.push_back(i);
      }
    }
    reverse(res.begin(),res.end());
  }
  return res;
}

