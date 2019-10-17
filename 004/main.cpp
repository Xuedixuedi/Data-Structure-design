#include <iostream>
#include <map>
#include <queue>
#include <stack>
//#include "Stack.h"

using namespace std;

map<char, int> optionWeight = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'%', 3},
        {'^', 4}


};//操作符的优先级

//思路：讲中缀表达式转化为后缀表达式 再用后缀表达式求和

queue<char> getSuffix(string s);//将中缀表达式化为后缀表达式,返回后缀表达式
bool cmp(char a, char b);//比较运算符的优先级

int main() {
    queue<char> suffix;//后缀表达式

    cout << "输入表达式：\n";

    string s;//表达式
    cin >> s;

    suffix = getSuffix(s);
    while(!suffix.empty()){
        cout << suffix.front();
        suffix.pop();
    }
    return 0;
}

queue<char> getSuffix(string s) {
    queue<char> suffix;//生成的后缀表达式
    stack<char> op;//运算符栈
    for (auto it = s.begin(); it != s.end(); it++) {
        if (*it >= '0' && *it <= '9') {

            suffix.push(*it);
        } else if (*it == '(') {

            op.push(*it);
        } else if (*it == ')') {

            while (op.top() != '(') {
                suffix.push(op.top());
                op.pop();
            }
            op.pop();//把左括号也出栈
        } else {

            if (op.empty() || op.top() == '('){
                cout << op.size()<< endl;
                op.push(*it);
            }

            else {

                while (cmp(op.top(), *it)) {
                    suffix.push(op.top());
                    op.pop();
                }
                op.push(*it);

            }
        }
    }
    return suffix;
}

//在当前操作符的优先级高于低于或等于栈顶操作符时，需要栈顶出栈
//使用时应cmp（栈顶，当前）
bool cmp(char a, char b) {
    return optionWeight[a] - optionWeight[b] >= 0;
}
