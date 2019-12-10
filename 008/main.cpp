#include <iomanip>
#include <iostream>
#include "Graph.h"

using namespace std;

void menu();

Graph *init();  //初始化图
void addSide(Graph *grid);

void minTree(Graph *grid);

void showTree(Graph *grid);

int main() {
    menu();
    Graph *grid;
    while (1) {
        cout << "Please select an operation: ";
        char op;
        cin >> op;
        if (op == 'E') {
            cout << "You are already exited the system" << endl;
            break;
        }
        switch (op) {
            default: {
                cout << "The operation code you entered is incorrect. Please re-enter!" << endl;
                break;
            }
            case 'A': {
                grid = init();
                cout << endl;
                break;
            }
            case 'B': {
                addSide(grid);
                cout << endl;
                break;
            }
            case 'C': {
                minTree(grid);
                cout << endl;
                break;
            }
            case 'D': {
                showTree(grid);
                cout << endl;
                break;
            }
        }
    }
    return 0;
}

void menu() {
    cout << "**       Power grid cost simulation system        **" << endl;
    cout << "====================================================" << endl;
    cout << std::left << setfill(' ') << setw(50)
         << "**     A --- Create a power grid vertex"
         << "**" << endl;
    cout << std::left << setfill(' ') << setw(50)
         << "**     B --- Adding the side of the grid"
         << "**" << endl;
    cout << std::left << setfill(' ') << setw(50)
         << "**     C --- Constructing minimum spanning tree"
         << "**" << endl;
    cout << std::left << setfill(' ') << setw(50)
         << "**     D --- Display minimum spanning tree"
         << "**" << endl;
    cout << std::left << setfill(' ') << setw(50)
         << "**     E --- Exit the program"
         << "**" << endl;
    cout << "====================================================" << endl;
}

Graph *init() {
    cout << "Please enter the number of vertex: ";
    int size = 0;
    cin >> size;
    while (size < 2) {
        cout << "the number of vertex cannnot be less than 2. Please enter "
                "again: ";
        cin >> size;
    }
    cout << "Please enter the names of the vertexes in order: ";
    char name;
    char *namelist = new char;
    auto matrix = new int *[size];
    for (int i = 0; i < size; ++i) {
        cin >> name;
        namelist[i] = name;
        matrix[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = INT_MAX;
        }
    }

    auto grid = new Graph(size, namelist, matrix);
//    grid->printMatrix();
    return grid;
}

void addSide(Graph *grid) {
    char vertex1, vertex2;
    int side;
    while (true) {
        cout << "Please enter two vertices and edges: ";
        cin >> vertex1 >> vertex2 >> side;
        if (vertex1 == '?') {
            break;
        } else {
            grid->initMatrix(vertex1, vertex2, side);
        }
    }
//     grid->printMatrix();
}

void minTree(Graph *grid) {
    cout << "Please enter the starting vertex: ";
    char v;
    cin >> v;
    grid->prim(v);
}

void showTree(Graph *grid) {
    cout << "The vertices and edges of the minimum spanning tree are: " << endl;
    grid->displayTree();
}