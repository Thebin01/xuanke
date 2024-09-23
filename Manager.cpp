#include "Manager.h"
#include"Student.h"
#include"Teacher.h"
#include<algorithm>
#include<fstream>

bool cmp2(Course a, Course b)
{
   return a.getno() < b.getno();
}
bool cmps(Student a, Student b)
{
    return a.getnumber() < b.getnumber();
}
bool cmpt(Teacher a, Teacher b)
{
    return a.gethao() < b.gethao();
}

ostream& operator<<(ostream& os, Student& d)
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "==============================================================================================" << endl;
    cout << "学号\t姓名\t班级\t平均学分绩点\t\t 选课总数" << endl;
    os << d.number << "\t" << d.name << "\t" << d.clas << "\t\t" << d.getjidian() << "\t\t" << d.c.size() << endl;
    for (int i = 0; i < d.c.size(); i++)
    {
        os << d.c[i];
        cout << "成绩:" << d.dankechengji(i) << endl << endl;
    }
    cout << "==============================================================================================" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl << endl;
    return os;
}
istream& operator>>(istream& is, Student& d)
{
    string a, b, c, x;
    cout << "依次输入学生学号、姓名、班级,按-1结束输入" << endl;
    is >> a;
    if (a == "-1") { d.setnumber(a); return is; }
    is >> b >> c;
    Student t(a, b, c);
    d = t;
    return is;
}

ostream& operator<<(ostream& os, Course& d)
{
    int i;
    cout << "课程代号\t课程名称\t课程学分\t课堂容量\t教学班号\t任课老师" << endl;
    os << d.no << "\t\t" << d.name << "\t\t" << d.xuefen << "\t\t" << d.number << "\t\t" << d.banhao << "\t\t";
    if (d.Teacher == "-1") cout << "暂无" << endl;
    else cout << d.Teacher;
    cout << endl;
    cout << "上课时间\t上课地点" << endl;//应该是文件读入课程信息、、
    if (d.n == 0) cout << "暂无" << endl;
    for (i = 0; i < d.n; i++)
    {
        cout << "周";
        os << d.time[i] / 10;
        cout << "第";
        os << d.time[i] % 10;
        cout << "节";
        os << "\t" << d.where[i] << endl;
    }
    return os;
}
istream& operator>>(istream& is, Course& d)
{
    string a, b, c;
    float x;
    int z, i = 0, k = 0;
    cout << "请依次输入课程代号、课程名称、学分、课容量、教学班号，输入-1结束" << endl;
    is >> a;
    if (a == "-1") { d.setno("-1"); return is; }
    is >> b;
    is >> x;
    is >> z >> c;
    Course t(a, b, x, z, c);
    while (1)
    {
        cout << "输入上课时间、地点，输入-1结束" << endl;
        is >> t.time[i];
        if (t.time[i] == -1) break;
        is >> t.where[i];
        i++;
    }
    d = t;
    d.n = i;
    return is;
}

ostream& operator<<(ostream& os, Teacher& d)
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "==============================================================================================" << endl;
    cout << "教师工号\t教师姓名\t所属院系\t教授课程总数" << endl;
    os << d.hao << "\t\t" << d.name << "\t\t" << d.yuanxi << "\t\t" << d.c.size() << endl;
    cout << "教授课程:" << endl;
    for (int i = 0; i < d.c.size(); i++)
    {
        os << d.c[i] << endl;
        d.c[i].displaystudent();
    }
    cout << "==============================================================================================" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    return os;
}
istream& operator>>(istream& is, Teacher& d)
{
    string a, b, c;
    cout << "依次输入教师工号、教师姓名、院系，输入-1结束" << endl;
    is >> a;
    if (a == "-1") { d.sethao(a); return is; }
    is >> b >> c;
    Teacher t(a, b, c);
    d = t;
    return is;
}



