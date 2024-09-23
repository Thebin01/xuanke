#include "Student.h"


#include<algorithm>
#include<iostream>
using namespace std;

bool cmp3(Course a, Course b)
{
  return a.getno() < b.getno();
}
bool cmps1(Student a, Student b)
{
    return a.getjidian() > b.getjidian();
}



void Student::displayalll()
{
    float zong = 0, xuefen = 0;
    int i, j;
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i].getchengji(number) < 60) cout << "0" << endl;
        else {
            cout << (c[i].getchengji(number) / 10 - 5) * c[i].getxuefen() << endl;
            zong += (c[i].getchengji(number) / 10 - 5) * c[i].getxuefen();
        }
        xuefen += c[i].getxuefen();
    }
    if (zong == 0) setjidian(0);
    else
        setjidian(zong / xuefen);
}
void Student::displayall()
{
    system("cls");
    float zong = 0, xuefen = 0;
    int i, j;
    cout << "�γ�����\t�γ̳ɼ�\t�γ�ѧ��\t�γ̼���" << endl;
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i].getname() << "\t" << c[i].getchengji(number) << "\t\t" << c[i].getxuefen() << "\t\t";
        if (c[i].getchengji(number) < 60) cout << "0" << endl;
        else {
            cout << (c[i].getchengji(number) / 10 - 5) * c[i].getxuefen() << endl;//����γ̼���,�ÿƳɼ�����10���̼�ȥ5�Ĳ���Ըÿ�ѧ��
            zong += (c[i].getchengji(number) / 10 - 5) * c[i].getxuefen();
        }
        xuefen += c[i].getxuefen();
    }
    if (zong == 0) setjidian(0);
    else
        setjidian(zong / xuefen);//����Ϊ�ÿ��ֳܷ���ѧ��
    cout << "ƽ��ѧ�ּ���:\t" << getjidian() << endl; system("pause");
}


void Student::kebiaodisplay()
{
    int i, j;
    cout << "         ��һ\t\t�ܶ�\t\t����\t\t����\t\t����\t\t����\t\t����" << endl;
    for (i = 1; i <= 5; i++)
    {
        cout << "��" << i << "���\t";
        for (j = 1; j <= 7; j++)
            cout << kebiao[i][j] << "\t";
        cout << endl;
    }
}
void Student::paixv()
{
    ma.clear();//ɾ��map����ma������Ԫ��
    sort(c.begin(), c.end(), cmp3);
    n = c.size();
    for (int i = 0; i < n; i++)
        ma.insert(make_pair(c[i].getno(), i));//���γ̴���������0123...��map����ma�д洢��ֵ��
}
void Student::NEW()
{
    average = zong / n;
    jidian = s / all;
}
void Student::add(Course a)
{
    c.push_back(a);
    ma.insert(make_pair(a.getno(), c.size() - 1));
    all += a.getxuefen();
    n = c.size();
    for (int i = 0; i < a.getn(); i++)
        kebiao[a.gettime(i) % 10][a.gettime(i) / 10] = a.getname();
    paixv();
}
void Student::erasee(string noo)
{
    ma1 = ma.find(noo); if (ma1 == ma.end()) { cout << "δѡ�˿�" << endl; return; }

    cout << c[ma[noo]] << endl; cout << "��ѡ�ɹ�" << endl;

    for (int i = 0; i < c[ma[noo]].getn(); i++)
        kebiao[c[ma[noo]].gettime(i) % 10][c[ma[noo]].gettime(i) / 10] = "--------";
    c.erase(c.begin() + ma[noo]);
    ma.erase(ma1); n = c.size();
    paixv();
}


