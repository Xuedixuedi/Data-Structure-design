//
// Created by lxd on 2019/10/5.
//

#ifndef INC_002_LINKLIST_H
#define INC_002_LINKLIST_H

#include "Node.h"

class LinkList {
private:
    int _size;
public:
    Node *header;//头节点
    Node *trailer;//尾节点

    LinkList();

    void insertAsLast(Node *t);//将该节点插入在链表的最后
    void traverse();//统计
};

LinkList::LinkList() {
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    header->pre = nullptr;
    trailer->next = nullptr;
    trailer->pre = header;
    _size = 0;
}

void LinkList::insertAsLast(Node *t) {
    trailer->insertAsPre(t);
    this->_size++;
}

void LinkList::traverse() {
    if (_size == 0) {
        std::cout << "NULL";
    } else {
        auto p = this->header->next;
        for (; p != this->trailer; p = p->next) {
            std::cout << p->getNum();
            if (p->next != this->trailer) {
                std::cout << ' ';
            }
        }
    }

}

#endif //INC_002_LINKLIST_H
