#O(n*n)
#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
  for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[i].size();j++){
      if(target==matrix[i][j]){
        return {i,j};
      }
    }
  }
  return {-1,-1};
}

#O(row+col)
#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
 int col=matrix[0].size()-1;
  
 int row=0;
  while(row<matrix.size() && col>=0){
    if(matrix[row][col]>target){
      col--;
    }
    else if(matrix[row][col]<target){
      row++;
    }
    else{
      return {row,col};
    }
  }
  return{-1,-1};
}
