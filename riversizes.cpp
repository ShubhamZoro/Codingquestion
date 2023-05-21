#include <vector>
using namespace std;

void dfs(vector<vector<int>>& matrix,int i,int j,int &size){
  int height=matrix.size();
  int width=matrix[0].size();
  if((i>=0 && i<height) && (j>=0 && j<width)){
    if(matrix[i][j]==1){
      matrix[i][j]=-1;
      size++;
      dfs(matrix,i,j-1,size);
      dfs(matrix,i,j+1,size);
      dfs(matrix,i-1,j,size);
      dfs(matrix,i+1,j,size);
    }
  }
  
}

vector<int> riverSizes(vector<vector<int>> matrix) {
  vector<int>sizes;
  
  for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[0].size();j++){
      if(matrix[i][j]==1){
        int size=0;
        dfs(matrix,i,j,size);
        sizes.push_back(size);
      }
  }

 
}
   return sizes;
}

