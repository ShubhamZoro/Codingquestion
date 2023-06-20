using namespace std;

int bestSeat(vector<int> seats) {
 int index=-1;
int max=0;
 int left=0;
  while(left<seats.size()){
      int right=left+1;
      while(right<seats.size() && seats[right]==0){
      right+=1;
      }
       int cmax=right-left-1;
      if (cmax>max){
        max=cmax;
        index=(left+right)/2;
      }
      left=right;
  }

  return index;
}
