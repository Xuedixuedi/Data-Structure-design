#include <ctime>
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

int *randNum(int len);

int *bubbleSort(int *raw, int len);

int *selectionSort(int *raw, int len);

int *insertionSort(int *raw, int len);

int *shellSort(int *raw, int len);

int *quickSort(int *raw, int start, int end, int &swapTime);

int *adjustHeap(int *heap, int start, int end, int &swapTime);//调整最大堆

int *heapSort(int *raw, int len);

int *merge(int *input, int start, int mid, int end, int *output, int &swapTime);

int *mergeSort(int *raw, int start, int end, int *buffer, int &swapTime);

int max(const int *raw, int len);

int countSort(int *raw, int len, int bit);

int *radixSort(int *raw, int len);

int main() {
    start();
    int len, op;
    cout << "Please enter the length of string: ";
    cin >> len;

    int *str;
    str = randNum(len);  // init a random string

    while (true) {
        cout << endl << "Please chose a sort algorithm: ";
        cin >> op;
        switch (op) {
            default: {
                cout << "You entered a wrong number,please try again:" << endl;
                break;
            }
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
            case 4: {
                cout << "[You choose SHELL SORT!]" << endl;
                shellSort(str, len);
                break;
            }
            case 5: {
                cout << "[You choose QUICK SORT!" << endl;
                int start = 0;
                int end = len - 1;
                auto result = new int[len];
                memcpy(result, str, len * sizeof(int));
                int time;                    //排序用时
                int swapTime = 0;  //交换次数
                int &sw = swapTime;
                BEGIN_RECORD
                    quickSort(result, start, end, sw);
                END_RECORD(time);
                cout << "The time taken for quick sort is: \t" << time << "ms" << endl;
                cout << "The number of quick sort's swap time is: \t" << swapTime << endl;
                break;
            }
            case 6: {
                cout << "[You choose HEAP SORT!]" << endl;
                heapSort(str, len);
                break;
            }
            case 7: {
                cout << "[You choose MERGE SORT!]" << endl;
                int start = 0;
                int end = len - 1;
                auto result = new int[len];
                auto buffer = new int[len];
                memcpy(result, str, len * sizeof(int));
                int time;
                int swapTime = 0;  //交换次数
                int &sw = swapTime;
                BEGIN_RECORD
                    mergeSort(result, start, end, buffer, sw);
                END_RECORD(time);
                cout << "The time taken for quick sort is: \t" << time << "ms" << endl;
                cout << "The number of quick sort's swap time is: \t" << swapTime << endl;
//                for (int i = 0; i < len; ++i) {
//                    cout << result[i] << ' ';
//                }
                break;
            }
            case 8: {
                cout << "[You choose RADIX SORT!]" << endl;
                auto result = new int[len];
                memcpy(result, str, len * sizeof(int));
                radixSort(result, len);
                break;
            }
            case 9: {
                cout << "You have already exit the system." << endl;
                return 0;
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
    cout << "**          4. Shell Sort            \t**" << endl;
    cout << "**          5. Quick Sort            \t**" << endl;
    cout << "**          6. Heap Sort            \t**" << endl;
    cout << "**          7. Merge Sort            \t**" << endl;
    cout << "**          8. Radix Sort            \t**" << endl;
    cout << "**          9. Exit System            \t**" << endl;
    cout << "==========================================" << endl;
    cout << endl;
}

int *randNum(int len) {
    srand(time(NULL));
    int *nums = new int[len];

    for (int i = 0; i < len; ++i) {
        nums[i] = 1 + (rand() % 100);
        // cout << nums[i] << ' ';
    }
    cout << endl;
    return nums;
}

int *bubbleSort(int *raw, int len) {
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

int *selectionSort(int *raw, int len) {
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

int *insertionSort(int *raw, int len) {
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

int *shellSort(int *raw, int len) {
    auto result = new int[len];
    memcpy(result, raw, len * sizeof(int));
    int time;                    //排序用时
    long long int swapTime = 0;  //交换次数

    int gap = 1;//每组的间隔
    while (gap <= len / 3) {
        gap = 3 * gap + 1;
    }

    BEGIN_RECORD
        while (gap > 0) {
            for (int i = gap; i < len; ++i) {
                if (result[i - gap] > result[i]) {
                    int temp = result[i];
                    int j = i - gap;
                    for (; result[j] > temp && j >= 0; j -= gap) {
                        result[j + gap] = temp;
                        swapTime++;
                    }
                    result[j + gap] = temp;
                    swapTime++;
                }
            }
            gap = (gap - 1) / 3;
        }
    END_RECORD(time)
    cout << "The time taken for shell sorting is: \t" << time << "ms"
         << endl;
    cout << "The number of shell sort's swap time is: \t" << swapTime
         << endl;
    return result;
//    for (int i = 0; i < len; ++i) {
//        cout << result[i] << ' ';
//    }
}

int *quickSort(int *raw, int start, int end, int &swapTime) {
    if (start < end) {
        int i = start;
        int j = end;
        int temp = raw[start];
        while (i < j) {
            while (i < j && raw[j] >= temp) {
                j--;
            }
            if (i < j) {
                raw[i] = raw[j];
                swapTime++;
            }
            while (i < j && raw[i] < temp) {
                i++;
            }
            if (i < j) {
                raw[j] = raw[i];
                swapTime++;
            }
        }
        raw[i] = temp;
        quickSort(raw, i + 1, end, swapTime);
        quickSort(raw, start, i - 1, swapTime);
    }
    return raw;
}

int *adjustHeap(int *heap, int start, int end, int &swapTime) {
    int temp = heap[start];
    for (int i = 2 * start + 1; i <= end; i = i * 2 + 1) {
        if (heap[i] < heap[i + 1] && i + 1 <= end) {
            i++;
        }
        if (heap[i] < temp) {
            break;
        }
        heap[start] = heap[i];
        start = i;
        swapTime++;
    }
    heap[start] = temp;

}

int *heapSort(int *raw, int len) {
    auto result = new int[len];
    memcpy(result, raw, len * sizeof(int));
    int time;                    //排序用时
    int swapTime = 0;  //交换次数
    int &sw = swapTime;
    BEGIN_RECORD
        for (int i = (len - 1) / 2; i >= 0; --i) {
            adjustHeap(result, i, len - 1, sw);
        }
        for (int i = len - 1; i >= 0; --i) {
            int temp = result[i];
            result[i] = result[0];
            result[0] = temp;
            swapTime++;
            adjustHeap(result, 0, i - 1, sw);
        }
    END_RECORD(time)
    cout << "The time taken for heap sort is: \t" << time << "ms" << endl;
    cout << "The number of heap sort's swap time is: \t" << swapTime << endl;
//        for (int i = 0; i < len; ++i) {
//        cout << result[i] << ' ';
//    }
    return result;
}

int *merge(int *input, int start, int mid, int end, int *output, int &swapTime) {
    int first = start;//第一个待合并待起点
    int second = mid + 1;//第二个待合并待起点
    int out = start;//合并结果待起点
    while (first <= mid && second <= end) {
        if (input[first] < input[second]) {
            output[out++] = input[first++];
            swapTime++;
        } else {
            output[out++] = input[second++];
            swapTime++;
        }
    }
    while (first <= mid) {
        output[out++] = input[first++];
        swapTime++;
    }
    while (second <= end) {
        output[out++] = input[second++];
        swapTime++;
    }
    for (int i = start; i <= end; i++) {
        input[i] = output[i];
        swapTime++;
    }
}

int *mergeSort(int *raw, int start, int end, int *buffer, int &swapTime) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(raw, start, mid, buffer, swapTime);
        mergeSort(raw, mid + 1, end, buffer, swapTime);
        merge(raw, start, mid, end, buffer, swapTime);
    }
    return raw;
}

int max(const int *raw, int len) {
    int max = raw[0];
    for (int i = 1; i < len; ++i) {
        if (raw[i] > max) {
            max = raw[i];
        }
    }
    return max;
}

int countSort(int *raw, int len, int bit) {
    auto output = new int[len];
    int swapTime = 0;
    int i, buckets[10] = {0};

    //将数据出现的次数储存在bucket
    for (i = 0; i < len; ++i) {
        buckets[(raw[i] / bit) % 10]++;
        swapTime++;
    }
    //更改buckets[i]目的是让更改后的buckets[i]的值 是该数据在output[]中的位置
    for (i = 1; i < 10; i++) {
        buckets[i] += buckets[i - 1];
    }

    // 将数据存储到临时数组output[]中
    for (i = len - 1; i >= 0; i--) {
        output[buckets[(raw[i] / bit) % 10] - 1] = raw[i];
        buckets[(raw[i] / bit) % 10]--;
    }
    // 将排序好的数据赋值给a[]
    for (i = 0; i < len; i++) {
        raw[i] = output[i];
    }
    return swapTime;
}

int *radixSort(int *raw, int len) {
    int maxNum = max(raw, len);
    //todo:确定这个swapTime到底该在哪里！！！
    int bit, time, swapTime = 0;
    BEGIN_RECORD
        for (bit = 1; maxNum / bit > 0; bit = bit * 10) {
            swapTime = countSort(raw, len, bit);
        }
    END_RECORD(time)
    cout << "The time taken for radix sort is: \t" << time << "ms" << endl;
    cout << "The number of radix sort's swap time is: \t" << swapTime << endl;

}