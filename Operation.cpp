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
        ttt = qquerystudent(a);//tt==-1���в���ѧ��//��ȡѧ���˺�
       

        if (ttt != -1)
        {
            cout << "ѧ��" << a << "��½�ɹ�" << endl; system("pause");
            Operation_student ss(s[ttt]);//�Ի�ȡ��ѧ���˺Ŵ���һ��ѧ��������
            s[ttt] = ss.A();//���ص���������Student������һ������
            save2();
            //save1();
        }
        else
        {
            ttt = qqueryteacher(a);
           // cout << a<<ttt; system("pause");
            if (ttt != -1) {
                cout << "��ʦ" << a << "��½�ɹ�" << endl; system("pause");
                Operation_teacher tt(t[ttt]);
                t[ttt] = tt.A();
                save3();
                //save1();
            }
            else {
                cout << "�û�������,����������" << endl;
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
            cout << "���Ӧ����ѧ��ƽʱ�ɼ�" << endl;
            cout << "ѧ��\t\t����\t\tƽʱ�ɼ�" << endl;
            for (int i = 0; i < c[j].sssn(); i++)
            {
                cout << c[j].getsssnumber(i) << "\t" << c[j].getsssname(i) << "\t\t";
                cin >> ji;
                cout << endl;
                c[j].tianjiaps(c[j].getsssnumber(i), ji);
                t.setpschengji(a, i, ji);
            }break;
        }
    if (j == c.size()) cout << "������������������" << endl; system("pause");

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
            cout << "���Ӧ����ѧ�����Գɼ�" << endl;
            cout << "ѧ��\t\t����\t\t���Գɼ�" << endl;
            for (int i = 0; i < c[j].sssn(); i++)
            {
                cout << c[j].getsssnumber(i) << "\t" << c[j].getsssname(i) << "\t\t";
                cin >> ji;
                cout << endl;
                c[j].tianjiaks(c[j].getsssnumber(i), ji);
                t.setkschengji(a, i, ji);
            }break;
        }
    if (j == c.size()) cout << "������������������" << endl; system("pause");
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
        cout << "   0:                               �˳�" << endl;
        cout << "   1:                               ѡ��" << endl;
        cout << "   2:                               �˿�" << endl;
        cout << "   3:                               ѧ��ѡ�ν�����ɼ�����" << endl;
        cout << "   4:                               ��д�ɼ�" << endl;
        cout << "   5:                               ����ѡ�����" << endl;
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
                cout << "������γ̺źͽ�ѧ���,����-1�˳�" << endl;
                cin >> aa;
                if (aa == "-1") { break; }
                cin >> b;
                if (t.chakecheng(aa, b) == -1) { cout << "������������������" << endl; system("pause"); }//�ж�����Ŀγ��Լ�����Ƿ�����
                else t.displaystudent(aa, b);

            }
        }
        else if (a == 4)
        {
            string aa, b; int z;
            while (1)
            {
                system("cls");
                cout << "������Ҫ��д�ɼ��Ŀγ̺źͽ�ѧ���,����-1�˳�" << endl;
                cin >> aa;
                if (aa == "-1") break;
                cin >> b;
                if (t.chakecheng(aa, b) == -1) cout << "������������������" << endl;
                //ma1=ma.find(aa);if(ma1==ma.end()||c[ma[aa]].getbanhao()!=b) {cout<<"������������������"<<endl;system("pause");system("cls");}
                else
                {
                    while (1)
                    {
                        cout << "����ƽʱ�ɼ���1�����뿼�Գɼ���2���˳���-1" << endl;
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
        cout << "��������ѡ�γ̵Ŀγ̺š����,����-1����" << endl;
        cin >> z;
        if (z == "-1") break;
        else {
            cin >> hao;
            if (t.chakechengm(z) != -1) { cout << "��ѡ�����ſγ�" << endl; system("pause"); }
            else {
                for (j = 0; j < c.size(); j++)
                    if (c[j].getno() == z && c[j].getbanhao() == hao) { break; }
                if (j != c.size())
                {
                    if (c[j].getteacher() != "-1") cout << "���н�ʦѡ�˴��ſγ�,������ѡ��" << endl;
                    else {
                        for (i = 0; i < c[j].getn(); i++)
                        {
                            l = c[j].gettime(i);
                            if (t.chake(c[j].gettime(i))) { cout << "ʱ���ͻ" << endl; tt = 1; break; }
                        }
                        if (tt == 0) {
                            //c[j].addstudent(s.getnumber());
                            cout << "ѡ�γɹ�" << endl;
                            c[j].setteacher(t.getname()); t.add(c[j]); cout << c[j] << endl;
                        }
                    }
                    system("pause");
                }
                else {
                    cout << "��������,���������룬����-1����" << endl; system("pause");
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
        cout << "���������˿γ̵Ŀγ̺�,����-1����" << endl;
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
                //cout<<"����ѡ�˿γ�"<<endl;
                system("pause");
            }
            else {
                cout << "�γ̺�������������������,����-1����" << endl; system("pause");
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
        cout << "   0:                               �˳�" << endl;
        cout << "   1:                               ѡ��" << endl;
        cout << "   2:                               �˿�" << endl;
        cout << "   3:                               ���Գɼ�" << endl;
        cout << "   4:                               ѡ�����" << endl;
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
        cout << "��������ѡ�γ̵Ŀγ̺š����,����-1����" << endl;
        cin >> z;//����γ̴���
        if (z == "-1") break;
        else
        {
            cin >> hao;//������
            if (s.chakecheng(z) != -1) { cout << "���ſγ���ѡ��" << endl; system("pause"); }
            else
            {
                system("cls");
                for (i = 0; i < c.size(); i++)
                    if (c[i].getno() == z && c[i].getbanhao() == hao) { cout << c[i] << endl; break; }
                if (i != c.size()) {
                    if (c[i].sssn() == c[i].getnumber()) cout << "���ſγ�����,������ѡ��" << endl;
                    else {
                        for (j = 0; j < c[i].getn(); j++)
                        {
                            l = c[i].gettime(j);
                            if (s.chake(c[i].gettime(j))) { cout << "ʱ���ͻ" << endl; t = 1; break; }
                        }
                        if (t == 0) {
                            c[i].addstudent(s.getnumber(), s.getname(), s.getclas(), 0, 0);//;
                            cout << "��ѡ�˿γ�" << endl;
                            s.add(c[i]); save1();//c[i].displaystudent();system("pause");
                        }
                    }system("pause");
                }
                else {
                    cout << "�γ̺���������,���������룬����-1����" << endl; system("pause");
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
        cout << "���������˿γ̵Ŀγ̺�,����-1����" << endl;
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
                //cout<<"����ѡ���ſγ�"<<endl;
                save1();
                system("pause");
            }
            else {
                cout << "�γ̺�������������������,����-1����" << endl; system("pause");
            }
        }
    }
}