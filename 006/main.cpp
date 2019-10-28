#include <iostream>
#include<iomanip>

using namespace std;

void beginShow();//初始的菜单

int main() {



    beginShow();
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