void Manager::paixvc()
{
    ma.clear();
    sort(c.begin(), c.end(), cmp2);
    for (int i = 0; i < c.size(); i++)
        ma.insert(make_pair(c[i].getno(), i));
}
void Manager::paixvs()
{
    mas.clear();
    sort(s.begin(), s.end(), cmps);
    for (int i = 0; i < s.size(); i++)
        mas.insert(make_pair(s[i].getnumber(), i));
}
void Manager::paixvt()
{
    mat.clear();
    sort(t.begin(), t.end(), cmpt);
    for (int i = 0; i < t.size(); i++)
        mat.insert(make_pair(t[i].gethao(), i));
}
void Manager::addcourse()
{
    int a;
    Course z;
    while (1)
    {
        system("cls");
        cin >> z;
        if (z.getno() == "-1") break;
        a = searchcourse(z.getno(), z.getbanhao());
        if (a != -1) cout << "已存在此门课程" << endl;
        else { c.push_back(z); cout << "已添加" << endl; }
        system("pause");
    }
    paixvc();
}
void Manager::addstudent()
{
    Student z;
    while (1)
    {
        system("cls");
        cin >> z;
        if (z.getnumber() == "-1") break;
        if (searchstudent(z.getnumber()) != -1) cout << "已存在此学号学生" << endl;
        else { s.push_back(z); cout << "学生添加成功" << endl; }
        system("pause");
    }paixvs();
}
void Manager::addteacher()
{
    Teacher z;
    while (1)
    {
        system("cls");
        cin >> z;
        if (z.gethao() == "-1") break;
        if (searchteacher(z.gethao()) != -1) cout << "已存在此工号教师" << endl;
        else { t.push_back(z); cout << "教师添加成功" << endl; }
        system("pause");
    }paixvt();
}
int Manager::searchcourse(string no, string aa)
{
    int i;
    for (i = 0; i < c.size(); i++)
        if (c[i].getno() == no && c[i].getbanhao() == aa)
            return i;
    return -1;
}
int Manager::searchstudent(string no)
{
    int i;
    for (i = 0; i < s.size(); i++)
        if (s[i].getnumber() == no)
            return i;
    return -1;
}
int Manager::searchteacher(string no)
{
    int i;
    for (i = 0; i < t.size(); i++)
        if (t[i].gethao() == no)
            return i;
    return -1;
}
void Manager::querycourse()
{
    int k;
    string a;
    string name; system("cls");
    while (1)
    {
        cout << "输入所查课程的课程号和教学班号,输入-1结束" << endl;
        cin >> name;
        if (name == "-1") break;
        cin >> a;
        k = searchcourse(name, a);
        if (k != -1) { cout << c[k] << endl; c[k].displaystudent(); }
        else cout << "课程号输入有误，请重新输入" << endl;
    }
}

