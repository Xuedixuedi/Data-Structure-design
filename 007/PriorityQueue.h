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

    Node() = default;

    Node(int t);

    bool operator<=(const Node *a) {
        return _data < a->_data || _data == a->_data;
    }
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
    void push(int t);//放入元素（并排序,从小到大
};

PriorityQueue::PriorityQueue() {
    _header = new Node;
    _trailer = new Node;
    _header->next = _trailer;
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
    if (this->empty()) {
        p->next = _header->next;
        this->_header->next = p;
        _size++;
        return;
    } else {
        auto it = this->_header;//从第一个数据开始
        while (it->next != _trailer) {
            if (p <= it->next) {
                p->next = it->next;
                it->next = p;
                _size++;
                return;
            } else {
                it = it->next;
            }
        }
        p->next = it->next;
        it->next = p;
        _size++;
        return;
    }
}

#endif //INC_007_PRIORITYQUEUE_H
