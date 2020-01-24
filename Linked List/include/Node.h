/**
 * @brief Node class for Linked List
 *
 */
#ifndef NODE_H
#define NODE_H
class Node {
private:
  int data;
  Node *next;

public:
  Node();
  Node(int);
  Node *addHead(int data, Node *head);
  Node *addTail(int data, Node *head);
  Node *getNext();
  int getData();
  void setNext(Node *node);
};
#endif
