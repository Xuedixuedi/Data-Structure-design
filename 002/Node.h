//
// Created by lxd on 2019/10/5.
//

#ifndef INC_002_NODE_H
#define INC_002_NODE_H


class Node {
private:
    int _number;
public:
    Node *pre;
    Node *next;

    Node();

    Node(int number);

    int getNum();
    void insertAsPre(Node *t);//作为该节点的前驱插入
    void insertAsNext(Node *t);//作为该节点的后继插入
};

Node::Node() {
    _number = 0;
    this->pre = nullptr;
    this->next = nullptr;
}

Node::Node(int number) {
    this->_number = number;
    this->pre = nullptr;
    this->next = nullptr;
}

int Node::getNum() {
    return this->_number;
}

void Node::insertAsPre(Node *t) {
    t->pre = this->pre;
    t->next = this;
    this->pre->next = t;
    this->pre = t;
}

#endif //INC_002_NODE_H
