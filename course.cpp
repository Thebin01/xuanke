#include "Course.h"
#include<iostream>
#include <algorithm>
using namespace std;

bool cmp4(Message a, Message b)
{
    return (a.ps * 0.3 + a.ks * 0.7) > (b.ps * 0.3 + b.ks * 0.7);
}

void Course::paixv()
{
    //sort(sss.begin(),sss.end(),ccc);
    ss.clear();
    for (int i = 0; i < sss.size(); i++)
        ss.insert(make_pair(sss[i].snumber, i));
}

void Course::chengjipaixu()
{
    sort(sss.begin(), sss.end(), cmp4);
}

void Course::addstudent(string a, string b, string c, float x, float y)
{
    struct Message A = { a,b,c,x,y };
    sss.push_back(A);
    paixv();
}
void Course::erasestudent(string a)
{
    paixv();//cout<<sss.size()<<endl;
    ss1 = ss.find(a);
    if (ss1 != ss.end())
    {
        ss.erase(ss1);
        sss.erase(sss.begin() + ss1->second); paixv();
    }
}
void Course::displaystudent()
{
    int i;
    cout << "共有" << sss.size() << "人选了此门课程" << endl;
    if (sss.size() == 0) return;
    cout << "选课学生信息：" << endl;
    cout << "学生学号\t学生姓名\t所属班级\t平时成绩\t考试成绩\t综合成绩" << endl;
    chengjipaixu();
    for (i = 0; i < sss.size(); i++)
    {
        cout << sss[i].snumber << "\t\t" << sss[i].sname << "\t\t" << sss[i].sclas << "\t\t" << sss[i].ps << "\t\t" << sss[i].ks << "\t\t";
        cout << sss[i].ps * 0.3 + sss[i].ks * 0.7 << endl;//计算综合成绩
    }
    cout << endl;
}