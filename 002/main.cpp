#include <iostream>
#include "LinkList.h"
#include "Node.h"

using namespace std;

LinkList *intersection(LinkList *s1, LinkList *s2);

int main() {
    int t = 2;//
    int num = 0;//节点数据
    Node *tNode;
    LinkList *s1 = new LinkList;
    LinkList *s2 = new LinkList;


    while (1) {
        cin >> num;
        if (num == -1) {
            break;
        } else {
            tNode = new Node(num);
            s1->insertAsLast(tNode);
        }
    }

    while (1) {
        cin >> num;
        if (num == -1) {
            break;
        } else {
            tNode = new Node(num);
            s2->insertAsLast(tNode);
        }
    }

    LinkList *s3 = intersection(s1,s2);

    s3->traverse();
    return 0;
}

LinkList *intersection(LinkList *s1, LinkList *s2) {
    Node *tNode;
    LinkList *s3 = new LinkList;
    auto p1 = s1->header->next, p2 = s2->header->next;
    while (p1 != s1->trailer && p2 != s2->trailer) {
        if (p1->getNum() == p2->getNum()) {
            tNode = new Node(p1->getNum());
            s3->insertAsLast(tNode);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->getNum() > p2->getNum()) {
            p2 = p2->next;
        } else {
            p1 = p1->next;
        }
    }
    return s3;
}