void Manager::querystudent()
{
    int k;
    string name; system("cls");
    while (1)
    {
        cout << "输入所查学生的学号,输入-1结束" << endl;
        cin >> name;
        if (name == "-1") break;
        k = searchstudent(name);
        if (k != -1) cout << s[k] << endl;
        else cout << "学号输入有误，请重新输入" << endl;
    }

}
int Manager::qquerycourse(string name, string hao)
{
    int k;
    k = searchcourse(name, hao);
    return k;
}
int Manager::qquerystudent(string name)
{
    int k;
    k = searchstudent(name);
    return k;
}
int Manager::qqueryteacher(string name)
{
    int k;
    k = searchteacher(name);
    return k;
}
void Manager::queryteacher()
{
    int k;
    string name; system("cls");
    while (1)
    {
        cout << "输入所查教师的工号,输入-1结束" << endl;
        cin >> name;
        if (name == "-1") break;
        k = searchteacher(name);
        if (k != -1) cout << t[k] << endl;
        else cout << "工号输入有误，请重新输入" << endl;
    }
}
void Manager::deletecourse()
{
    int k;
    string na, hao; system("cls");
    while (1)
    {
        cout << "输入要删除的课程的课程号和班号,输入-1结束" << endl;
        cin >> na;
        if (na == "-1") break;
        cin >> hao;
        k = searchcourse(na, hao);
        if (k != -1) c.erase(c.begin() + k);
        else cout << "课程号输入有误，请重新输入" << endl;
    }
}
void Manager::deletestudent()
{
    int k;
    string na; system("cls");
    while (1)
    {
        cout << "输入要删除的学生的学号,输入-1结束" << endl;
        cin >> na;
        if (na == "-1") break;
        k = searchstudent(na);
        if (k != -1) s.erase(s.begin() + k);
        else cout << "学号输入有误，请重新输入" << endl;
    }
}
void Manager::deleteteacher()
{
    int k;
    string na; system("cls");
    while (1)
    {
        cout << "输入要删除的教师的工号,输入-1结束" << endl;
        cin >> na;
        if (na == "-1") break;
        k = searchteacher(na);
        if (k != -1) t.erase(t.begin() + k);
        else cout << "工号输入有误，请重新输入" << endl;
    }
}
void Manager::chargecourse()
{
    int k;
    string na, hao;
    Course zz; system("cls");
    while (1)
    {
        cout << "输入要修改的课程的课程号和班号,输入-1结束" << endl;
        cin >> na >> hao;
        if (na == "-1") break;
        k = searchcourse(na, hao);
        if (k != -1)
        {
            cout << c[k] << endl;
            cin >> zz;
            c[k] = zz;
            cout << "修改后的信息：" << endl;
            cout << c[k] << endl;
        }
        else cout << "课程号输入有误，请重新输入" << endl;
    }
    paixvc();
}
void Manager::chargestudent()
{
    int k;
    string na;
    Student zz; system("cls");
    while (1)
    {
        cout << "输入要修改的学生的学号,输入-1结束" << endl;
        cin >> na;
        if (na == "-1") break;
        k = searchstudent(na);
        if (k != -1)
        {
            cout << s[k] << endl;
            cin >> zz;
            s[k] = zz;
            cout << "修改后的信息：" << endl;
            cout << s[k] << endl;
        }
        else cout << "学号输入有误，请重新输入" << endl;
    }paixvs();
}
void Manager::chargeteacher()
{
    int k;
    string na; system("cls");
    Teacher zz;
    while (1)
    {
        cout << "输入要修改的教师的工号,输入-1结束" << endl;
        cin >> na;
        if (na == "-1") break;
        k = searchteacher(na);
        if (k != -1)
        {
            cout << t[k] << endl;
            cin >> zz;
            t[k] = zz;
            cout << "修改后的信息：" << endl;
            cout << t[k] << endl;
        }
        else cout << "工号输入有误，请重新输入" << endl;
    }paixvt();
}
void Manager::displaycourse(int a)
{
    system("cls");
    string ss;

    for (int i = 0; i < c.size(); i++)
    {
        cout << "----------------------------------------------------------------------------------------------" << endl;
        cout << c[i] << endl;
        if (a)
        {
            //cout<<"共有"<<c[i].sssn()<<"人选了此课"<<endl;
            if (c[i].sssn() != 0)
            {
                c[i].displaystudent();
            }
        }
        cout << "----------------------------------------------------------------------------------------------" << endl;
    }

}
void Manager::displaystudent()
{
    system("cls");
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << endl;
}
void Manager::displayteacher()
{
    system("cls");
    for (int i = 0; i < t.size(); i++)
        cout << t[i] << endl;
}
void Manager::load1()//载入课程
{
    Course x1;
    int n;
    string m, z, l, a;
    float b, x, y;
    ifstream infile("Course.txt", ios::in);
    if (!infile) return;
    c.clear();
    while (infile >> x1)
    {
        if (x1.getno() == "-1") break;
        infile >> m;
        x1.setteacher(m);
        infile >> n;
        for (int i = 0; i < n; i++)
        {
            infile >> m >> z >> l >> x >> y;
            x1.addstudent(m, z, l, x, y);
        }
        c.push_back(x1);
        ma.insert(make_pair(x1.getno(), c.size() - 1));
    }
    infile.close(); system("cls");
}
void Manager::load2()//载入学生
{
    int a;
    Course x;
    string zz, hao;
    Student x1;
    float l;
    ifstream infile("Student.txt", ios::in);
    if (!infile) return;
    s.clear();
    while (infile >> x1)
    {

        if (x1.getnumber() == "-1") break;
        infile >> l;
        x1.setjidian(l);
        infile >> a;
        while (a--)
        {
            infile >> zz >> hao;
            x1.add(c[qquerycourse(zz, hao)]);
        }
        x1.setn(a); x1.displayalll();
        s.push_back(x1);
        mas.insert(make_pair(x1.getnumber(), s.size() - 1));
    }
    infile.close(); system("cls");
}
void Manager::load3()//载入教师
{
    int a;
    Course x;
    string zz, hao;
    Teacher x1;
    ifstream infile("Teacher.txt", ios::in);
    if (!infile) return;
    t.clear();
    while (infile >> x1)
    {

        if (x1.gethao() == "-1") break;
        infile >> a;
        while (a--)
        {
            infile >> zz >> hao;

            x1.add(c[qquerycourse(zz, hao)]);
        }x1.setnumber(a);
        t.push_back(x1);
        mat.insert(make_pair(x1.gethao(), t.size() - 1));
    }
    infile.close(); system("cls");
}
void Manager::save1()//保存课程
{
    int j, k;
    ofstream outfile("Course.txt", ios::out);
    if (!outfile) return;
    for (int i = 0; i < c.size(); i++)
    {
        outfile << c[i].getno() << "\t\t" << c[i].getname() << "\t\t" << c[i].getxuefen();
        outfile << "\t\t" << c[i].getnumber() << "\t\t" << c[i].getbanhao() << "\t\t";
        for (k = 0; k < c[i].getn(); k++)
        {
            outfile << c[i].gettime(k) << "\t" << c[i].getwhere(k) << endl;

        }
        outfile << "-1" << endl;
        outfile << c[i].getteacher() << endl;
        outfile << c[i].sssn() << endl;
        if (c[i].sssn() != 0)
        {
            for (j = 0; j < c[i].sssn(); j++)
            {
                outfile << c[i].getsssnumber(j) << "\t" << c[i].getsssname(j) << "\t" << c[i].getsssclas(j);
                outfile << "\t" << c[i].getsssps(j) << "\t" << c[i].getsssks(j) << endl;
            }
        }
    }
    outfile << "-1" << endl;
    outfile.close(); system("cls");
}
void Manager::save2()//保存学生
{
    ofstream outfile("Student.txt", ios::out);
    if (!outfile) return;

    for (int i = 0; i < s.size(); i++)
    {
        outfile << s[i].getnumber() << "\t" << s[i].getname() << "\t" << s[i].getclas() << "\t" << s[i].getjidian() << "\t" << s[i].getn() << endl;
        for (int j = 0; j < s[i].getn(); j++)
            outfile << s[i].courseno(j) << "\t" << s[i].coursehao(j) << endl;
    }
    outfile << "-1" << endl;
    outfile.close(); system("cls");
}
void Manager::save3()//保存老师
{
    ofstream outfile("Teacher.txt", ios::out);
    if (!outfile) return;
    for (int i = 0; i < t.size(); i++)
    {
        outfile << t[i].gethao() << "\t" << t[i].getname() << "\t";
        outfile << t[i].getyuanxi() << "\t" << t[i].getnumber() << endl;

        for (int j = 0; j < t[i].getnumber(); j++)
            outfile << t[i].courseno(j) << "\t" << t[i].coursehao(j) << endl;
    }
    outfile << endl << "-1" << endl;
    outfile.close(); system("cls");
}
void Manager::menudisplay1()//主界面
{
    cout << "*******************************************" << endl;
    cout << "               尊敬的管理员              " << endl;
    cout << "             欢迎使用选课系统              " << endl;
    cout << " 0:              退出                      " << endl;
    cout << " 1:              课程管理                  " << endl;
    cout << " 2:              学生管理                  " << endl;
    cout << " 3:              教师管理                  " << endl;
    cout << "*******************************************" << endl;
    return;
}
void Manager::menudisplay2(int a)//子界面
{
    cout << "*******************************************" << endl;

    if (a == 1)
    {
        cout << "            欢迎使用课程管理系统           " << endl;
        cout << " 0:              退出                      " << endl;
        cout << " 1:              增加课程                  " << endl;
        cout << " 2:              删除课程                  " << endl;
        cout << " 3:              修改课程                  " << endl;
        cout << " 4:              查询课程                  " << endl;
        cout << " 5:              展示所有课程及选课结果    " << endl;
    }
    if (a == 2)
    {
        cout << "            欢迎使用学生管理系统           " << endl;
        cout << " 0:              退出                      " << endl;
        cout << " 1:              增加学生                  " << endl;
        cout << " 2:              删除学生                  " << endl;
        cout << " 3:              修改学生                  " << endl;
        cout << " 4:              查询学生                  " << endl;
        cout << " 5:              展示所有学生              " << endl;
    }
    if (a == 3)
    {
        cout << "            欢迎使用教师管理系统           " << endl;
        cout << " 0:              退出                      " << endl;
        cout << " 1:              增加教师                  " << endl;
        cout << " 2:              删除教师                  " << endl;
        cout << " 3:              修改教师                  " << endl;
        cout << " 4:              查询教师                  " << endl;
        cout << " 5:              展示所有老师              " << endl;
    }
    cout << "*******************************************" << endl;
}
void Manager::menu1()//输出管理员首界面
{
    int x;
    while (1)
    {
        system("cls");
        menudisplay1();//输出界面
        cout << "请输入你的选择:" << endl;
        cin >> x;
        if (!x) break;
        system("cls");
        menu2(x);
    }
}
void Manager::menu2(int a)
{
    int x;
    system("cls");

    if (a == 1)//课程管理
    {
        while (1)
        {
            menudisplay2(a);
            cout << "请输入你的选择" << endl;
            cin >> x;
            if (!x) break;
            switch (x)
            {
                case 1:
                    addcourse();//增加课程
                    break;
                case 2:
                    deletecourse();//删除课程
                    break;
                case 3:
                    chargecourse();//修改课程
                    break;
                case 4:
                    querycourse();//查询课程
                    break;
                case 5:
                    displaycourse(1);//展示所有课程及选课结果
                    break;
            }
            system("pause");
            system("cls");
        }
    }
    if (a == 2)//学生管理
    {
        while (1)
        {
            menudisplay2(a);
            cout << "请输入你的选择" << endl;
            cin >> x;
            if (!x) break;
            switch (x)
            {
            case 1:
                addstudent();//增加学生
                break;
            case 2:
                deletestudent();//删除学生
                break;
            case 3:
                chargestudent();//修改学生
                break;
            case 4:
                querystudent();//查询学生 
                break;
            case 5:
                displaystudent();//展示所有学生
                break;
            }
            system("pause");
            system("cls");
        }
    }
    if (a == 3)//教师管理
    {
        while (1)
        {
            menudisplay2(a);
            cout << "请输入你的选择" << endl;
            cin >> x;
            if (!x) break;
            switch (x)
            {
            case 1:
                addteacher();
                break;
            case 2:
                deleteteacher();
                break;
            case 3:
                chargeteacher();
                break;
            case 4:
                queryteacher();
                break;
            case 5:
                displayteacher();
                break;
            }
            system("pause");
            system("cls");
        }
    }

}

