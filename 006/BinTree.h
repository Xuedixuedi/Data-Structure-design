//
// Created by lxd on 2019/10/28.
//

#ifndef INC_006_BINTREE_H
#define INC_006_BINTREE_H

#include "BinNode.h"
#include <stack>
#include <queue>

//左长子，右兄弟法
//用二叉树实现家谱储存
template<typename T>
class BinTree {
private:
    int _size;//树的规模
    BinNode<T> *_root;//根节点

public:
    BinTree() : _size(0), _root(nullptr) {}

    ~BinTree() { if (0 < _size) remove(_root); }

    int size() { return this->_size; }

    bool empty() { return !_size; }

    BinNode<T> *root() { return _root; }

    BinNode<T> *insertAsRoot(T t);//作为跟节点插入（初始化
    BinNode<T> *insertAsLC(BinNode<T> *x, T t);//作为x节点的左孩子插入，data=t
    BinNode<T> *insertAsRC(BinNode<T> *x, T t);//作为x节点的右孩子插入，data=t
    BinNode<T> *search(T t);//查找内容为t的某个元素(使用前序遍历）

    std::queue<BinNode<T> *> showChild(BinNode<T> *x);//输出这个节点的所有子一代,并用队列存储所有子一代
    void remove(BinNode<T> *p);//解散data为t的子🌲及他自身
};

template<typename T>
BinNode<T> *BinTree<T>::insertAsRoot(T t) {
    this->_root = new BinNode<T>(t);
    _size++;
}

template<typename T>
BinNode<T> *BinTree<T>::insertAsLC(BinNode<T> *x, T t) {
    x->insertAsLC(t);
    _size++;
}

template<typename T>
BinNode<T> *BinTree<T>::insertAsRC(BinNode<T> *x, T t) {
    x->insertAsRC(t);
    _size++;
}

template<typename T>
BinNode<T> *BinTree<T>::search(T t) {
    std::stack<BinNode<T> *> s;
    auto p = this->_root;
    s.push(p);
    while (!s.empty() || p != nullptr) {
        if (p->data() == t) {
            return p;
        } else {
            s.push(p);
            p = p->lChild;
            while (p == nullptr) {
                p = s.top();
                p = p->rChild;
                s.pop();
            }
        }

    }
}

template<typename T>
std::queue<BinNode<T> *> BinTree<T>::showChild(BinNode<T> *x) {
    std::queue<BinNode<T> *> child;
    if (x->lChild != nullptr) {
        std::cout << x->lChild->data() << "  ";
        child.push(x->lChild);
    } else {
        std::cout << "他没有子代" << std::endl;
    }
    while (x->rChild != nullptr) {
        child.push(x->rChild);
        std::cout << x->rChild->data() << "  ";
        x = x->rChild;
    }
    std::cout << std::endl;
    return child;
}

template<typename T>
void BinTree<T>::remove(BinNode<T> *p) {
    if (p == nullptr) {
        return;
    }
    if (p->lChild != nullptr) {
        remove(p->lChild);
    }
    if (p->rChild != nullptr) {
        remove(p->rChild);
    }
    delete p;
}

#endif //INC_006_BINTREE_H
