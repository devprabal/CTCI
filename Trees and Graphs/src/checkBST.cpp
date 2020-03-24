#include <iostream>
#include <vector>
using namespace std;
struct Node {
  int data;
  Node *left;
  Node *right;
};
/**
 * METHOD 1 
 * See if the inorder traversal is a non-decreasing list
 * O(n) time 
 * O(n+H) space ?
 * H for recursive function call and n for storing the elements in vector ?
 */
vector<int> treeElements;
void inorderTraversal(Node *root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    treeElements.push_back(root->data);
    inorderTraversal(root->right);
  }
}
bool checkBST(const vector<int> &treeElements) {
  vector<int>::const_iterator it = treeElements.begin();
  it++;
  for (; it != treeElements.end(); it++) {
    if (*it < *(it - 1)) {
      return false;
    }
  }
  return true;
}

/**
 * METHOD 2
 * Recursive, using min and max values at each node
 * O(n) time and O(H) space, H may not be equal to log n
 **/

bool checkBST_method2(Node* root, int min, int max){
    if(root == nullptr)
        return true;
    if(root->data < min || root->data > max)
        return false;
    return checkBST_method2(root->left,min,root->data) && checkBST_method2(root->right,root->data +1,max);
    // +1 is used to avoid duplicate values on right subtree, but duplicate values are allowed on the left subtree
    
}

int main(int argc, char const *argv[]) {
  Node *root = new Node;
  root->data = 8;
  root->left = new Node;
  root->left->data = 4;
  root->left->left = nullptr;
  root->left->right = nullptr;
  root->right = nullptr;
  Node *node4 = root->left;
  node4->left = new Node;
  node4->left->data = 3;
  node4->left->left = nullptr;
  node4->left->right = nullptr;
  root->right = new Node;
  Node* node22 = root->right;
  node22->data = 22;
  node22->left = new Node;
  node22->left->data = 16;
  node22->right = nullptr;
  node22->left->left = nullptr;
  node22->left->right = nullptr;

  inorderTraversal(root);
  cout << (checkBST(treeElements) ? "true\n" : "false\n");
  cout << (checkBST_method2(root,INT8_MIN, INT8_MAX) ? "true\n" : "false\n");
  for(vector<int>::iterator it = treeElements.begin();it!=treeElements.end();++it){
      cout<<*it<<" ";
  }
  cout<<"\n";
  return 0;
}
