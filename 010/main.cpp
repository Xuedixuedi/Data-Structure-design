#include <stdio.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

// define start time and end time

#define BEGIN_RECORD                    \
    {                                   \
        clock_t ____temp_begin_time___; \
        ____temp_begin_time___ = clock();

#define END_RECORD(dtime)                                                    \
    dtime = float(clock() - ____temp_begin_time___) / CLOCKS_PER_SEC * 1000; \
    }

int* randNum(int len);
int* bubbleSort(int* raw, int len);

int main() {
    cout << "Please enter the lenth of string: ";
    int len;
    cin >> len;
    int *str, *str1;
    str = randNum(len);
    str1 = bubbleSort(str, len);
    return 0;
}

int* randNum(int len) {
    srand(time(NULL));
    vector<int> nums(len);

    for (int i = 0; i < len; ++i) {
        nums[i] = 1 + (rand() % 100);
        cout << nums[i] << ' ';
    }
    cout << endl;
}

int* bubbleSort(int* raw, int len) {
    auto result = new int[len];
    memcpy(result, raw, len * sizeof(int));
    int time;      //排序用时
    int swapTime;  //交换次数

    BEGIN_RECORD
    for (int i = len - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (result[j] > result[j + i]) {
                int temp = result[j];
                swapTime++;
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
    END_RECORD(time)

    cout << "The time taken for bubble sorting is: \t" << time << "ms" << endl;
    cout << "The number of bubble sort's swap time is: \t" << swapTime << endl;
}
