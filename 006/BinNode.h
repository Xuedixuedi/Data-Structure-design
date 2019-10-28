//
// Created by lxd on 2019/10/28.
//

#ifndef INC_006_BINNODE_H
#define INC_006_BINNODE_H

#include <string>

//二叉树的节点类
class BinNode {
private:
    std::string data;//数据
    BinNode *parent, *lChild, *rChild;//父亲 左孩子，右孩子
    int height;
};


#endif //INC_006_BINNODE_H