/////启动部分
#define SIZE 100//最大用户容量
int stucnt = 0;//用作储存当前已注册用户数
Manager user[SIZE];//声明辅助管理类的实例作为用户数据的中转站
string Manager::Login()
{
    
   

    do
    {
        int ssw;
        dengluflag = -1;//重置flag
        cout << "1.学生登录" << endl;
        cout << "2.教师登录" << endl;
        cout << "请选择：" << endl;
        cin >> ssw;
        switch (ssw)
        {
        case 1://学生登录
            user[0].read_student();//导入学生数据
            return Login_student();
        case 2: 
            user[0].read_teacher();//导入教师数据
            return Login_teacher();
        }

    } while (dengluflag < 0);//如果没有找到账号则一直循环


}

void Manager::setzhanghao_student(string _zhanghao)			  //设置学生帐号
{
    zhanghao=_zhanghao;
    //cout << "申请成功" << endl;
    ofstream ofile;
    ofile.open("user_student.txt", ios::app); 
    ofile << zhanghao << endl; 
    ofile.close();
}

void Manager::setzhanghao_teacher(string _zhanghao)			  //设置教师帐号
{
    zhanghao = _zhanghao;
    cout << "申请成功" << endl;
    ofstream ofile;
    ofile.open("user_teacher.txt", ios::app);
    ofile << zhanghao << endl;
    ofile.close();
}

