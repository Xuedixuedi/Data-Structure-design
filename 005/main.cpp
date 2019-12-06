#include <iostream>
#include "Queue.h"

using namespace std;

//队列题

int main() {
    int time;//人数
    cin >> time;
    while (time < 1) {
        cout << "您输入的数字应大于或等于1，请重新输入：";
        cin >> time;
    }
    Queue bankA, bankB;
    while (time--) {
        int num;
        cin >> num;
        if (num % 2) {//奇数
            bankA.push(num);
        } else {//偶数
            bankB.push(num);
        }
    }

    while (!bankA.empty() && !bankB.empty()) {
        cout << bankA.front() << ' ';
        bankA.pop();
        if (!bankA.empty()) {
            cout << bankA.front() << ' ';
        }
        bankA.pop();
        cout << bankB.front() << ' ';
        bankB.pop();
    }

    while (!bankA.empty()) {
        cout << bankA.front() << ' ';
        bankA.pop();
    }
    while (!bankB.empty()) {
        cout << bankB.front() << ' ';
        bankB.pop();
    }
    return 0;
}