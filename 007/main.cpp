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

    for (int i = 0; i < times; i++) {
        auto p = q->_header->next;
        cout << p->_data << ' ';
        p = p->next;
    }
    return 0;
}