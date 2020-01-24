#include "printLinkedList.h"
#include "Node.h"
#include <iostream>
//FIXME: there is code duplication in if and else parts
void printLinkedList(Node *head, int numberOfELements /*= -1*/) {
  std::cout << '\n';
  if (numberOfELements != -1) {
    int counter = 0;
    while (head != NULL && counter != numberOfELements) {
      std::cout << head->getData() << "->";
      head = head->getNext();
      counter++;
    }
  } else {
    while (head != NULL) {
      std::cout << head->getData() << "->";
      head = head->getNext();
    }
  }
  std::cout << '\n';
}