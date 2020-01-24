#include "Node.h"
#include <iostream>
Node::Node() {}
Node::Node(int data) {
  this->data = data;
  this->next = NULL;
}
Node *Node::addHead(int data, Node *head) {
  Node *temp = new Node(data);
  if (head != NULL) {
    temp->next = head;
    head = temp;
  } else {
    head = temp;
  }
  return head;
}
Node *Node::addTail(int data, Node *head) {
  Node *temp = new Node(data);
  if (head != NULL) {
    Node *p = head;
    while (p->next != NULL)
      p = p->next;

    p->next = temp;
  } else {
    head = temp;
  }
  return head;
}
Node *Node::getNext() { return this->next; }
int Node::getData() { return this->data; }
void Node::setNext(Node *node) { this->next = node; }