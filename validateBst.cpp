class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};
void inOrderTraverse(BST *tree, vector<int> &array) {
  // Write your code here.
  if(tree==NULL){
    return ;
  }
  inOrderTraverse(tree->left,array);
    array.push_back(tree->value);
  inOrderTraverse(tree->right,array);
}
bool validateBst(BST *tree) {
  // Write your code here.
vector<int>array;
  inOrderTraverse(tree,array);
  for(int i=0;i<array.size()-1;i++){
    if(array[i]>array[i+1]){
      return false;
    }
  }
  return true;
}
