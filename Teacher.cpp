#include"Teacher.h"
#include<algorithm>

bool cmp1(Course a, Course b)
{
    return a.getno() < b.getno();
}

void Teacher::paixv() 
{
    ma.clear();
    sort(c.begin(), c.end(), cmp1);
    number = c.size();
    for (int i = 0; i < number; i++)
        ma.insert(make_pair(c[i].getno(), i));
}
void Teacher::add(Course a)
{
    c.push_back(a);
    number = c.size();
    for (int i = 0; i < a.getn(); i++)
        kebiao[a.gettime(i) % 10][a.gettime(i) / 10] = a.getname();
    paixv();
}
void Teacher::erasee(string noo)
{
    ma1 = ma.find(noo); if (ma1 == ma.end()) { cout << "未选此课" << endl; return; }
    cout << c[ma1->second] << endl; cout << "退选成功" << endl;
    for (int i = 0; i < c[ma[noo]].getn(); i++)
        kebiao[c[ma[noo]].gettime(i) % 10][c[ma[noo]].gettime(i) / 10] = "--------";
    c.erase(c.begin() + ma1->second);
    ma.erase(ma1); number = c.size();
    paixv();

}
void Teacher::displaystudent(string a, string b)
{
    ma1 = ma.find(a);//寻找a并返回迭代器，即返回该课程代号若没有则返回end（）
    if (ma1 != ma.end() && c[ma[a]].getbanhao() == b)//如果返回的不是end即找到该课程，并且班号也对应相同则下一步
        c[ma[a]].displaystudent();//输出该课程所有信息（包括所选人数和成绩排名）
    else cout << "输入有误，请重新输入" << endl;
    system("pause");
}
void Teacher::kebiaodisplay()
{
    int i, j;
    cout << "         周一\t\t周二\t\t周三\t\t周四\t\t周五\t\t周六\t\t周日" << endl;
    for (i = 1; i <= 5; i++)
    {
        cout << "第" << i << "大节\t";
        for (j = 1; j <= 7; j++)
            cout << kebiao[i][j] << "\t";
        cout << endl;
    }
}

