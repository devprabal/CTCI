#include "Stack.h"
#include "Queue.h"
#include "Node.h"
/**
 * @brief prints out the stack elements till it encounters NULL
 * 
 * @tparam T the Node datatype, Node contains 'data' and 'next' fields
 * @tparam T2 the datatype for 'data' in Node
 * @param myStack pointer to the Stack object
 */
template <class T, class T2> void printStack(Stack<T, T2>* myStack);
/**
 * @brief prints out the queue elements till it encounters NULL
 * 
 * @tparam T the Node datatype, Node contains 'data' and 'next' fields
 * @tparam T2 the datatype for 'data' in Node
 * @param myQueue pointer to the Queue object
 */
template <class T, class T2> void printQueue(Queue<T,T2>* myQueue);
