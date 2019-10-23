#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include "Stack.h"

using namespace std;



//思路：讲中缀表达式转化为后缀表达式 再用后缀表达式求和
map<char, int> optionWeight = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'%', 3},
        {'^', 4}


};//操作符的优先级
queue<string> getSuffix(string s);//将中缀表达式化为后缀表达式,返回后缀表达式
string monoOpProcess(string s);//处理单目运算符,返回处理后的字符串
bool isNumber(char a);//判断这个字符是数字还是符号
bool cmp(char a, char b);//比较运算符的优先级
double calculate(double a, double b, char op);

double getAns(queue<string> s);//计算表达式最终结果


int main() {
    string s;//表达式
    while(1){
        cout << "输入表达式：\n";
        cin >> s;
        s.pop_back();//删除等号做处理
        queue<string> suffix;//后缀表达式
        s = monoOpProcess(s);//处理单目运算符
        suffix = getSuffix(s);//转后缀表达式
        cout << getAns(suffix) << endl;
        cout << "是否继续(y/n)?" << endl;
        char op;
        cin >> op;
        if(op == 'y'){
            continue;
        }else if(op == 'n'){
            break;
        }
    }
    return 0;
}

bool isNumber(char a) {
    return a >= '0' && a <= '9';
}

string monoOpProcess(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '+' && s[i] != '-') {
            continue;
        }
        if (i == 0) {
            s.insert(i, 1, 0 + '0');
        } else if (!isNumber(s[i - 1]) && s[i - 1] != ')') {
            s.insert(i, "(0");
            for (i = i + 3; i < s.size(); ++i) {
                if (isNumber(s[i]) || s[i] == '.') {
                    continue;
                } else {
                    s.insert(i, ")");
                    break;
                }
            }
        }
    }
    return s;
}

queue<string> getSuffix(string s) {
    queue<string> suffix;//生成的后缀表达式
    auto op = new Stack<char>;
    for (int i = 0; i < s.size(); ++i) {
        if (isNumber(s[i])) {
            string num = string(1, s[i]);
            int j = i + 1;
            for (; j < s.size(); ++j) {
                if (!isNumber(s[j]) && s[j] != '.') {
                    break;
                }
                num = num + s[j];
                i = j;
            }
            suffix.push(num);
        } else if (s[i] == '(') {
            op->push(s[i]);
        } else if (s[i] == ')') {
            while (op->top() != '(') {
                suffix.push(string(1, op->top()));
                op->pop();
            }
            op->pop();//把左括号也出栈
        } else {
            if (op->empty() || op->top() == '(') {
                op->push(s[i]);
            } else {
                while (cmp(op->top(), s[i])) {
                    suffix.push(string(1, op->top()));
                    op->pop();
                    if (op->empty()) {
                        break;
                    }
                }

                op->push(s[i]);
            }
        }
    }
    while (!op->empty()) {
        suffix.push(string(1, op->top()));
        op->pop();
    }
    return suffix;
}

//在当前操作符的优先级高于低于或等于栈顶操作符时，需要栈顶出栈
//使用时应cmp（栈顶，当前）
bool cmp(char a, char b) {
    return optionWeight[a] - optionWeight[b] >= 0;
}

double calculate(double a, double b, string op) {
    if (op == "+") {
        return a + b;
    } else if (op == "-") {
        return a - b;
    } else if (op == "*") {
        return a * b;
    } else if (op == "/") {
        if (b == 0) {
            cout << "除数不能为0，您输入的表达式有误" << endl;
            exit(-1);
        } else {
            return a / b;
        }
    } else if (op == "%") {
        return (int(a) % int(b));
    } else if (op == "^") {
        return pow(a, b);
    }
}

double getAns(queue<string> s) {
    Stack<double> ans;//结果栈
    while (!s.empty()) {
        string temp = s.front();
        s.pop();
        if (isnumber(temp[0])) {
            //当前取出是数字
            ans.push(atof(temp.c_str()));
        } else {
            double b = ans.top();
            ans.pop();
            double a = ans.top();
            ans.pop();
            ans.push(calculate(a, b, temp));
        }
    }
    return ans.top();
}