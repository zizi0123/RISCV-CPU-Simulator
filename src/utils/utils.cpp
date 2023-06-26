#include "utils.h"

MyQueue::MyQueue() : front(0), rear(0) {}

bool MyQueue::EnQueue(const RoBEle &x) {
    if (this->Full()) return false;
    rear = (rear + 1) % MaxSize;
    queue[rear] = x; //循环队列头空尾不空
}

bool MyQueue::DeQueue() {
    if (this->Empty()) return false;
    front = (front + 1) % MaxSize;
}

bool MyQueue::Full() {
    return (rear + 1) % MaxSize == front;
}

bool MyQueue::Empty() {
    return front == rear;
}

RoBEle &MyQueue::Front() {
    return queue[front+1];
}

RoBEle &MyQueue::Back() {
    return queue[rear];
}
