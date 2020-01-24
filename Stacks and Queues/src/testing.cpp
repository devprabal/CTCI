#include<iostream>
#include"Stack.h"
#include "Queue.h"
#include "Node.h"
#include"printStackOrQueue.h"
#include <cstdlib>
int random_x_y(int lower, int upper){
    return lower+rand()%(upper - lower);
}
using namespace std;
// int main(int argc, char const *argv[])
// {

//     Stack<Node<int>, int>* myStack = new Stack<Node<int>, int>();
//     for(int i=0;i<8;i++)
//         myStack->push(random_x_y(0,10));
//     Queue<Node<int>, int>* myQueue = new Queue<Node<int>, int>();
//     for (int i = 0; i < 8; i++)
//     {
//         myQueue->add(random_x_y(0,10));
//     }
//     printStack(myStack);
//     cout<<"***********************************************";
//     printQueue(myQueue);
    
     
//     return 0;
// }