void Manager::setmima_student(string _mima)                 //重新设置验证码
{
    mima=_mima;
    //cout << "设置成功" << endl;
    ofstream ofile;
    ofile.open("user_student.txt", ios::app);
    ofile << mima << endl;
    ofile.close();
}
void Manager::setmima_teacher(string _mima)                 //重新设置验证码
{
    mima = _mima;
    //cout << "设置成功" << endl;
    ofstream ofile;
    ofile.open("user_teacher.txt", ios::app);
    ofile << mima << endl;
    ofile.close();
}
void Manager::checkC()						 			//查询功能
{
    cout << "账号：\n" << zhanghao << endl;
    cout << "密码：\n" << mima << endl;

}


bool Manager::zhanghaopipei(string _zhanghao)          //账号是否匹配
{
    if (zhanghao ==_zhanghao)return true;
    else return false;
}
bool Manager::mimapipei(string _mima)              //验证码是否匹配
{
    if (mima ==_mima)return true;
    else return false;
}

void Manager::read_student()
{
    ifstream ifile;
    ifile.open("user_student.txt", ios::in);

    stucnt = 0;

    if (!ifile.is_open())
    {
        //cout << "文件打开失败！" << endl;
        return;
    }

    for (int i = 0; !ifile.eof(); i++)//eof()指针到结尾是返回值为1，即结束循环，并已经将文件中所有用户信息导入
    {
        ifile >> user[i].zhanghao;
        ifile >> user[i].mima;
        stucnt++;
    }
    stucnt--;
    ifile.close();//关闭答开的所有文件
}
void Manager::read_teacher()
{
    ifstream ifile;
    ifile.open("user_teacher.txt", ios::in);

    stucnt = 0;

    if (!ifile.is_open())
    {
        //cout << "文件打开失败！" << endl;
        return;
    }

    for (int i = 0; !ifile.eof(); i++)//eof()指针到结尾是返回值为1，即结束循环，并已经将文件中所有用户信息导入
    {
        ifile >> user[i].zhanghao;
        ifile >> user[i].mima;
        stucnt++;
    }
    stucnt--;
    ifile.close();//关闭答开的所有文件
}

