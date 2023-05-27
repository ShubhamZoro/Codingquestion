// Given a staircase, find the total number of ways to reach the n'th stair from the bottom of the stair when a person is only allowed to take at most m steps at a time.
// using namespace std;
// Input:  n = 3, m = 2
// Output: Total ways to reach the 3rd stair with at most 2 steps are 3
 
// 1 step + 1 step + 1 step
// 1 step + 2 steps
// 2 steps + 1 step
 
 
// Input:  n = 4, m = 3
// Output: Total ways to reach the 4th stair with at most 3 steps are 7
 
// 1 step + 1 step + 1 step + 1 steps
// 1 step + 1 step + 2 steps
// 1 step + 2 steps + 1 step
// 1 step + 3 steps
// 2 steps + 1 step + 1 step
// 2 steps + 2 steps
// 3 steps + 1 step
int staircaseTraversal(int height, int maxSteps) {
  vector<int>x;
  if(maxSteps==0){
    return 1;
  }
  x.push_back(1);
  x.push_back(1);
  for(int i=2;i<=height;i++){
    int sum=0;
    for(int j=0;j<maxSteps;j++){
      if(i-j-1>=0){
        sum+=x[i-j-1];
      }
    }
    x.push_back(sum);
  }
  return x[height];
}
