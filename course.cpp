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
    cout << "����" << sss.size() << "��ѡ�˴��ſγ�" << endl;
    if (sss.size() == 0) return;
    cout << "ѡ��ѧ����Ϣ��" << endl;
    cout << "ѧ��ѧ��\tѧ������\t�����༶\tƽʱ�ɼ�\t���Գɼ�\t�ۺϳɼ�" << endl;
    chengjipaixu();
    for (i = 0; i < sss.size(); i++)
    {
        cout << sss[i].snumber << "\t\t" << sss[i].sname << "\t\t" << sss[i].sclas << "\t\t" << sss[i].ps << "\t\t" << sss[i].ks << "\t\t";
        cout << sss[i].ps * 0.3 + sss[i].ks * 0.7 << endl;//�����ۺϳɼ�
    }
    cout << endl;
}