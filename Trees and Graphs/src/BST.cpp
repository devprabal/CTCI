#include "Node.h"
#include "traversal.h"
#include <iostream>
using namespace std;
/**
 * @brief add a new Node in Binary Search Tree
 *
 * @tparam T the datatype of data in Node
 * @param root the Node* pointer to the root of the tree
 * @param data the datavalue to be added
 * @return Node<T>* root of the tree
 */
template <typename T> Node<T> *add(Node<T> *root, T data) {
  if (root == NULL) {
    root = new Node<T>;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
  } else {
    if (root->data < data) {
      root->right = add(root->right, data);
    } else {
      root->left = add(root->left, data);
    }
  }
  return root;
}
/**
 * @brief searches for a node with specified data in Binary Search Tree
 *
 * @tparam T the datatype of the data in Node
 * @param root the Node* pointer to the root of the tree
 * @param data the data value to be searched
 * @return Node<T>* the Node* ptr to the Node where data is present or else NULL
 */
template <typename T> Node<T> *search(Node<T> *root, T data) {
  if (root != NULL) {
    if (root->data == data) {
      return root;
    } else {
      if (root->data < data) {
        return search(root->right, data);
      } else {
        return search(root->left, data);
      }
    }
  } else {
    return NULL;
  }
}
/**
 * @brief finds the Node which has the minimum value of data among all Nodes in
 * the tree
 *
 * @tparam T the datatype of the data in Node
 * @param root the Node* ptr to the root of the tree
 * @return Node<T>* the Node* ptr to Node which has the minimum data value
 */
template <typename T> Node<T> *findMinValueNode(Node<T> *root) {
  if (root != NULL) {
    if (root->left == NULL) {
      return root;
    } else {
      return findMinValueNode(root->left);
    }
  } else {
    return NULL;
  }
}
/**
 * @brief deletes a Node with the specified data if that Node is present in the
 * Binary Search Tree
 *
 * @tparam T the datatype of the data present in Node
 * @param root the Node* ptr to the root of the tree
 * @param data the data value to be deleted
 * @return Node<T>* pointer to the root of the tree
 */
template <typename T> Node<T> *remove(Node<T> *root, T data) {
  // https://www.youtube.com/watch?v=gcULXE7ViZw
  if (root == NULL) {
    return NULL;
  } else if (root->data < data) {
    root->right = remove(root->right, data);
  } else if (root->data > data) {
    root->left = remove(root->left, data);
  } else {
    // no child present
    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
      return root;
    }
    // right child only present
    else if (root->left == NULL && root->right != NULL) {
      Node<T> *tempnodeptr = root->right;
      delete root;
      root = NULL;
      return tempnodeptr;
    }
    // left child only present
    else if (root->left != NULL && root->right == NULL) {
      Node<T> *tempnodeptr = root->left;
      delete root;
      root = NULL;
      return tempnodeptr;
    }
    // both children present
    else {
      Node<T> *tempnodeptr = findMinValueNode(root->right);
      root->data = tempnodeptr->data;
      root->right = remove(root->right, tempnodeptr->data);
      return root;
    }
  }
  return root;
}
int main(int argc, char const *argv[]) {
  Node<int> *root = NULL;
  root = add(root, 8);
  root = add(root, 12);
  root = add(root, 4);
  root = add(root, 2);
  root = add(root, 18);
  root = add(root, 6);
  cout << '\n';
  inorderTraversal(root);
  cout << '\n';
  cout << "\n**********************************************\n";
  Node<int> *temp = search(root, 12);
  cout << temp->data;
  cout << "\n**********************************************\n";
  temp = findMinValueNode(root);
  cout << temp->data;
  cout << "\n**********************************************\n";
  root = remove(root, 8);
  root = remove(root, 12);
  root = remove(root, 6);
  root = remove(root, 4);
  cout << "\n**********************************************\n";
  cout << '\n';
  inorderTraversal(root);
  cout << '\n';
  return 0;
}
