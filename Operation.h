
#ifndef STUDENT_D
#define STUDENT_D
#include"Manager.h"

class Operation:public Manager
{
public:
    void menu1(string temp);
};
class Operation_teacher
{
    Teacher t;
    vector<Course>c;
    vector<Course>::iterator it;
    map<string, int>ma;
    map<string, int>::iterator ma1;
public:
    void addc();
    void erasec();
    void xuanze();
    void displaycourse();
    Teacher A() { return t; }
    void load1();
    void save1();
    void pschengji(string a, string b);//教师填写学生平时成绩
    void kschengji(string a, string b);//教师填写学生考试成绩
    Operation_teacher(Teacher a) :t(a) { load1(); xuanze(); save1(); }
};

class Operation_student
{
    Student s;
    vector<Course>c;
    vector<Course>::iterator it;
    map<string, int>ma;
    map<string, int>::iterator ma1;
public:
    void displaycourse();
    void addc();
    void erasec();
    void load1();
    Student A() { return s; }
    void xuanze();
    void jieguo();
    void save1();
    Operation_student(Student a) :s(a) { load1(); xuanze(); save1(); }
};

#endif