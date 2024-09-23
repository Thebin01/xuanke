#include "Operation.h"

#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
void Operation::menu1(string temp)
{
    load1();
    load3(); 
    load2(); 
    system("cls");

        string a;
        a = temp;
        int ttt;
        ttt = qquerystudent(a);//tt==-1，招不到学生//获取学生账号
       

        if (ttt != -1)
        {
            cout << "学生" << a << "登陆成功" << endl; system("pause");
            Operation_student ss(s[ttt]);//以获取的学生账号创造一个学生操作类
            s[ttt] = ss.A();//传回到管理类中Student进行下一步操作
            save2();
            //save1();
        }
        else
        {
            ttt = qqueryteacher(a);
           // cout << a<<ttt; system("pause");
            if (ttt != -1) {
                cout << "教师" << a << "登陆成功" << endl; system("pause");
                Operation_teacher tt(t[ttt]);
                t[ttt] = tt.A();
                save3();
                //save1();
            }
            else {
                cout << "用户不存在,请重新输入" << endl;
                system("pause"); 
                //menu1(); 
            }
        }

    //}
}


void Operation_teacher::pschengji(string a, string b)
{
    system("cls");
    string k;
    int j;
    float ji;
    for (j = 0; j < c.size(); j++)
        if (c[j].getno() == a && c[j].getbanhao() == b)
        {
            cout << "请对应输入学生平时成绩" << endl;
            cout << "学号\t\t姓名\t\t平时成绩" << endl;
            for (int i = 0; i < c[j].sssn(); i++)
            {
                cout << c[j].getsssnumber(i) << "\t" << c[j].getsssname(i) << "\t\t";
                cin >> ji;
                cout << endl;
                c[j].tianjiaps(c[j].getsssnumber(i), ji);
                t.setpschengji(a, i, ji);
            }break;
        }
    if (j == c.size()) cout << "输入有误，请重新输入" << endl; system("pause");

}
void Operation_teacher::kschengji(string a, string b)
{
    system("cls");
    string k;
    int j;
    float ji;
    for (j = 0; j < c.size(); j++)
        if (c[j].getno() == a && c[j].getbanhao() == b)
        {
            cout << "请对应输入学生考试成绩" << endl;
            cout << "学号\t\t姓名\t\t考试成绩" << endl;
            for (int i = 0; i < c[j].sssn(); i++)
            {
                cout << c[j].getsssnumber(i) << "\t" << c[j].getsssname(i) << "\t\t";
                cin >> ji;
                cout << endl;
                c[j].tianjiaks(c[j].getsssnumber(i), ji);
                t.setkschengji(a, i, ji);
            }break;
        }
    if (j == c.size()) cout << "输入有误，请重新输入" << endl; system("pause");
}

void Operation_teacher::save1()
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
void Operation_teacher::displaycourse()
{
    for (int i = 0; i < c.size(); i++)
    {
        cout << "----------------------------------------------------------------------------------------------" << endl;
        cout << c[i] << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;
    }
}
void Operation_teacher::xuanze()
{

    int a;
    while (1)
    {
        system("cls");
        t.kebiaodisplay();
        cout << "###################################################################" << endl;
        cout << "   0:                               退出" << endl;
        cout << "   1:                               选课" << endl;
        cout << "   2:                               退课" << endl;
        cout << "   3:                               学生选课结果及成绩排名" << endl;
        cout << "   4:                               填写成绩" << endl;
        cout << "   5:                               个人选课情况" << endl;
        cout << "###################################################################" << endl;
        cin >> a;
        if (a == 0) break;
        else if (a == 1) addc();
        else if (a == 2) erasec();
        else if (a == 3)
        {
            string aa, b;
            while (1)
            {
                system("cls");
                cout << "请输入课程号和教学班号,输入-1退出" << endl;
                cin >> aa;
                if (aa == "-1") { break; }
                cin >> b;
                if (t.chakecheng(aa, b) == -1) { cout << "输入有误，请重新输入" << endl; system("pause"); }//判断输入的课程以及班号是否有误
                else t.displaystudent(aa, b);

            }
        }
        else if (a == 4)
        {
            string aa, b; int z;
            while (1)
            {
                system("cls");
                cout << "请输入要填写成绩的课程号和教学班号,输入-1退出" << endl;
                cin >> aa;
                if (aa == "-1") break;
                cin >> b;
                if (t.chakecheng(aa, b) == -1) cout << "输入有误，请重新输入" << endl;
                //ma1=ma.find(aa);if(ma1==ma.end()||c[ma[aa]].getbanhao()!=b) {cout<<"输入有误，请重新输入"<<endl;system("pause");system("cls");}
                else
                {
                    while (1)
                    {
                        cout << "输入平时成绩按1，输入考试成绩按2，退出按-1" << endl;
                        cin >> z;
                        if (z == -1) break;
                        else if (z == 1)
                            pschengji(aa, b);
                        else if (z == 2) kschengji(aa, b);
                    }
                }
                system("pause");
            }
        }
        else if (a == 5) { system("cls"); cout << t << endl; system("pause"); }
    }
}
void Operation_teacher::addc()
{
    string z, hao;
    int i, j, l, tt = 0;
    while (1)
    {
        system("cls");
        displaycourse(); cout << t << endl;
        cout << "请输入所选课程的课程号、班号,输入-1结束" << endl;
        cin >> z;
        if (z == "-1") break;
        else {
            cin >> hao;
            if (t.chakechengm(z) != -1) { cout << "已选过此门课程" << endl; system("pause"); }
            else {
                for (j = 0; j < c.size(); j++)
                    if (c[j].getno() == z && c[j].getbanhao() == hao) { break; }
                if (j != c.size())
                {
                    if (c[j].getteacher() != "-1") cout << "已有教师选了此门课程,请重新选课" << endl;
                    else {
                        for (i = 0; i < c[j].getn(); i++)
                        {
                            l = c[j].gettime(i);
                            if (t.chake(c[j].gettime(i))) { cout << "时间冲突" << endl; tt = 1; break; }
                        }
                        if (tt == 0) {
                            //c[j].addstudent(s.getnumber());
                            cout << "选课成功" << endl;
                            c[j].setteacher(t.getname()); t.add(c[j]); cout << c[j] << endl;
                        }
                    }
                    system("pause");
                }
                else {
                    cout << "输入有误,请重新输入，输入-1结束" << endl; system("pause");
                }
            }
        }
    }
}
void Operation_teacher::erasec()
{
    string z;
    while (1)
    {
        system("cls");
        cout << t << endl;
        cout << "请输入所退课程的课程号,输入-1结束" << endl;
        cin >> z;
        if (z == "-1") break;
        else
        {
            ma1 = ma.find(z);
            if (ma1 != ma.end())
            {
                c[ma1->second].setteacher("-1");
                t.erasee(z);
                //ma.erase(ma1);
                //cout<<"已退选此课程"<<endl;
                system("pause");
            }
            else {
                cout << "课程号输入有误，请重新输入,输入-1结束" << endl; system("pause");
            }
        }
    }
}
void Operation_teacher::load1()
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



