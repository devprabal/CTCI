#include "traversal.h"
#include <iostream>
using namespace std;
template <typename T> void inorderTraversal(Node<T> *root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
  }
}
template <typename T> void preorderTraversal(Node<T> *root) {
  if (root != NULL) {
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}
template <typename T> void postorderTraversal(Node<T> *root) {
  if (root != NULL) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
  }
}
//explicit instantiation
template void inorderTraversal<int>(Node<int>*);
template void postorderTraversal<int>(Node<int>*);
template void preorderTraversal<int>(Node<int>*);