string Manager::Login_student()
{
    string temp;
    string temp1;
    string tempp;
    int flag = -1;
    do {
        int SW;
        
        int zhanghaoflag = -1;
        system("cls");
        cout << "1.注册账号" << endl;
        cout << "2.登陆已有账号" << endl;
        cout << "输入0退出" << endl;
        cin >> SW;
        switch (SW)
        {
        case 1:

            do
            {
                system("cls");
                cout << "请输入注册账号（即学号）" << endl;
                cin >> temp;
                for (int i = 0; i < stucnt; i++)
                {
                    if (user[i].zhanghaopipei(temp) == true)
                    {
                        cout << "账号重复，请重新输入" << endl;
                        system("pause");
                        break;
                    }
                    if (i == stucnt-1)zhanghaoflag = 1;
                }
                if (stucnt == 0)break;
                //cout << stucnt;
                
                //system("pause");

            } while (zhanghaoflag < 0);
            user[stucnt].setzhanghao_student(temp);
            

            while(1)
            {
                system("cls");
                cout << "请输入登陆密码" << endl;
                cin >> temp;
                cout << "请确认并再次输入登陆密码" << endl;
                cin >> tempp;
                system("cls");
                if (temp  != tempp)
                    cout << "两次密码输入不相同，请重新输入" << endl;
                else 
                    break;//不相同则重新输入密码
            }

            user[stucnt].setmima_student(temp);
            cout << "注册成功,注册信息如下" << endl;
            //user[stucnt].read();
            user[stucnt].checkC();
            stucnt++;
            system("pause");


            cout << "请以账号作为学号按要求输入" << endl;

            system("pause");
            addstudent();

            break;

        case 2:
            user[stucnt].read_student();//更新注册表
            system("cls");
            cout << "请输入账号" << endl;
            cin >> temp;
            for (int i = 0; i < stucnt; i++)
            {
                if (user[i].zhanghaopipei(temp) == true)
                {
                    while (1)
                    {
                        cout << "请输入登陆密码" << endl;
                        cin >> temp1;
                        if (user[i].mimapipei(temp1) == true)
                        {
                            cout << "登陆成功" << endl;
                            dengluflag = i;//没有找到账号就会保持初始值-1
                            flag = 1;
                            break;
                        }
                        else
                        {
                            cout << "验证密码错误，重试" << endl;
                        }
                    }
                }
            }
            if (dengluflag < 0)cout << "账号不存在,请重新输入账号" << endl;
            system("pause");
            break;
        case 0:
            flag = 1;
        }
    } while (flag < 0);
    return temp;
}

