/////////////////////////管理员类//////////////////////////////////////
#ifndef STUDENT_C
#define STUDENT_C
#include"Student.h"
#include"Teacher.h"


#include<iostream>
using namespace std;

class Manager
{
public:
    vector<Course>c;
    vector<Course>::iterator it;
    map<string, int>ma;
    map<string, int>::iterator ma1;
    vector<Student>s;
    vector<Student>::iterator its;
    map<string, int>mas;
    map<string, int>::iterator ma1s;
    vector<Teacher>t;
    vector<Teacher>::iterator itt;
    map<string, int>mat;
    map<string, int>::iterator ma1t;
    
    string mima;//密码
    string zhanghao;//学生账号
    //string zhanghao_teacher;//教师账号
	int kecnt;
	int dengluflag = -1;

    void addcourse();
    void addstudent();
    void addteacher();

    int searchcourse(string no, string aa);
    int searchstudent(string no);
    int searchteacher(string no);

    void deletecourse();
    void deletestudent();
    void deleteteacher();

    void querycourse();
    int  qquerycourse(string name, string hao);
    void querystudent();
    int  qquerystudent(string name);
    void queryteacher();
    int  qqueryteacher(string name);

    void chargecourse();
    void chargestudent();
    void chargeteacher();

    void displaycourse(int a);
    void displaystudent();
    void displayteacher();

    void menudisplay1();
    void menudisplay2(int a);
    void menu2(int a);
    void menu1();

    void load1();
    void load2();
    void load3();
    void save1();
    void save2();
    void save3();

    void paixvc();
    void paixvs();
    void paixvt();

    void setzhanghao_student(string _zhanghao);
    void setzhanghao_teacher(string _zhanghao);
	void setmima_student(string _yanz);
    void setmima_teacher(string _yanz);
	void checkC();
	bool zhanghaopipei(string _zhanghao);
	bool mimapipei(string _yanz);
    string Login();//登录
	void read_student();
    void read_teacher();
    //读取
    string Login_student();
    string Login_teacher();
	void Login_manager();
};

#endif