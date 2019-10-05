#include <iostream>
#include "LinkList.h"
#include "Node.h"

using namespace std;

int main() {
    int t = 2;//
    int num = 0;//节点数据
    Node *tNode;
    LinkList *s1 = new LinkList;
    LinkList *s2 = new LinkList;
    LinkList *s3 = new LinkList;

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
    s3->traverse();
    return 0;
}