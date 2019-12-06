//
// Created by lxd on 2019/10/27.
//

#ifndef INC_005_QUEUE_H
#define INC_005_QUEUE_H


struct Node {
    int data;
    Node *next;
    Node *pre;
};

//链表实现队列（我爱链表
class Queue {
private:
    int _size;//队列长度
    Node *head;
    Node *trail;

public:
    Queue();

    int size() { return _size; }

    int front();//返回头节点的值
    void pop();//头元素出队
    void push(int t);//元素入队
    bool empty() { return !_size; };


};

Queue::Queue() {
    _size = 0;
    head = new Node;
    trail = new Node;
    head->pre = nullptr;
    head->next = trail;
    trail->pre = head;
    trail->next = nullptr;
}

//在队伍尾巴插入
void Queue::push(int t) {
    auto p = new Node;
    p->data = t;
    p->pre = trail->pre;
    p->next = trail;
    p->pre->next = p;
    trail->pre = p;
    _size++;
}

int Queue::front() {
    return head->next->data;
}

void Queue::pop() {
    auto p = head->next;
    head->next = p->next;
    p->next->pre = head;
    _size--;
    delete p;
}

#endif //INC_005_QUEUE_H
