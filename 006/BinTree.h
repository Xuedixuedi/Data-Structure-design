//
// Created by lxd on 2019/10/28.
//

#ifndef INC_006_BINTREE_H
#define INC_006_BINTREE_H

#include "BinNode.h"

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


#endif //INC_006_BINTREE_H
