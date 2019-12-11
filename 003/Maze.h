//
// Created by lxd on 2019/12/10.
//

#ifndef INC_003_MAZE_H
#define INC_003_MAZE_H

#include <cstring>
#include <iostream>
#include "Stack.h"

using namespace std;

struct Point {
    int x;
    int y;

    bool operator==(const Point &p) {
        return p.x == this->x && p.y == this->y;
    }

    Point() = default;

    Point(int x, int y);
};

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

class Maze {
private:
    int _size;

    int DIR[4][2] = {{0,  1},
                     {0,  -1},
                     {-1, 0},
                     {1,  0}};

public:
    char **_maze;
    char **_Bmaze;
    char **_ansMaze;
    Point _start;
    Point _end;

    Maze();

    void printMaze(char **maze);

    void changeMaze();

    Stack<Point> dfs(int x, int y);

    void displayPath(Stack<Point> s);
};

Maze::Maze() {
    _size = 7;
    _maze = new char *[_size];
    _Bmaze = new char *[_size];
    _ansMaze = new char *[_size];
    for (int i = 0; i < _size; ++i) {
        _maze[i] = new char[_size];
        _Bmaze[i] = new char[_size];
        _ansMaze[i] = new char[_size];
    }
    strcpy(_maze[0], "#######");
    strcpy(_maze[1], "#0#000#");
    strcpy(_maze[2], "#0#0###");
    strcpy(_maze[3], "#000#0#");
    strcpy(_maze[4], "#0#000#");
    strcpy(_maze[5], "#0#0#0#");
    strcpy(_maze[6], "#######");
    strcpy(_Bmaze[0], "0000000");
    strcpy(_Bmaze[1], "0000000");
    strcpy(_Bmaze[2], "0000000");
    strcpy(_Bmaze[3], "0000000");
    strcpy(_Bmaze[4], "0000000");
    strcpy(_Bmaze[5], "0000000");
    strcpy(_Bmaze[6], "0000000");
    strcpy(_ansMaze[0], "#######");
    strcpy(_ansMaze[1], "#0#000#");
    strcpy(_ansMaze[2], "#0#0###");
    strcpy(_ansMaze[3], "#000#0#");
    strcpy(_ansMaze[4], "#0#000#");
    strcpy(_ansMaze[5], "#0#0#0#");
    strcpy(_ansMaze[6], "#######");
    _start.x = 1;
    _start.y = 1;
    _end.x = 5;
    _end.y = 5;
}

void Maze::printMaze(char **maze) {
    cout << "Maze Map:" << endl;
    cout << "\t\t";
    for (int i = 0; i < _size; ++i) {
        cout << i << "row\t";
    }
    cout << endl;
    for (int i = 0; i < _size; ++i) {
        cout << i << "line\t";
        for (int j = 0; j < _size; ++j) {
            cout << maze[i][j] << "\t\t";
        }
        cout << '\n';
    }
}

Stack<Point> Maze::dfs(int x, int y) {
    Stack<Point> s;//存放走过节点的栈
    Point p(x, y);//新建一个节点，作为下一个要走的节点
    _Bmaze[x][y] = '1';
    s.push(p);
    int i = 0;
    while (!s.empty()) {
        while (i < 4) {
            int nx = p.x + DIR[i][0];
            int ny = p.y + DIR[i][1];
            if (_maze[nx][ny] == '0' && _Bmaze[nx][ny] == '0') {
                p.x = nx;
                p.y = ny;
                s.push(p);
                if (nx == _end.x && ny == _end.y) {
                    return s;
                }
                _Bmaze[nx][ny] = '1';
                i = 0;
                continue;
            }
            ++i;
        }
        s.pop();
        if (s.empty()) {
            cout << "No Answer" << endl;
            exit(0);
        } else {
            p = Point(s.top().x, s.top().y);
            i = 0;
        }
    }
}

void Maze::changeMaze() {
    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_Bmaze[i][j] == '1') {
                _ansMaze[i][j] = '*';
            } else {
                continue;
            }
        }
    }
}

void Maze::displayPath(Stack<Point> s) {
    Stack<Point> st;
    while (!s.empty()) {
        st.push(s.top());
        s.pop();
    }
    while (!st.empty()) {
        cout << '<' << st.top().x << ',' << st.top().y << '>';
        if (st.size() > 1) {
            cout << "  -->  ";
        }
        st.pop();
    }
}

#endif //INC_003_MAZE_H
