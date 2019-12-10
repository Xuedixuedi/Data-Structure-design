//
// Created by lxd on 2019/11/22.
//

//用邻接矩阵建立图
//用Prim法构造最小生成树
#ifndef INC_008_GRAPH_H
#define INC_008_GRAPH_H

class Graph {
   private:
    char *_name;         //储存顶点名称的数组
    int **_matrix;       //邻接矩阵表示
    bool **_primMatrix;  //最小生成树的边
    int _size;           //顶点数
    int *_parent;        //最小生成树里面的父节点
    bool *_visit;
    int *_score;
    int _sum;  //最短路径和

   public:
    Graph() = default;
    // Graph(int size, char *name, int **matrix = nullptr)
    //     : _size(size), _name(name), _matrix(matrix) {}
    Graph(int size, char *name, int **matrix) {
        _size = size;
        _name = name;
        _sum = 0;
        _matrix = matrix;
        _parent = new int[size];
        _parent[size] = {-1};
        _visit = new bool[size];
        _visit[size] = {false};
        _score = new int[size];
        _score[size] = {INT_MAX};
        _primMatrix = new bool *[size];
        _primMatrix[size] = new bool[size];
        _primMatrix[size][size] = {false};
    }
    void initMatrix(char vertex1, char vertex2, int side);
    void printMatrix();
    void prim(char vertex);  //以vertex为顶点生成最小生成树
    void displayTree();
};

void Graph::initMatrix(char vertex1, char vertex2, int side) {
    for (int i = 0; i < _size; ++i) {
        if (_name[i] == vertex1 || _name[i] == vertex2) {
            for (int j = i + 1; j < _size; ++j) {
                if (_name[j] == vertex2 || _name[j] == vertex1) {
                    _matrix[i][j] = side;
                    _matrix[j][i] = side;
                    break;
                }
            }
        }
    }
}

void Graph::printMatrix() {
    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            std::cout << _matrix[i][j] <<"\t\t";
        }
        std::cout << '\n';
    }
}


void Graph::prim(char vertex) {
    //维护三个东西：selected minDist parent
    int s;
    //找到vertex对应的下标
    for (int i = 0; i < _size; ++i) {
        if (_name[i] == vertex) {
            s = i;
        }
    }
    for (int i = 0; i < _size; ++i) {
        _score[i] = _matrix[s][i];
        _parent[i] = s;
        _visit[i] = false;
    }
    _visit[s] = true;

    int minCost = 0;
    int minid = 0;
    for (int i = 0; i < _size - 1; ++i) {
        minCost = INT_MAX;
        for (int j = 0; j < _size; ++j) {
            if (_visit[j] == false && _score[j] < minCost) {
                minCost = _score[j];
                minid = j;
            }
        }
        _visit[minid] = true;
        _sum += minCost;

        for (int j = 0; j < _size; ++j) {
            if (_visit[j] == false && _matrix[minid][j] < _score[j]) {
                _score[j] = _matrix[minid][j];
                _parent[j] = minid;
            }
        }
    }
    std::cout << "Generate Prim Minimum Spanning Tree!" << std::endl;
}

void Graph::displayTree() {
    for (int i = 0; i < _size; ++i) {
        if (_score[i] != INT_MAX) {
            std::cout << _name[i] << "-(" << _score[i] << ")->"
                      << _name[_parent[i]] << "\t\t";
        }
    }
}
#endif  // INC_008_GRAPH_H