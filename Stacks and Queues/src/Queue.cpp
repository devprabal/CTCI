#include "Queue.h"
#include "Node.h"
#include "AnimalData.h"
#include <iostream>
template <class T, class T2> Queue<T,T2>::Queue() {}
template <class T, class T2> Queue<T,T2>::Queue(T2 data) {
  front = new T;
  front->data = data;
  front->next = NULL;
  rear = front;
}
template <class T, class T2> void Queue<T, T2>::add(T2 data) {
  T *temp = new T;
  temp->data = data;
  temp->next = NULL;
  if (front == NULL && rear == NULL) {
    front = temp;
    rear = front;
  } else {
    rear->next = temp;
    rear = temp;
  }
}
template <class T, class T2> T2 Queue<T,T2>::remove() {
  if (isEmpty()) {
    std::cout << "\nQueue Empty";
    // FIXME: I think it would be better if we throw some
    // error instead of quiting.
    exit(EXIT_FAILURE);
  }
  if (front == rear) {
    T2 temp = front->data;
    delete front;
    front = NULL;
    rear = NULL;
    return temp;
  } else {
    T2 temp = front->data;
    T *tempptr = front->next;
    delete front;
    front = tempptr;
    return temp;
  }
}
template <class T, class T2> bool Queue<T,T2>::isEmpty() { return front == NULL && rear == NULL; }
template <class T, class T2> T2 Queue<T,T2>::peekFront() {
  if (!isEmpty())
    return front->data;
  else {
    std::cout << "\nQueue Empty";
    // FIXME: I think it would be better if we throw some
    // error instead of quiting.
    // We could return null if the return-type was a pointer
    exit(EXIT_FAILURE);
  }
}
template <class T, class T2> T2 Queue<T, T2>::peekRear() {
  if (!isEmpty())
    return rear->data;
  else {
    std::cout << "\nQueue Empty";
    // FIXME: I think it would be better if we throw some
    // error instead of quiting.
    // We could return null if the return-type was a pointer
    exit(EXIT_FAILURE);
  }
}
template <class T, class T2> T *Queue<T, T2>::getFrontNode() { return front; }

//explicit instantiation
template class Queue<Node<int>, int>;
template class Queue<Node<AnimalData>,AnimalData>;