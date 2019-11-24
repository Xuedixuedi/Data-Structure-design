//
// Created by lxd on 2019/11/22.
//


//用邻接矩阵建立图
//用克鲁斯卡尔法构造最小生成树
#ifndef INC_008_GRAPH_H
#define INC_008_GRAPH_H


class Graph {
private:
    int _size;//顶点数
    char *_name;//储存顶点名称的数组
    int **_matrix;//邻接矩阵表示
public:
    Graph(int size, char *name, int **matrix = nullptr) :
            _size(size), _name(name), _matrix(matrix) {}

};


#endif //INC_008_GRAPH_H
