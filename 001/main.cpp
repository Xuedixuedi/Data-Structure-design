//
// Created by lxd on 2019-09-12.
//

//考生信息
//list实现



#include "Node.h"
#include "LinkList.h"

using namespace std;

void option(LinkList *namelist);

int main() {
    int number;
    string name;//姓名
    string sex;//性别
    int age;//年龄
    string type;//报考科目

    cout << "首先建立考生信息系统\n首先输入考生人数:  ";
    int n;//考生人数
    cin >> n;
    while(n <= 0){
        cout << "请输入一个正整数： ";
        cin >> n;
    }
    cout << "请依次输入考生的考号、姓名、性别、年龄及报考类别\n";
    auto nameList = new LinkList;
    while (n--) {
        cin >> number >> name >> sex >> age >> type;
        Node *stu = new Node(number, name, sex, age, type);
        nameList->insertAsLast(stu);
    }
    cout << "请选择您要进行的操作(1为插入，2为删除，3为查找，4为修改，5为统计，6为退出，0取消操作）:\n";

    int op = 0;
    while (1) {
        cout << "请选择您要进行的操作: ";
        cin >> op;
        if (op == 6) {
            cout << "您已退出系统。";
            break;
        }
        switch (op) {
            case 0: {
                break;
            }
            case 1: {
                int pos;
                std::cout << "请输入你要插入的考生的位置： ";
                std::cin >> pos;
                if (nameList->insertAtPos(pos) != nullptr) {
                    nameList->traverse();
                }
                break;
            }
            case 2: {
                cout << "请输入要删除的考生的考号:";
                cin >> number;
                nameList->remove(number);
                nameList->traverse();
                break;
            }
            case 3: {
                cout << "请输入您要查找的考生的考号：";
                cin >> number;
                nameList->find(number);
                break;
            }
            case 4: {
                cout << "请输入您要修改的考生的考号: ";
                cin >> number;
                if (nameList->change(number) != nullptr) {
                    nameList->traverse();
                }
                break;
            }
            case 5: {
                nameList->traverse();
                break;
            }
            default: {
                cout << "您输入的数字有误，请重新输入：";
                break;
            }
        }
    }
    return 0;
}
