
/////////////////////////学生类//////////////////////////////////////
#ifndef STUDENT_Z
#define STUDENT_Z
#include"Course.h"
#include<map>
#include<vector>
#include <string>
class Student {
    std::vector<Course>c;//存储学生选的课
    std::vector<Course>::iterator it;//创建一个指针方便操作
    std::map<std::string, int>ma;
    std::map<std::string, int>::iterator ma1;
    Course z;
    std::string name, number, clas;//姓名、学号、班级
    int n;//所选课程总和
    float average, jidian, zong;//平均成绩，绩点，总成绩
    float s;//课程绩点总和

    std::string kebiao[6][8];//课表
    float all;//已获取的学分
public:
    Student(std::string num, std::string na, std::string cla) :number(num), name(na), clas(cla)//依次输入学生学号、姓名、班级创建一个学生
    {
        for (int i = 0; i <= 5; i++)
            for (int j = 0; j <= 7; j++)
                kebiao[i][j] = "--------";
    }
    Student() {
        name = "-1"; number = "-1"; clas = "-1";
    }
    std::string getnumber() { return number; }//获取学号
    void setnumber(std::string m) { number = m; }//设置学号
    std::string getname() { return name; }//获取姓名
    void setname(std::string m) { name = m; }//设置姓名
    std::string getclas() { return clas; }//获取班级
    void setclas(std::string m) { clas = m; }//设置班级
    int getn() { return c.size(); }//获取学生的个数
    void setn(int a) { n = a; }//设置学生选课数的总和
    float getxuefen() { return all; }//获取该学生已经获取的学分
    float getjidian() { return jidian; }//获取该学生的绩点
    void setjidian(float a) { jidian = a; }//设置绩点
    float getaverage() { return average; }//获取平均成绩
    void NEW();//对平均成绩和绩点进行更新
    void add(Course a);//增加学生选的一个课程
    void erasee(std::string noo);//退出学生选的一门课程
    float dankechengji(int i) { return c[i].getichengji(number); }//获取该学生在这一门课中的成绩
    void paixv();//根据课程代码对学生排序
    void kebiaodisplay();//显示课表
    void displayalll();//载入绩点，绩点等于加权总分除以总学分，加权总分等于该科成绩除以10的商减去5的差除以该科学分
    int chake(int a) { if (kebiao[a % 10][a / 10] != "--------") return 1; else return 0; }//判断课表对应位置是否为空
    int chakecheng(std::string a) { ma1 = ma.find(a); if (ma1 != ma.end()) return ma[a]; else return -1; }//判断该生是否选择此刻
    std::string courseno(int k) { return c[k].getno(); }//获取该生选择的第几个课程的代号
    std::string coursehao(int j) { return c[j].getbanhao(); }//获取该生选择的第几个课程的班号
    friend std::ostream& operator<<(std::ostream& os, Student& d);//显示该生所有信息
    friend std::istream& operator>>(std::istream& is, Student& d);//输入信息实例化一个学生类（创建一个学生）
    void displayall();//显示该生在这一门课程中的所有成绩
};
#endif