//
// Created by lxd on 2019-09-18.
//

#ifndef DATA_STRUCTURE_LINKLIST_H
#define DATA_STRUCTURE_LINKLIST_H


#include "Node.h"

class LinkList {

private:
    int _size;//规模
    Node *header;//头哨兵
    Node *trailer;//尾哨兵

public:
    LinkList();

    ~LinkList();

    Node *insertAtPos(int pos);//在某个位置插入
    Node *insertAsLast(Node *t);//在最后插入
    void remove(int num);//按考号删除考生位置
    Node *find(int num);//按学号查找 返回对象
    Node *change(int num);//按学号修改内容
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

Node *LinkList::insertAsLast(Node *t) {
    _size++;
    trailer->insertAsPred(t);
}

Node *LinkList::insertAtPos(int pos) {

    auto temp = this->header;//头哨兵
    while (--pos) {
        temp = temp->next;//现在要在他的后面插入
        if (temp == this->trailer || nullptr) {
            std::cout << "您输入的位置有误，请重新输入\n";
            return nullptr;
        }
    }

    std::cout << "请依次输入考生的考号、姓名、性别、年龄及报考类别\n";
    int number;
    std::string name;//姓名
    std::string sex;//性别
    int age;//年龄
    std::string type;//报考科目
    std::cin >> number >> name >> sex >> age >> type;
    auto stu = new Node(number, name, sex, age, type);
    _size++;
    temp->insertAsNext(stu);
    return stu;

}

void LinkList::traverse() {
    auto p = this->header->next;
    for (; p != this->trailer; p = p->next) {
        p->getInform();
    }
}

void LinkList::remove(int num) {
    auto p = this->header->next;
    while (p != this->trailer && p->getNumber() != num) {
        p = p->next;
    }
    if (p->getNumber() == num) {
        std::cout << "您要删除的考生信息是：\n";
        p->getInform();
        std::cout << '\n';
        p->pre->next = p->next;
        p->next->pre = p->pre;
        //delete p;
        _size--;
    } else {
        std::cout << "您的输入有误\n";
    }
}

Node *LinkList::find(int num) {
    auto p = this->header->next;
    while (p != this->trailer && p->getNumber() != num) {
        p = p->next;
    }
    if (p->getNumber() == num) {
        p->getInform();
        return p;
    } else {
        std::cout << "您输入的信息有误\n";
        return nullptr;
    }
}

Node *LinkList::change(int num) {
    auto p = this->header->next;
    while (p != this->trailer && p->getNumber() != num) {
        p = p->next;
    }
    if (p->getNumber() == num) {
        p->getInform();
        std::cout << "请依次输入修改之后的学号 姓名 性别 年龄 报考类别：\n";
        p->setInform();
        return p;
    } else {
        std::cout << "您输入的信息有误\n";
        return nullptr;
    }
}

#endif //DATA_STRUCTURE_LINKLIST_H