string Manager::Login_teacher()
{
    string temp;
    string temp1;
    string tempp;
    int flag = -1;
    do {
        int SW;
        //dengluflag = -1;//重置flag
        int zhanghaoflag = -1;
        system("cls");
        cout << "1.注册账号" << endl;
        cout << "2.登陆已有账号" << endl;
        cout << "输入0退出" << endl;
        cin >> SW;
        switch (SW)
        {
        case 1:

            do
            {
                system("cls");
                cout << "请输入注册账号（即工号）" << endl;
                cin >> temp;
                for (int i = 0; i < stucnt; i++)
                {
                    if (user[i].zhanghaopipei(temp) == true)
                    {
                        cout << "账号重复，请重新输入" << endl;
                        system("pause");
                        break;
                    }
                    if (i == stucnt-1)zhanghaoflag = 1;
                }
                if (stucnt == 0 )break;

            } while (zhanghaoflag < 0);
            user[stucnt].setzhanghao_teacher(temp);
            do
            {
                system("cls");
                cout << "请输入登陆密码" << endl;
                cin >> temp;
                cout << "请确认并再次输入登陆密码" << endl;
                cin >> tempp;
                system("cls");
                if (temp!=tempp)
                    cout << "两次密码输入不相同，请重新输入" << endl;
                else
                    break;//不相同则重新输入密码
            } while (1);

            user[stucnt].setmima_teacher(temp);
            cout << "注册成功,注册信息如下" << endl;
            //user[stucnt].read();
            user[stucnt].checkC();
            stucnt++;
            system("pause");

            cout << "请以账号作为工号按要求输入" << endl;
            addteacher();

            break;

        case 2:
            user[stucnt].read_teacher();
            system("cls");
            cout << "请输入账号" << endl;
            cin >> temp;
            for (int i = 0; i < stucnt; i++)
            {
                if (user[i].zhanghaopipei(temp) == true)
                {
                    while (1)
                    {
                        cout << "请输入登陆密码" << endl;
                        cin >> temp1;
                        if (user[i].mimapipei(temp1) == true)
                        {
                            cout << "登陆成功" << endl;
                            dengluflag = i;//没有找到账号就会保持初始值-1
                            flag = 1;
                            break;
                        }
                        else
                        {
                            cout << "验证密码错误，重试" << endl;
                        }
                    }
                }
            }
            if (dengluflag < 0)cout << "账号不存在,请重新输入账号" << endl;
            system("pause");
            break;
        case 0:
            flag = 1;
        }
    } while (flag < 0);
    return temp;
}

void Manager::Login_manager()
{
    while (1)
    {
        char temp[20];
        while (1)//检测账号
        {
            system("cls");
            cout << "请输入尊贵的管理员账号(8个8)" << endl;
            cin >> temp;
            if (strcmp("88888888", temp) == 0)
            {
                cout << "请输入登陆密码(一样)" << endl;
                break;
            }
            else
            {
                cout << "账号错误,请重新输入" << endl;
            }
        }
        while (1)//检测密码
        {
            cin >> temp;
            if (strcmp("88888888", temp) == 0)
            {
                cout << "登陆成功！" << endl; cout << "欢迎回来！" << endl; break;
            }
            else
            {
                cout << "密码错误,请重新输入" << endl;
            }
        }
        break;
    }
}
