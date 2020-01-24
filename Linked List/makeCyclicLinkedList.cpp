#include<iostream>
#include"Node.h"
#include"makeCyclicLinkedList.h"
#include"random_x_y.h"
Node *makeCyclicLinkedList(int indexOfCycle, int noOfNodes) {
  if (indexOfCycle <= noOfNodes) {
    Node *head = new Node(random_x_y(0,10)); // first node here
    for (int i = 1; i < noOfNodes; i++) {
      head = head->addTail(random_x_y(0,10), head);
    }
    // finding last node to link to the node of start of cycle
    Node *p = head;
    while (p->getNext() != NULL) {
      p = p->getNext();
    }
    // node of start of cycle
    Node *q = head;
    int count = 0;
    while (count != indexOfCycle) {
      q = q->getNext();
      count++;
    }
    p->setNext(q); // form a cycle
    return head;
  } else {
    return NULL;
  }
}