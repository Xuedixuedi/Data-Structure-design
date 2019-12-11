#include <iostream>
#include "Maze.h"
#include "Stack.h"

using namespace std;

void printStack(Stack<Point> s);

int main() {
    auto maze = new Maze;
    Point start = maze->_start;
    maze->printMaze(maze->_maze);
    Stack<Point> s = maze->dfs(start.x, start.y);
//    printStack(s);
    maze->changeMaze();
    maze->printMaze(maze->_ansMaze);
    maze->displayPath(s);
    return 0;
}

void printStack(Stack<Point> s) {
    while (!s.empty()) {
        cout << s.top().x << ',' << s.top().y << "  ";
        s.pop();
    }
}