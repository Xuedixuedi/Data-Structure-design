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

void start();
int* randNum(int len);
int* bubbleSort(int* raw, int len);
int* selectionSort(int* raw, int len);
int* insertionSort(int* raw, int len);

int main() {
    start();
    int len, op;
    cout << "Please enter the lenth of string: ";
    cin >> len;

    int *str, *str1;
    str = randNum(len);  // init a random string

    while (1) {
        cout << endl << "Please chose a sort algorithm: ";
        cin >> op;
        switch (op) {
            case 1: {
                cout << "[You choose BUBBLE SORT!]" << endl;
                bubbleSort(str, len);
                break;
            }
            case 2: {
                cout << "[You choose SELECTION SORT!]" << endl;
                selectionSort(str, len);
                break;
            }
            case 3: {
                cout << "[You choose INSERTION SORT!]" << endl;
                insertionSort(str, len);
                break;
            }
        }
    }

    return 0;
}

void start() {
    cout << "**     Please select a sort algorithm  \t**" << endl;
    cout << "==========================================" << endl;
    cout << "**          1. Bubble Sort          \t**" << endl;
    cout << "**          2. Selection Sort          \t**" << endl;
    cout << "**          3. Insertion Sort       \t**" << endl;
    cout << "**          4. Shell Sort          \t**" << endl;
    cout << "**          5. Quick Sort          \t**" << endl;
    cout << "**          6. Heap Sort          \t**" << endl;
    cout << "**          7. Merge Sort          \t**" << endl;
    cout << "**          8. Radix Sort          \t**" << endl;
    cout << "**          9. Exit System            \t**" << endl;
    cout << "==========================================" << endl;
    cout << endl;
}

int* randNum(int len) {
    srand(time(NULL));
    int* nums = new int[len];

    for (int i = 0; i < len; ++i) {
        nums[i] = 1 + (rand() % 100);
        // cout << nums[i] << ' ';
    }
    cout << endl;
    return nums;
}

int* bubbleSort(int* raw, int len) {
    auto result = new int[len];
    memcpy(result, raw, len * sizeof(int));
    int time;                    //排序用时
    long long int swapTime = 0;  //交换次数

    BEGIN_RECORD
    for (int i = len - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (result[j] > result[j + 1]) {
                int temp = result[j];
                swapTime++;
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
    END_RECORD(time)

    cout << "The time taken for bubble sort is: \t" << time << "ms" << endl;
    cout << "The number of bubble sort's swap time is: \t" << swapTime << endl;
    return result;
}

int* selectionSort(int* raw, int len) {
    auto result = new int[len];
    memcpy(result, raw, len * sizeof(int));
    int time;                    //排序用时
    long long int swapTime = 0;  //交换次数
    BEGIN_RECORD
    for (int i = 0; i < len - 1; ++i) {
        int temp = result[i];
        int k = i;
        for (int j = i; j < len; ++j) {
            if (result[j] < temp) {
                temp = result[j];
                k = j;
            }
        }
        result[k] = result[i];
        result[i] = temp;
        swapTime++;
    }
    END_RECORD(time)

    cout << "The time taken for selection sort is: \t" << time << "ms" << endl;
    cout << "The number of selection sort's swap time is: \t" << swapTime
         << endl;
    return result;
}

int* insertionSort(int* raw, int len) {
    auto result = new int[len];
    memcpy(result, raw, len * sizeof(int));
    int time;                    //排序用时
    long long int swapTime = 0;  //交换次数

    BEGIN_RECORD
    for (int i = 0; i < len; ++i) {
        int temp = result[i];
        int j = i - 1;
        for (; temp < result[j] && j >= 0; --j) {
            result[j + 1] = result[j];
        }
        result[j + 1] = temp;
        swapTime++;
    }
    END_RECORD(time)

    cout << "The time taken for insertion sorting is: \t" << time << "ms"
         << endl;
    cout << "The number of insertion sort's swap time is: \t" << swapTime
         << endl;
    return result;
}