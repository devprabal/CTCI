#include <iostream>
using namespace std;
/*
this is independent program file, can be compiled and run independently.
For a dependent version (much cleaner) of this program, see AnimalShelter.cpp
*/
typedef struct date_of_arrival {
  int dd;
  int mm;
  int yyyy;
  bool operator<(date_of_arrival const &other) {

    if (yyyy < other.yyyy)
      return true;
    if (yyyy == other.yyyy && mm < other.mm)
      return true;
    if (yyyy == other.yyyy && mm == other.mm && dd < other.dd)
      return true;
    return false;
  }
} date;

struct AnimalQueueNode {
  char type;
  date ddmmyyyy;
  AnimalQueueNode *next;
};

class AnimalQueue {
private:
  AnimalQueueNode *front;
  AnimalQueueNode *rear;

public:
  AnimalQueue() {}
  AnimalQueue(AnimalQueueNode data) {
    front = new AnimalQueueNode;
    front->type = (data.type == 'd') ? 'd' : 'c';
    front->ddmmyyyy = data.ddmmyyyy;
    front->next = NULL;
  }
  void enqueue(AnimalQueueNode data) {
    AnimalQueueNode *temp = new AnimalQueueNode;
    temp->ddmmyyyy = data.ddmmyyyy;
    temp->type = data.type;
    temp->next = NULL;
    if (this->isEmpty()) {
      front = temp;
      rear = front;
    } else {
      rear->next = temp;
      rear = temp;
    }
  }
  AnimalQueueNode *deque() {
    if (!this->isEmpty()) {
      AnimalQueueNode *temp = front;
      front = front->next;
      return temp;
    } else {
      cout << "\nQueue Empty. There are no animals.";
      exit(EXIT_FAILURE);
    }
  }
  bool isEmpty() { return front == NULL; }
  date getOldestDate() {
    if (!this->isEmpty()) {
      return front->ddmmyyyy;
    }
  }
  AnimalQueueNode *getFrontAnimal() {
    if (!isEmpty())
      return front;
    return NULL;
  }
};
class AnimalShelter {
private:
  static AnimalQueue *dog;
  static AnimalQueue *cat;

public:
  void enqueue(AnimalQueueNode data) {
    if (data.type == 'd') {
      dog->enqueue(data);
    }
    if (data.type == 'c') {
      cat->enqueue(data);
    }
  }
  AnimalQueueNode *dequeAny() {
    if (dog->getFrontAnimal() != NULL && cat->getFrontAnimal() != NULL) {
      if (dog->getOldestDate() < cat->getOldestDate())
        return dequeDog();
      else
        return dequeCat();
    }
    if (dog->getFrontAnimal() == NULL && cat->getFrontAnimal() != NULL) {
      return dequeCat();
    }
    if (dog->getFrontAnimal() != NULL && cat->getFrontAnimal() == NULL) {
      return dequeDog();
    }
    return NULL;
  }
  void printQueue(char type) {
    AnimalQueueNode *animal;
    AnimalQueueNode *animal2;
    if (type == 'd') {
      animal = dog->getFrontAnimal();
    } else if (type == 'c') {
      animal = cat->getFrontAnimal();
    } else {
      animal = dog->getFrontAnimal();
      animal2 = cat->getFrontAnimal();
    }
    cout << '\n';
    if (type == 'd' || type == 'c') {
      while (animal != NULL) {
        cout << animal->type
             << ":"
                "{"
             << animal->ddmmyyyy.dd;
        cout << " " << animal->ddmmyyyy.mm;
        cout << " " << animal->ddmmyyyy.yyyy << "}";
        animal = animal->next;
        cout << '\n';
      }
    } else {
      while (animal != NULL && animal2 != NULL) {
        if (animal->ddmmyyyy < animal2->ddmmyyyy) {
          cout << animal->type << ":"
               << "{" << animal->ddmmyyyy.dd;
          cout << " " << animal->ddmmyyyy.mm;
          cout << " " << animal->ddmmyyyy.yyyy << "}";
          cout << '\n';
          animal = animal->next;
        } else {
          cout << animal2->type << ":"
               << "{" << animal2->ddmmyyyy.dd;
          cout << " " << animal2->ddmmyyyy.mm;
          cout << " " << animal2->ddmmyyyy.yyyy << "}";
          cout << '\n';
          animal2 = animal2->next;
        }
      }
      if (animal2 == NULL && animal != NULL) {
        while (animal != NULL) {
          cout << animal->type << ":"
               << "{" << animal->ddmmyyyy.dd;
          cout << " " << animal->ddmmyyyy.mm;
          cout << " " << animal->ddmmyyyy.yyyy << "}";
          animal = animal->next;
          cout << '\n';
        }
      }
      if (animal == NULL && animal2 != NULL) {
        while (animal2 != NULL) {
          cout << animal2->type << ":"
               << "{" << animal->ddmmyyyy.dd;
          cout << " " << animal->ddmmyyyy.mm;
          cout << " " << animal->ddmmyyyy.yyyy << "}";
          animal2 = animal2->next;
          cout << '\n';
        }
      }
    }
  }
  AnimalQueueNode *dequeDog() { return dog->deque(); }
  AnimalQueueNode *dequeCat() { return cat->deque(); }
};

AnimalQueue *AnimalShelter::dog = new AnimalQueue();
AnimalQueue *AnimalShelter::cat = new AnimalQueue();

// int main(int argc, char const *argv[]) {
//   AnimalShelter *petcare = new AnimalShelter();
//   petcare->enqueue({'d', {1, 1, 2018}, NULL});
//   petcare->enqueue({'d', {1, 2, 2018}, NULL});
//   petcare->enqueue({'d', {14, 4, 2018}, NULL});
//   petcare->enqueue({'d', {16, 6, 2018}, NULL});
//   petcare->enqueue({'d', {30, 12, 2019}, NULL});

//   petcare->enqueue({'c', {30, 1, 2018}, NULL});
//   petcare->enqueue({'c', {28, 2, 2018}, NULL});
//   petcare->enqueue({'c', {12, 4, 2018}, NULL});
//   petcare->enqueue({'c', {11, 6, 2018}, NULL});
//   petcare->enqueue({'c', {13, 12, 2019}, NULL});
//   petcare->enqueue({'c', {29, 12, 2019}, NULL});
//   petcare->printQueue('d');
//   cout << "****************************************************";
//   petcare->printQueue('c');
//   cout << "****************************************************";
//   petcare->printQueue('a');
//   AnimalQueueNode *temp;
//   cout << '\n';
//   while ((temp = petcare->dequeAny()) != NULL) {
//     cout << temp->type << ":"
//          << "{" << temp->ddmmyyyy.dd;
//     cout << " " << temp->ddmmyyyy.mm << " ";
//     cout << temp->ddmmyyyy.yyyy << "}";
//     cout << '\n';
//   }
//   return 0;
// }
