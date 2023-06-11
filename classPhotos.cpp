#include <vector>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  // Write your code here.
  int k=0,s=0;
  sort(redShirtHeights.begin(),redShirtHeights.end());
    sort(blueShirtHeights.begin(),blueShirtHeights.end());
  for(int i=0;i<redShirtHeights.size();i++){
    if(redShirtHeights[i]>blueShirtHeights[i]){
      k=k+1;
    }
    if(blueShirtHeights[i]>redShirtHeights[i]){
      s=s+1;
    }
  }
  if(k==redShirtHeights.size()||s==redShirtHeights.size())
  {
    return true;
  }
  return false;
}
