#include "printStackOrQueue.h"
#include <iostream>
template <class T, class T2> void printStack(Stack<T, T2> *myStack) {
  if (myStack != NULL) {
    T *top = myStack->getTopNode();
    std::cout << '\n';
    while (top != NULL) {
      // TODO: data can be any data type, not necessarily int or char, but also
      // user defined struct like AnimalData (which has fields like int and
      // char). Can we write a general function in place of the below line that
      // takes prints all the subfields of the data structure (like we did in
      // AnimalShelter.cpp where we overrode this function)? Would it become the
      // general task of parsing and printing a JSON data (What if those
      // subfields have sub-sub-fields?)?
      std::cout << top->data << "->";
      top = top->next;
    }
    std::cout << '\n';
  } else {
    std::cout << "\nEmpty.\n";
  }
}
template <class T, class T2> void printQueue(Queue<T, T2> *myQueue) {
  if (myQueue != NULL) {
    T *front = myQueue->getFrontNode();
    std::cout << '\n';
    while (front != NULL) {
        // TODO: data can be any data type, not necessarily int or char, but also
      // user defined struct like AnimalData (which has fields like int and
      // char). Can we write a general function in place of the below line that
      // takes prints all the subfields of the data structure (like we did in
      // AnimalShelter.cpp where we overrode this function)? Would it become the
      // general task of parsing and printing a JSON data (What if those
      // subfields have sub-sub-fields?)?
      std::cout << front->data << "->";
      front = front->next;
    }
    std::cout << '\n';
  } else {
    std::cout << "\nEmpty.\n";
  }
}

// explicit instantiation
template void printStack<Node<int>, int>(Stack<Node<int>, int> *);
template void printQueue<Node<int>, int>(Queue<Node<int>, int> *);