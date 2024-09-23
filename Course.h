
//////////////////////////////课程类//////////////////////////////////////
#ifndef STUDENT_H
#define STUDENT_H
#include <map>
#include <vector>

#include "Message.h"
//#include <iostream>
//using namespace std;

class Course//储存课程信息
{
    std::vector<Message>sss;
    std::map<std::string, int>ss;//学号与位置
    std::map<std::string, int>::iterator ss1;
    std::string  no, name, banhao, Teacher, where[5];//课程代号、课程名称、教学班号，任课老师，上课地点
    int number, time[5], n;//课容量，上课时间，上课次数
    float xuefen, chengji;//学分，成绩
public:
    Course(std::string n, std::string na, float fen, int x, std::string z) : no(n), name(na), xuefen(fen), number(x), banhao(z) { chengji = 0; Teacher = "-1"; }//课程代号、课程名称、学分、课容量、教学班号
    Course() {
        name = "-1"; no = "-1"; banhao = "-1"; Teacher = "-1";
        xuefen = 0; number = 0; chengji = 0; //无参构造输入默认值
    }
    std::string getno() { return no; }//获取课程代码
    void setno(std::string n) { no = n; }//设置课程代码
    std::string getbanhao() { return banhao; }//获取班号
    void setbanhao(std::string n) { banhao = n; }//设置班号
    std::string getname() { return name; }//获取课程名
    void setname(std::string n) { name = n; }//更改课程名
    std::string getteacher() { return Teacher; }//获取任课老师
    std::string getsssnumber(int a) { return sss[a].snumber; }//获取所含学生学号
    std::string getsssname(int a) { return sss[a].sname; }//获取所含学生名字
    std::string getsssclas(int a) { return sss[a].sclas; }//获取所含学生班号
    float getsssps(int a) { return sss[a].ps; }//获取平时成绩             
    float getsssks(int a) { return sss[a].ks; }//获取考试成绩
    void displaystudent();//显示这门课程的所有学生信息
    int sssn() { return sss.size(); }//获取这门课的选课人数
    void addstudent(std::string a, std::string b, std::string c, float x, float y);//在这门课里增加一个学生
    void erasestudent(std::string a);//在这门课中删除这个学号学号的学生
    void setteacher(std::string n) { Teacher = n; }//设置任课老师的编号
    float getxuefen() { return xuefen; }//获取学分
    void setxuefen(float n) { xuefen = n; }//设置学分
    int getnumber() { return number; }//获取课容量
    void setnumber(int n) { number = n; }//设置课容量
    float getichengji(std::string a) { return sss[ss[a]].ps * 0.3 + sss[ss[a]].ks * 0.7; }//以学号获取成绩，平时成绩：考试成绩=3：7
    int getn() { return n; }//获取上课次数
    void paixv();//更新map容器以同步vector容器变化
    void tianjiaps(std::string a, float b) { sss[ss[a]].ps = b; }//输入学号和平时成绩，添加设置平时成绩
    void tianjiaks(std::string a, float b) { sss[ss[a]].ks = b; }//输入学号和考试成绩，添加设置考试成绩
    float getps(std::string a) { ss1 = ss.find(a); if (ss1 != ss.end()) return sss[ss[a]].ps; else return -1; }
    float getks(std::string a) { ss1 = ss.find(a); if (ss1 != ss.end()) return sss[ss[a]].ks; else return -1; }
    float getchengji(std::string a) { ss1 = ss.find(a); if (ss1 != ss.end()) return sss[ss[a]].ps * 0.3 + sss[ss[a]].ks * 0.7; else return -1; }//获取该生本门成绩，平时成绩：考试成绩=3：7
    int gettime(int a) { return time[a]; }//获取上课的时间
    std::string getwhere(int a) { return where[a]; }//获取上课地点
    void chengjipaixu();//根据成绩对该课程内的学生进行排序
    friend std::ostream& operator<<(std::ostream& os, Course& d);//显示这门课的所有信息
    friend std::istream& operator>>(std::istream& is, Course& d);//输入这门课的信息，创建一门课
   
};
#endif