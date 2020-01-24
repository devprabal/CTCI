#include "Stack.h"
#include "Node.h"
#include <iostream>
template <class T, class T2> Stack<T,T2>::Stack(){}
template <class T, class T2> Stack<T,T2>::Stack(T2 data) {
  top = new T;
  top->data = data;
  top->next = NULL;
}
template <class T, class T2> void Stack<T,T2>::push(T2 data) {
  T *temp = new T;
  temp->data = data;
  temp->next = top;
  top = temp;
}
template <class T, class T2> T2 Stack<T,T2>::pop() {
  if (isEmpty()) {
    std::cout << "\nStack Empty";
    // FIXME: I think it would be better if we throw some
    // error instead of quiting.
    // We could return null if the return-type was a pointer
    exit(EXIT_FAILURE);
  }
  T2 temp = top->data;
  T *tempptr = top->next;
  delete top;
  top = tempptr;
  return temp;
}
template <class T, class T2> bool Stack<T, T2>::isEmpty() { return top == NULL; }
template <class T, class T2> T2 Stack<T,T2>::peek() {
  if (isEmpty()) {
    std::cout << "\nStack Empty";
    // FIXME: I think it would be better if we throw some
    // error instead of quiting.
    exit(EXIT_FAILURE);
  }
  return top->data;
}
template <class T, class T2> T *Stack<T, T2>::getTopNode() { return top; }

//explicit instantiation
template class Stack<Node<int>, int>;
