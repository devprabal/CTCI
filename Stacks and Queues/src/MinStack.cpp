// #include <iostream>
// #include "Stack.h"
// #include "printStackOrQueue.h"
// using namespace std;
// //FIXME: this implementation of MinStack is wrong
// class MinStack: public Stack{
//     protected:
//     int minElement;
// public:
//     int getMinElement();
//     void push(int data);
//     MinStack(int data):Stack(data){
//         minElement = data;
//     }
// };
// int MinStack::getMinElement(){
//     if(!isEmpty()){
//         return minElement;
//     }
        
//     else{
//         cout<<"\nStack Empty";
//         exit(EXIT_FAILURE);
//     }
        
// }
// void MinStack::push(int data){
//     if(!isEmpty()){
//         StackNode* temp = new StackNode;
//         temp->data = data;
//         temp->next = top;
//         minElement = (data<minElement)?data:minElement;
//         top = temp;
//     }
//     else{
//         top = new StackNode;
//         top->data = data;
//         top->next = NULL;
//         minElement = data;
//     }
// }
// // int MinStack::pop(){
// //     if(!isEmpty()){
// //         StackNode*  tempptr = top->next;
// //         int temp = top->data;
// //         delete top;
// //         top = tempptr;
// //         if(minElement==temp)
// //             minElement = nextMinElement;
// //         return temp;
// //     }
// //     else{
// //         cout<<"\nStack Empty";
// //         exit(EXIT_FAILURE);
// //     }
// // }
// int main(int argc, char const *argv[])
// {
//     MinStack myMinStack = MinStack(5);
//     myMinStack.push(9);
//     myMinStack.push(7);
//     myMinStack.push(4);
//     myMinStack.push(8);
    
    
//     return 0;
// }

