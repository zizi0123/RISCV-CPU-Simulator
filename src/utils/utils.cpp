#include "utils.h"

template<class T,int a>
MyQueue<T,a>::MyQueue() : front(0), rear(0) {}

template<class T,int a>
bool MyQueue<T,a>::EnQueue(const T &x) {
    if (this->Full()) return false;
    rear = (rear + 1) % MaxSize;
    queue[rear] = x; //循环队列头空尾不空
    return true;
}

template<class T,int a>
bool MyQueue<T,a>::DeQueue() {
    if (this->Empty()) return false;
    front = (front + 1) % MaxSize;
    return true;
}

template<class T,int a>
bool MyQueue<T,a>::Full() {
    return (rear + 1) % MaxSize == front;
}

template<class T,int a>
bool MyQueue<T,a>::Empty() {
    return front == rear;
}
template<class T,int a>
T &MyQueue<T,a>::Front() {
    return queue[(front+1)%MaxSize];
}

template<class T,int a>
T &MyQueue<T,a>::Back() {
    return queue[rear];
}

template<class T, int a>
int MyQueue<T, a>::size() {
    int size = rear-front;
    if(size>=0) return size;
    return size+MaxSize;
}

template<class T, int a>
void MyQueue<T, a>::Clear() {
    front = rear = 0;
}


template class MyQueue<RoBEle,32>;

template class MyQueue<ReservationEle,5>;

template class MyQueue<SLEle,32>;
