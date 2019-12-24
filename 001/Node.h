//
// Created by lxd on 2019-09-18.
//

#ifndef DATA_STRUCTURE_NODE_H
#define DATA_STRUCTURE_NODE_H

#include <iostream>
#include <string>


class Node {
private:
    int _number;//考号
    std::string _name;//姓名
    std::string _sex;//性别
    int _age;//年龄
    std::string _type;//报考科目



public:
    Node *next;//后继指针
    Node *pre;//前驱指针

    Node() = default;

    Node(int number, std::string name, std::string sex, int age, std::string type);//初始化s
    ~Node();

    Node *insertAsPred(Node *t);//紧接着该节点后面 插入新节点
    Node *insertAsNext(Node *t);//紧接着这个节点前面 插入新的
    void getInform();

    void setInform();

    int getNumber() { return this->_number; }
};


Node::Node(int number, std::string name, std::string sex, int age, std::string type) {
    this->_number = number;
    this->_name = name;
    this->_sex = sex;
    this->_age = age;
    this->_type = type;

}

Node *Node::insertAsPred(Node *t) {
    this->pre->next = t;
    t->pre = this->pre;
    this->pre = t;
    t->next = this;
    return t;
}

Node *Node::insertAsNext(Node *t) {
    this->next->pre = t;
    t->next = this->next;
    this->next = t;
    t->pre = this;
    return t;
}

void Node::getInform() {
    std::cout << this->_number << " \t"
              << this->_name << " \t"
              << this->_sex << " \t"
              << this->_age << " \t"
              << this->_type << " \t"
              << '\n';
}

void Node::setInform() {
    std::cin >> _number >> _name >> _sex >> _age >> _type;
}

#endif //DATA_STRUCTURE_NODE_H
