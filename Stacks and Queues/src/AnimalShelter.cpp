#include "Node.h"
#include "Queue.h"
#include "printStackOrQueue.h"
#include "AnimalData.h"
#include <iostream>
using namespace std;

void printAnimalData(AnimalData animal) {
  cout << "\n{"  << animal.timestamp << " " << animal.type
       << "}\n";
}
//Overriding the function printQueue to handle printing of AnimalNode type of data
template <class T, class T2> void printQueue(Queue<T, T2> *myQueue) {
  if (myQueue != NULL) {
    T *front = myQueue->getFrontNode();
    std::cout << '\n';
    while (front != NULL) {
      printAnimalData(front->data);
      cout << "->";
      front = front->next;
    }
    std::cout << '\n';
  } else {
    std::cout << "\nEmpty.\n";
  }
}
void dequeAny(Queue<Node<AnimalData>, AnimalData> *dog,
              Queue<Node<AnimalData>, AnimalData> *cat) {
  Node<AnimalData> *dognode = dog->getFrontNode();
  Node<AnimalData> *catnode = cat->getFrontNode();
  if (dognode != NULL && catnode != NULL) {
    if (dognode->data.timestamp < catnode->data.timestamp) {
      printAnimalData(dog->remove());
    }
    else{
      printAnimalData(cat->remove());
    }
  }
  else if (dognode == NULL && catnode != NULL) {
    printAnimalData(cat->remove());
  }
  else if (dognode != NULL && catnode == NULL) {
    printAnimalData(dog->remove());
  }
  else{
    cout << "\n No Animal available. Queue Empty.\n";
  }
}

void dequeDog(Queue<Node<AnimalData>, AnimalData> *dog) {
  Node<AnimalData> *dognode = dog->getFrontNode();
  if (dognode != NULL) {
    printAnimalData(dog->remove());
  } else {
    cout << "\n Animal not available. Queue Empty. Maybe choose cat.\n";
  }
}
void dequeCat(Queue<Node<AnimalData>, AnimalData> *cat) {

  Node<AnimalData> *catnode = cat->getFrontNode();
  if (catnode != NULL) {

    printAnimalData(cat->remove());
  } else {
    cout << "\n Animal not available. Queue Empty. Maybe choose dog.\n";
  }
}

int main(int argc, char const *argv[]) {
  Queue<Node<AnimalData>, AnimalData> *dog =
      new Queue<Node<AnimalData>, AnimalData>();
  Queue<Node<AnimalData>, AnimalData> *cat =
      new Queue<Node<AnimalData>, AnimalData>();
  dog->add({ 1, 'd'});
  cat->add({ 4, 'c'});
  dog->add({ 2, 'd'});
  cat->add({ 5, 'c'});
  dog->add({ 3, 'd'});
  cat->add({ 6, 'c'});
  dog->add({ 9, 'd'});
  cat->add({ 7, 'c'});
  dog->add({ 10, 'd'});
  cat->add({ 8, 'c'});
  cat->add({ 11, 'c'});
  printQueue(dog);
  cout << "\n***************\n";
  printQueue(cat);
  cout << "\n***************\n";
  dequeAny(dog, cat);
  dequeAny(dog, cat);
  dequeAny(dog, cat);
  dequeDog(dog);
  dequeAny(dog, cat);
  dequeCat(cat);
  dequeAny(dog, cat);
  dequeAny(dog, cat);
  dequeDog(dog);
  dequeAny(dog, cat);
  dequeDog(dog);

  return 0;
}
