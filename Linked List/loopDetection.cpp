#include "Node.h"
#include "makeCyclicLinkedList.h"
#include "printLinkedList.h"
#include <cstdlib> // for int rand()
#include <iostream>
using namespace std;
class Result {
public:
  Node *node;
  bool isLoopPresent;
  Result() {}
  Result(bool truth, Node *node) {
    this->isLoopPresent = truth;
    this->node = node;
  }
};
Result *loopDetection(Node *head) {
  Result *result = new Result(false, NULL);
  if (head == NULL) {
    return result;
  } else {
    Node *slow = head;
    Node *fast = head;
    // initially fast and slow will be same so, the while loop would never work
    // so we use do while
    do {
      slow = slow->getNext();
      fast = fast->getNext()->getNext();
    } while (slow != fast && fast != NULL &&
             fast->getNext()->getNext() != NULL);
    if (fast == NULL || fast->getNext()->getNext() == NULL) {
      return result;
    }
    fast = head;
    while (fast != slow) {
      fast = fast->getNext();
      slow = slow->getNext();
    }
    result->isLoopPresent = true;
    result->node = slow;
    return result;
  }
}
int findLoopIndex(Node *head, Node *loopNode) {
  int index = 0; // index starts at zero
  if (loopNode == NULL) {
    return -1; // signifies no valid index
  }
  while (head != loopNode) {
    index++;
    head = head->getNext();
  }
  return index;
}
int main(int argc, char const *argv[]) {
  // cycle start at index 2 and there are total 8 nodes in the linked list
  Node *head = makeCyclicLinkedList(2, 8);
  printLinkedList(head, 14);
  Result *result = loopDetection(head);
  cout << "\nis loop present: " << ((result->isLoopPresent) ? "true" : "false");
  cout << "\nloop starts at index: " << findLoopIndex(head, result->node)<<'\n';
  return 0;
}
