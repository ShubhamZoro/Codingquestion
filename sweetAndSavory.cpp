using namespace std;

vector<int> sweetAndSavory(vector<int> dishes, int target) {
 sort(dishes.begin(),dishes.end());
  int sweet=0,savory=dishes.size()-1,minDif=INT_MAX,dif=0,absDif=0;
  vector<int>dishesAns={0,0};
  if(dishes.size()<2 || dishes[sweet]>0 || dishes[savory]<0){
    return dishesAns;
  }
  while(sweet<savory){
    if(dishes[sweet]>0||dishes[savory]<0){
      break;
    }
    dif=dishes[sweet]+dishes[savory];
    if(dif==target){
      return {dishes[sweet],dishes[savory]};
    }
    if(dif<target){
      absDif=target-dif;
      if(absDif<minDif){
        minDif=absDif;
        dishesAns[0]=dishes[sweet];
        dishesAns[1]=dishes[savory];
        
      }
      sweet++;
    }
    else{
      savory--;
    }
  }
  return dishesAns;
}
