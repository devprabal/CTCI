#ifndef STACK_H
#define STACK_H
template <class T, class T2> class Stack {
protected:
  T *top;

public:
  Stack();
  Stack(T2 data);
  T2 peek();
  void push(T2 data);
  T2 pop();
  bool isEmpty();
  T *getTopNode();
};
#endif