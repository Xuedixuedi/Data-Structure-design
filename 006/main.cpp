#include <iostream>
#include <iomanip>
#include <string>
#include "BinNode.h"
#include "BinTree.h"

using namespace std;

void beginShow();//初始的菜单
BinTree<string> *initFamily();//建立家谱
void *completeFamily(BinTree<string> *tree);//完善家谱

int main() {
    beginShow();
    auto family = initFamily();
    while (1) {
        cout << "请选择要执行的操作";
        char op;
        cin >> op;
        if (op == 'E') {
            cout << "您已退出系统" << endl;
            break;
        }
        switch (op) {
            case 'A' : {

            }
        }
    }
    return 0;
}

void beginShow() {


    cout << left << setw(50) << "**               家谱管理系统               **" << endl;
    cout << left << setw(50) << "============================================" << endl;
    cout << left << setw(50) << "**             请选择要执行的操作:           **" << endl;
    cout << left << setw(50) << "**              A --- 完善家谱             **" << endl;
    cout << left << setw(50) << "**              B --- 添加家庭成员          **" << endl;
    cout << left << setw(50) << "**              C --- 解散局部家庭          **" << endl;
    cout << left << setw(50) << "**              D --- 更改家庭成员姓名      **" << endl;
    cout << left << setw(50) << "**              E --- 退出程序             **" << endl;
    cout << left << setw(50) << "============================================" << endl;
}

BinTree<string> *initFamily() {
    cout << "首先建立一个家谱!" << endl;
    cout << "请输入祖先的姓名：";
    string ancestor;
    cin >> ancestor;
    auto tree = new BinTree<string>;
    tree->insertAsRoot(ancestor);
    cout << "这个家族的祖先是：" << tree->root()->data() << endl;
}

void *completeFamily(BinTree<string> *tree) {
    cout << "请输入要建立家庭的人的姓名：";
    string name;
    cin >> name;
    cout << "请输入" << name << "的儿女数：";
    int num;
    cin >> num;
    cout << "请依次输入" << name << "的儿女姓名";
    string child;
    while(num--){
        cin >> child;

    }
}