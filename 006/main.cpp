#include <iostream>
#include <iomanip>
#include <string>
#include "BinNode.h"
#include "BinTree.h"


using namespace std;

void beginShow();//初始的菜单
BinTree<string> *initFamily();//建立家谱
void completeFamily(BinTree<string> *tree);//完善家谱
void addMember(BinTree<string> *tree);//添加成员
void disbandLocalFamily(BinTree<string> *tree);//解散局部家庭
void changeName(BinTree<string> *tree);//修改某个成员的姓名

int main() {
    beginShow();
    auto family = initFamily();
    while (1) {
        cout << "请选择要执行的操作: ";
        char op;
        cin >> op;
        if (op == 'E') {
            cout << "您已退出系统" << endl;
            break;
        }
        switch (op) {
            case 'A' : {
                completeFamily(family);
                break;
            }
            case 'B': {
                addMember(family);
                break;
            }
            case 'C': {
                disbandLocalFamily(family);
                break;
            }
            case 'D': {
                changeName(family);
                break;
            }
        }
    }
    return 0;
}

void beginShow() {


    cout << left << setw(50) << "**               家谱管理系统             \t**" << endl;
    cout << left << setw(50) << "==============================================" << endl;
    cout << left << setw(50) << "**             请选择要执行的操作:         \t**" << endl;
    cout << left << setw(50) << "**              A --- 完善家谱           \t**" << endl;
    cout << left << setw(50) << "**              B --- 添加家庭成员        \t**" << endl;
    cout << left << setw(50) << "**              C --- 解散局部家庭        \t**" << endl;
    cout << left << setw(50) << "**              D --- 更改家庭成员姓名    \t**" << endl;
    cout << left << setw(50) << "**              E --- 退出程序           \t**" << endl;
    cout << left << setw(50) << "==============================================" << endl;
}

BinTree<string> *initFamily() {
    cout << "首先建立一个家谱!" << endl;
    cout << "请输入祖先的姓名：";
    string ancestor;
    cin >> ancestor;
    auto tree = new BinTree<string>;
    tree->insertAsRoot(ancestor);
    cout << "这个家族的祖先是：" << tree->root()->data() << endl;
    return tree;
}

void completeFamily(BinTree<string> *tree) {
    cout << "请输入要建立家庭的人的姓名：";
    string name;
    cin >> name;
    cout << "请输入" << name << "的儿女数：";
    int num;
    cin >> num;
    auto p = tree->search(name);
    auto p0 = p;//记录该节点位置
    while (num <= 0) {
        cout << "您输入的数字有误，请重新输入" << endl;
        cin >> num;
    }
    cout << "请依次输入" << name << "的儿女姓名: ";
    string child;
    cin >> child;
    p->insertAsLC(child);
    num--;
    while (num--) {
        cin >> child;
        p->insertAsRC(child);
        p = p->rChild;
    }
    cout << name << "的第一代子孙是： ";
    tree->showChild(p0);
}

void addMember(BinTree<string> *tree) {
    cout << "请输入要添加儿子（或女儿）的人的姓名： ";
    string name, child;
    cin >> name;
    cout << "请输入" << name << "新添加的儿子（或女儿）的姓名: ";//todo:应该在这里就判断name是否存在在子🌲
    cin >> child;
    auto p = tree->search(name);
    auto p0 = p;
    if (p->lChild == nullptr) {
        p->insertAsLC(child);
    } else {
        p = p->lChild;
        while (p->rChild != nullptr) {
            p = p->rChild;
        }
        p->insertAsRC(name);
    }
    cout << name << "的第一代子孙是： ";
    tree->showChild(p0);
}

void disbandLocalFamily(BinTree<string> *tree) {
    cout << "请输入要解散家庭的人的姓名： ";
    string name;
    cin >> name;
    cout << "要解散家庭的人是：" << name << endl;
    cout << name << "的第一代子孙是: ";
    auto p = tree->search(name);
    tree->showChild(p);//todo:暂时写成只输出子一代（又方便又看上去符合题目要求先不管了cnmd）
    tree->remove(p);
}

void changeName(BinTree<string> *tree) {
    cout << "请输入要更改姓名的人目前的姓名：";
    string formerName, name;
    cin >> formerName;
    auto p = tree->search(formerName);
    cout << "请输入更改后的姓名： ";
    cin >> name;
    p->setData(name);
    cout << formerName << "已更名为" << name << endl;
}