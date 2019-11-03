//
// Created by lxd on 2019/10/28.
//

#ifndef INC_006_BINNODE_H
#define INC_006_BINNODE_H

#include <string>

//二叉树的节点类
template<typename T>
class BinNode {
private:
    T _data;//数据
    BinNode *parent, *lChild, *rChild;//父亲 左孩子，右孩子
    int _height;//高度
public:
    BinNode() : parent(nullptr), lChild(nullptr), rChild(nullptr), _height(0) {}

    BinNode(T data, BinNode<T> *p = nullptr, BinNode<T> *lc = nullptr,
            BinNode<T> *rc = nullptr, int h = 0) :
            _data(data), parent(p), lChild(lc), rChild(rc), _height(h) {}

    int size();//以当前节点为根节点的后代规模
    T data() { return this->_data; }//返回该节点的数据

    BinNode *insertAsLC(T t);

    BinNode *insertAsRC(T t);
};

template<typename T>
int BinNode<T>::size() {

}

template<typename T>
BinNode<T> *BinNode<T>::insertAsLC(T t) {
    return this->rChild = new BinNode(t, this);
}

template<typename T>
BinNode<T> *BinNode<T>::insertAsRC(T t) {
    return this->rChild = new BinNode(t, this);
}

#endif //INC_006_BINNODE_H

