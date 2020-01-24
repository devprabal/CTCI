#include "Node.h"
/**
 * @brief makes a dummy circular linked list
 * 
 * @details the circulat linked list has random integer data by rand() function from cstdlib
 * @param indexOfCycle the position (starting index is zero) where the loop starts
 * @param noOfNodes the total number of nodes in the linked list
 * @return Node* head of linked list
 */
Node *makeCyclicLinkedList(int indexOfCycle, int noOfNodes);