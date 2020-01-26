#include "Node.h"
/**
 * @brief inorder tree traversal to print Node data in tree
 * 
 * @tparam T the datatype of data in Node
 * @param root the Node* pointer to the root of tree
 */
template <typename T> void inorderTraversal(Node<T> *root);
/**
 * @brief preorder tree traversal to print Node data in tree
 * 
 * @tparam T the datatype of data in Node
 * @param root the Node* pointer to the root of tree
 */
template <typename T> void preorderTraversal(Node<T> *root);
/**
 * @brief postorder tree traversal to print Node data in tree
 * 
 * @tparam T the datatype of data in Node
 * @param root the Node* pointer to the root of tree
 */
template <typename T> void postorderTraversal(Node<T> *root);