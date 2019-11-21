#include <iostream>
#include <iomanip>
//using std::setw;
using namespace std;

void menu();

int main() {
    menu();
    cout << "Please select an operation: " << endl;
    char op;
    cin >> op;
    switch (op){
        case'A':
        {

            break;
        }
    }
    return 0;
}

void menu(){
    cout << "**       Power grid cost simulation system        **" << endl;
    cout << "====================================================" << endl;
    cout << std::left <<setfill(' ')<< setw(50) << "**     A --- Create a power grid vertex" << "**" << endl;
    cout << std::left <<setfill(' ')<< setw(50) << "**     B --- Adding the side of the grid" << "**" << endl;
    cout << std::left <<setfill(' ')<< setw(50) << "**     C --- Constructing minimum spanning tree" << "**" << endl;
    cout << std::left <<setfill(' ')<< setw(50) << "**     D --- Display minimum spanning tree" << "**" << endl;
    cout << std::left <<setfill(' ')<< setw(50) << "**     E --- Exit the program" << "**" << endl;
    cout << "====================================================" << endl;
}