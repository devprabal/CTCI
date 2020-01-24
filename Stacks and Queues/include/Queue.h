#ifndef QUEUE_H
#define QUEUE_H
template <class T, class T2> class Queue{
    private:
        T* front;
        T* rear;
    public:
        Queue();
        Queue(T2 data);
        T2 peekFront();
        T2 peekRear();
        T2 remove();
        void add(T2 data);
        bool isEmpty();
        T* getFrontNode();
};
#endif