void Operation_student::save1()
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
        outfile << c[i].sssn() << endl;//cout<<c[i].sssn()<<endl;system("pause");
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
void Operation_student::displaycourse()
{
    for (int i = 0; i < c.size(); i++)
    {
        cout << "----------------------------------------------------------------------------------------------" << endl;
        cout << c[i] << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl << endl;
    }
}
void Operation_student::xuanze()
{
    int a;
    while (1)
    {
        system("cls");
        s.kebiaodisplay();
        cout << "###################################################################" << endl;
        cout << "   0:                               退出" << endl;
        cout << "   1:                               选课" << endl;
        cout << "   2:                               退课" << endl;
        cout << "   3:                               考试成绩" << endl;
        cout << "   4:                               选课情况" << endl;
        cout << "###################################################################" << endl;
        cin >> a;
        if (a == 0) break;
        else if (a == 1) addc();
        else if (a == 2) erasec();
        else if (a == 3) s.displayall();
        else if (a == 4) { system("cls"); cout << s << endl; system("pause"); }
    }
}
void Operation_student::load1()
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
void Operation_student::addc()
{
    string z, hao;
    int i, j, t = 0;
    while (1)
    {
        system("cls");
        load1();
        displaycourse();
        cout << s << endl; int l;
        cout << "请输入所选课程的课程号、班号,输入-1结束" << endl;
        cin >> z;//输入课程代号
        if (z == "-1") break;
        else
        {
            cin >> hao;//输入班号
            if (s.chakecheng(z) != -1) { cout << "此门课程已选过" << endl; system("pause"); }
            else
            {
                system("cls");
                for (i = 0; i < c.size(); i++)
                    if (c[i].getno() == z && c[i].getbanhao() == hao) { cout << c[i] << endl; break; }
                if (i != c.size()) {
                    if (c[i].sssn() == c[i].getnumber()) cout << "此门课程已满,请重新选择" << endl;
                    else {
                        for (j = 0; j < c[i].getn(); j++)
                        {
                            l = c[i].gettime(j);
                            if (s.chake(c[i].gettime(j))) { cout << "时间冲突" << endl; t = 1; break; }
                        }
                        if (t == 0) {
                            c[i].addstudent(s.getnumber(), s.getname(), s.getclas(), 0, 0);//;
                            cout << "已选此课程" << endl;
                            s.add(c[i]); save1();//c[i].displaystudent();system("pause");
                        }
                    }system("pause");
                }
                else {
                    cout << "课程号输入有误,请重新输入，输入-1结束" << endl; system("pause");
                }
            }
        }
    }
}
void Operation_student::erasec()
{
    string z;
    while (1)
    {
        system("cls");
        cout << s << endl;
        cout << "请输入所退课程的课程号,输入-1结束" << endl;
        cin >> z;
        if (z == "-1") break;
        else
        {
            ma1 = ma.find(z);
            if (ma1 != ma.end())
            {//cout<<"!"<<endl;
                c[ma1->second].erasestudent(s.getnumber());
                s.erasee(z);
                //ma.erase(ma1);
                //cout<<"已退选此门课程"<<endl;
                save1();
                system("pause");
            }
            else {
                cout << "课程号输入有误，请重新输入,输入-1结束" << endl; system("pause");
            }
        }
    }
}