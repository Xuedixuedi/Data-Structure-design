#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Graph.h"

using namespace std;

vector<Course> readFile();//读取文件并转化为vector<Course>
void arrangeClass(int sem, Graph *gr);//sem学期的课表
void outPut(int sem, vector<Course> ls);

bool cmp(Course a, Course b) {
    return a._time > b._time;
}

int main() {
    vector<Course> courses;
    vector<Course> ans;//排序之后的前29节
    courses = readFile();
    auto gr = new Graph(courses);
    gr->initMatrix();
    ans = gr->topologicalSort();//
    for (int i = 1; i <= 8; ++i) {
        arrangeClass(i, gr);
        cout << endl;
    }
}

vector<Course> readFile() {
    ifstream ifs;//输入
    ofstream ofstream1;//输出
    ifs.open("../in.txt");
    if (ifs.fail()) {
        cerr << "Error opeing a file" << endl;
        ifs.close();
        exit(1);
    }
    auto line = new string[10000];
    int num = 0;
    while (ifs >> line[num]) {
        num++;
    }

    vector<Course> courses;
    int j = 0;
    for (int i = 5; i < num; ++i) {
        if (line[i][0] == 'c' && line[i + 1][0] != 'c') {
            //判断是否为课号
            Course co;
            j++;//新增一个课程
            co._number = line[i];
            co._name = line[i + 1];
            int ti = stoi(line[i + 2]);
            int se = stoi(line[i + 3]);
            co._time = ti;
            co._semester = se;
            co._degree = 0;
            int k = i + 4;
            int m = 0;
            while (line[k][0] == 'c' && line[k + 1][0] == 'c') {
                co._havePre = true;
                co._pre.push_back(line[k]);
                co._degree++;
                m++;
                k++;
            }
            courses.push_back(co);
        }
    }

    ifs.close();
    return courses;//size
}


//输出文件：
void outPut(int sem, vector<Course> ls) {
    string xx = "../out0.txt";
    xx[6] = static_cast<char> (sem)+96;
    auto str = xx.c_str();
    ofstream out;
    out.open(str);
    out << "The " << sem << " semester's curriculum:" << endl;

    //我想先把ls按照课时数排一排
    sort(ls.begin(), ls.end(), cmp);
    for (int i = 0; i < ls.size(); ++i) {
//        cout << ls[i]._time << ' ';
    }

    int classtime[ls.size()];//对应课程的课时
    vector<Course> schedual;
    for (int i = 0; i < ls.size(); ++i) {
        classtime[i] = ls[i]._time;
    }

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < ls.size(); ++i) {
            if (classtime[i]) {
                if (classtime[i] % 2) {
                    //奇数情况
                    schedual.push_back(ls[i]);
                    schedual.push_back(ls[i]);
                    schedual.push_back(ls[i]);
                    classtime[i] -= 3;
                } else {
                    //偶数情况
                    schedual.push_back(ls[i]);
                    schedual.push_back(ls[i]);
                    classtime[i] -= 2;
                }
            }
        }
    }

    int hd = 4;
    int num = 0;
    string temp1;

    for (int i = 0; i < schedual.size(); ++i) {
        num++;
        out << schedual[i]._name << "\t|";
        if (schedual[i]._number != schedual[i + 1]._number && schedual[i]._number == schedual[i - 2]._number) {
            num++;
            out << "  \t|";
        }
        if (num == 4) {
            out << "午休\t|";
        }
        if (num == 8) {
            num = 0;
            out << endl;
        }
    }

    out.close();

}

void arrangeClass(int sem, Graph *gr) {
    int ttime = 0;//这些课程的总时间
    vector<Course> list;
    for (int i = 0; i < gr->_name.size(); ++i) {
        if (gr->_name[i]._semester == sem) {
            list.push_back(gr->_name[i]);
            ttime += gr->_name[i]._time;
        }
    }

    if (!gr->_classlist.empty()) {
        for (auto it = gr->_classlist.begin(); it != gr->_classlist.end(); ++it) {
            if (it->_semester == 0) {
                ttime += it->_time;
                list.push_back(*it);
                it->_semester = sem;
            }
            if (ttime > 20) {
                break;
            }
        }
    }

    outPut(sem, list);

}