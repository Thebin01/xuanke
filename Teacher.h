/////////////////////////老师类//////////////////////////////////////
#ifndef STUDENT_N
#define STUDENT_N
#include"Course.h"


#include<map>
#include<vector>
#include<iostream>
using namespace std;
class Teacher {
    string hao;
    string yuanxi;
    string name;
    int number;
    vector<Course>c;
    vector<Course>::iterator it;
    map<string, int>ma;
    map<string, int>::iterator ma1;
    Course z;
    string kebiao[6][8];
public:
    Teacher(string a, string b, string c) :hao(a), yuanxi(c), name(b)
    {
        for (int i = 0; i <= 5; i++)
            for (int j = 0; j <= 7; j++)
                kebiao[i][j] = "--------";
    }
    Teacher() {
        hao = "-1"; yuanxi = "-1"; name = "-1"; number = 0;
    }
    string gethao() { return hao; }
    void sethao(string a) { hao = a; }
    string getyuanxi() { return yuanxi; }
    void setyuanxi(string a) { yuanxi = a; }
    string getname() { return name; }
    void setname(string a) { name = a; }
    int getnumber() { return c.size(); }
    void setnumber(int a) { number = a; }
    void paixv();
    void add(Course a);
    int chake(int a) { if (kebiao[a % 10][a / 10] != "--------") return 1; else return 0; }
    int chakecheng(string a, string b) { ma1 = ma.find(a); if (ma1 != ma.end() && c[ma[a]].getbanhao() == b) return ma[a]; else return -1; }//判断输入的课程以及班号是否有误
    string courseno(int k) { return c[k].getno(); }
    int chakechengm(string a) { ma1 = ma.find(a); if (ma1 != ma.end()) return ma[a]; else return -1; }
    string coursehao(int j) { return c[j].getbanhao(); }
    void erasee(string noo);
    void kebiaodisplay();
    void displaystudent(string a, string b);//输入课程代码及班号以显示该课程已选学生数即成绩排名
    void setpschengji(string a, int i, float ji)//输入学生学号，容器中对应位置，平时成绩，从而设置平时成绩
    {
        c[ma[a]].tianjiaps(c[ma[a]].getsssnumber(i), ji);//ma[a]即在ma容器中有一对一关系，学号a在其中对应一个位置数
    }
    void setkschengji(string a, int i, float ji)
    {
        c[ma[a]].tianjiaks(c[ma[a]].getsssnumber(i), ji);
    }
    friend ostream& operator<<(ostream& os, Teacher& d);
    friend istream& operator>>(istream& is, Teacher& d);
};

#endif