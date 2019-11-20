//
// Created by lxd on 2019/11/17.
//

#ifndef INC_007_PRIORITYQUEUE_H
#define INC_007_PRIORITYQUEUE_H


#include <iostream>

//优先级队列实现
//先将给出的长度排序（优先级队列实现，从小到大
//然后取最小的两个相加，得到的结果放入队列接着排队
//直到输出结果 嘿嘿！

struct Node {
    int _data;//数据
    Node *next;
    Node *pre;

    Node() = default;

    explicit Node(int t);

};

Node::Node(int t) {
    this->_data = t;
    next = nullptr;
}

class PriorityQueue {
private:
    int _size;//规模
public:
    Node *_header;//头哨兵
    Node *_trailer;//尾哨兵
    PriorityQueue();

    bool empty() { return !_size; }

    int size() { return _size; }

    int top();//返回该队列优先级最高的元素
    void pop();//弹出队列优先级最高的元素
    void push(int t);//放入元素
    void sort();
};

PriorityQueue::PriorityQueue() {
    _header = new Node;
    _trailer = new Node;
    _header->next = _trailer;
    _trailer->pre = _header;
    _size = 0;
}

int PriorityQueue::top() {
    if (!empty()) {
        return this->_header->next->_data;
    } else {
        std::cout << "该队列为空" << std::endl;
        exit(-1);
    }
}

void PriorityQueue::pop() {
    if (!empty()) {
        auto p = this->_header->next;
        _header->next = p->next;
        p->next->pre = _header;
        delete p;
        _size--;
        return;
    } else {
        std::cout << "该队列为空" << std::endl;
        exit(-1);
    }
}

void PriorityQueue::push(int t) {
    auto p = new Node(t);
    auto q = _header->next;
    while (q != _trailer) {
        if (t <= q->_data) {
            p->next = q;
            p->pre = q->pre;
            q->pre->next = p;
            q->pre = p;
            _size++;
            break;
        }
        q = q->next;
    }
    if (q == _trailer) {
        p->next = q;
        p->pre = q->pre;
        q->pre->next = p;
        q->pre = p;
        _size++;
    }
}

void PriorityQueue::sort() {
    auto p = _header->next;
    auto q = p->next;
    int temp;
    while (p != _trailer) {
        for (q = p->next; q != _trailer; q = q->next) {
            if (q->_data < p->_data) {
                temp = p->_data;
                p->_data = q->_data;
                q->_data = temp;
            }
        }
        p = p->next;
    }
}

#endif //INC_007_PRIORITYQUEUE_H
