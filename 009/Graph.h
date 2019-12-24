//
// Created by lxd on 2019/12/12.
//

#ifndef INC_009_GRAPH_H
#define INC_009_GRAPH_H

#include <iostream>
#include <vector>
#include <stack>

struct Course {
    std::string _number;//课程编号
    std::string _name;//课程名字
    int _time;//学时数
    int _semester;//开课学期
    bool _havePre;
    int _degree;//入度
    std::vector<std::string> _pre;

    Course() {
        _number = "0";
        _name = "0";
        _havePre = false;
        _degree = 0;

    }

    Course(std::string &nu, std::string &na, int ti, int se, bool ha) {
        _number = nu;
        _name = na;
        _time = ti;
        _semester = se;
        _havePre = ha;
    }
};


class Graph {
public:
    std::vector<Course> _name;         //储存顶点名称的数组
    std::vector<Course> _classname;  //在矩阵中有用的顶点们
    int _matrix[29][29];       //邻接矩阵表示
    int _size;           //course name数
    int _vertexes;  //真实的顶点数
    std::vector<int> _inDegree;//入度
    std::vector<Course> _classlist;//拓扑排序后的课程顺序
    std::stack<int> stk; //入度为0的点
    Graph() = default;

    Graph(std::vector<Course> course) {
        _name = course;
        _size = course.size();
        _vertexes = 0;
    }

    void initMatrix();

    void findInDegree();//查找各个顶点的入度
    std::vector<Course> topologicalSort();
};

void Graph::initMatrix() {
    for (auto &i : _name) {
        if (!i._semester) {
            _classname.push_back(i);
        }
    }
    _vertexes = _classname.size();
    int mat[_vertexes][_vertexes];
    for (int i = 0; i < _vertexes; ++i) {
        for (int j = 0; j < _vertexes; ++j) {
            mat[i][j] = 0;
            if (_classname[j]._havePre) {
                //j的前驱是i，也就是i的后继是j matrix[i][j]置1
                for (auto it = _classname[j]._pre.begin(); it != _classname[j]._pre.end(); ++it) {
                    if (*it == _classname[i]._number) {
                        mat[i][j] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < _vertexes; ++i) {
        for (int j = 0; j < _vertexes; ++j) {
            _matrix[i][j] = mat[i][j];
        }
    }
}

void Graph::findInDegree() {
    for (int i = 0; i < _classname.size(); ++i) {
//        std::cout << _classname[i]._degree << " ";
        _inDegree.push_back(_classname[i]._degree);
        if (_inDegree[i] == 0) {
            stk.push(i);
        }

    }
}

std::vector<Course> Graph::topologicalSort() {
    std::vector<Course> ans;
    findInDegree();
    int v;//下标
    while (!stk.empty()){
        v = stk.top();
        stk.pop();
        for(int i = 0;i < _classname.size();++i){
            if(_matrix[v][i] == 1){
                _inDegree[i] --;
                if(_inDegree[i] == 0){
                    stk.push(i);
                }
            }
        }
        ans.push_back(_classname[v]);
    }
        _classlist = ans;
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        std::cout << it->_name << ' ';
    }
    return ans;
}

#endif //INC_009_GRAPH_H
