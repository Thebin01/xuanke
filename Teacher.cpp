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
    ma1 = ma.find(noo); if (ma1 == ma.end()) { cout << "δѡ�˿�" << endl; return; }
    cout << c[ma1->second] << endl; cout << "��ѡ�ɹ�" << endl;
    for (int i = 0; i < c[ma[noo]].getn(); i++)
        kebiao[c[ma[noo]].gettime(i) % 10][c[ma[noo]].gettime(i) / 10] = "--------";
    c.erase(c.begin() + ma1->second);
    ma.erase(ma1); number = c.size();
    paixv();

}
void Teacher::displaystudent(string a, string b)
{
    ma1 = ma.find(a);//Ѱ��a�����ص������������ظÿγ̴�����û���򷵻�end����
    if (ma1 != ma.end() && c[ma[a]].getbanhao() == b)//������صĲ���end���ҵ��ÿγ̣����Ұ��Ҳ��Ӧ��ͬ����һ��
        c[ma[a]].displaystudent();//����ÿγ�������Ϣ��������ѡ�����ͳɼ�������
    else cout << "������������������" << endl;
    system("pause");
}
void Teacher::kebiaodisplay()
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

