#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main() {
    int times;
    cin >> times;
    auto q = new PriorityQueue();
    for (int i = 0; i < times; i++) {
        int num;
        cin >> num;
        q->push(num);
    }

    int tempAns = 0;
    while(q->size()>1){
        int a = q->top();
        q->pop();
        int b = q->top();
        q->pop();
        tempAns += a+b;
        q->push(a+b);
    }
    cout << tempAns;

    return 0;
}