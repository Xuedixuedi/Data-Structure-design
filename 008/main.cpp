#include <iostream>
#include <iomanip>
#include "Graph.h"

using namespace std;

void menu();

Graph *init();//初始化图
void addSlide(Graph *grid);

int main() {
    menu();
    cout << "Please select an operation: " << endl;
    char op;
    cin >> op;
    Graph *grid;
    switch (op) {
        case 'A': {
            grid = init();
            cout << endl;
            break;
        }
        case 'B': {

            cout << endl;
            break;
        }
    }
    return 0;
}

void menu() {
    cout << "**       Power grid cost simulation system        **" << endl;
    cout << "====================================================" << endl;
    cout << std::left << setfill(' ') << setw(50) << "**     A --- Create a power grid vertex" << "**" << endl;
    cout << std::left << setfill(' ') << setw(50) << "**     B --- Adding the side of the grid" << "**" << endl;
    cout << std::left << setfill(' ') << setw(50) << "**     C --- Constructing minimum spanning tree" << "**" << endl;
    cout << std::left << setfill(' ') << setw(50) << "**     D --- Display minimum spanning tree" << "**" << endl;
    cout << std::left << setfill(' ') << setw(50) << "**     E --- Exit the program" << "**" << endl;
    cout << "====================================================" << endl;
}

Graph *init() {
    cout << "Please enter the number of vertex: ";
    int size = 0;
    cin >> size;
    cout << "Please enter the names of the vertexes in order: ";
    char name;
    char *namelist = new char;
    for (int i = 0; i < size; ++i) {
        cin >> name;
        namelist[i] = name;
    }
    auto grid = new Graph(size, namelist);
    return grid;
}

void addSlide(Graph *grid) {
    char vertex1, vertex2;
    int slide;
    while (true) {
        cout << "请输入两个顶点及边： ";
        cin >> vertex1 >> vertex2 >> slide;
        if (vertex1 == '?') {
            break;
        }
    }
}