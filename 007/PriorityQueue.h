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


class PriorityQueue {
private:
    int _size;
    int *_data;//层序遍历的最小堆

    int parent(int i) { return ((i - 1) >> 1); }//返回下标为i的节点的父节点
    int lChild(int i) {
        return (1 + (i << 1));
    }

    int rChild(int i) {
        return ((1 + i) << 1);
    }

    bool inHeap(int i) { return i >= 0 && i < _size; }

    void swap(int i, int j);//交换

public:
    PriorityQueue() {
        _size = 0;
        _data = nullptr;
    };

    explicit PriorityQueue(int size) {
        _size = size;
        _data = new int[size];
        _data[size] = {0};
    };

    int size() { return _size; }

    int top() { return _data[0]; };

    void pop();//弹出顶部元素

    void insert(int n);//插入元素
};

void PriorityQueue::swap(int i, int j) {
    int temp;
    temp = _data[i];
    _data[i] = _data[j];
    _data[j] = temp;
}

void PriorityQueue::insert(int n) {
    if (_size == 0) {
        _data[0] = n;
        _size++;
        return;
    }
    _data[_size] = n;
    int i = _size;
    _size++;
    while (i > 0) {
        int j = parent(i);//j是i的父亲节点的秩
        if (_data[j] > _data[i]) {
            swap(i, j);
            i = j;
        } else {
            break;
        }
    }

}

void PriorityQueue::pop() {
    swap(0, _size - 1);
    _data[_size - 1] = 0;
    _size--;
    int i = 0;
    while (inHeap(i)) {
        int j = lChild(i);
        int k = rChild(i);//k一定>j
        int t;
        if (inHeap(k)) {
            if (_data[j] < _data[k]) {
                t = j;
            } else {
                t = k;
            }
        } else if (inHeap(j)) {
            t = j;
        } else {
            break;
        }
        if (_data[t] < _data[i]) {
            swap(i, t);
            i = t;
        } else {
            break;
        }
    }
}

#endif //INC_007_PRIORITYQUEUE_H
