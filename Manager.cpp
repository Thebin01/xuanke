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
    cout << "ѧ��\t����\t�༶\tƽ��ѧ�ּ���\t\t ѡ������" << endl;
    os << d.number << "\t" << d.name << "\t" << d.clas << "\t\t" << d.getjidian() << "\t\t" << d.c.size() << endl;
    for (int i = 0; i < d.c.size(); i++)
    {
        os << d.c[i];
        cout << "�ɼ�:" << d.dankechengji(i) << endl << endl;
    }
    cout << "==============================================================================================" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl << endl;
    return os;
}
istream& operator>>(istream& is, Student& d)
{
    string a, b, c, x;
    cout << "��������ѧ��ѧ�š��������༶,��-1��������" << endl;
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
    cout << "�γ̴���\t�γ�����\t�γ�ѧ��\t��������\t��ѧ���\t�ο���ʦ" << endl;
    os << d.no << "\t\t" << d.name << "\t\t" << d.xuefen << "\t\t" << d.number << "\t\t" << d.banhao << "\t\t";
    if (d.Teacher == "-1") cout << "����" << endl;
    else cout << d.Teacher;
    cout << endl;
    cout << "�Ͽ�ʱ��\t�Ͽεص�" << endl;//Ӧ�����ļ�����γ���Ϣ����
    if (d.n == 0) cout << "����" << endl;
    for (i = 0; i < d.n; i++)
    {
        cout << "��";
        os << d.time[i] / 10;
        cout << "��";
        os << d.time[i] % 10;
        cout << "��";
        os << "\t" << d.where[i] << endl;
    }
    return os;
}
istream& operator>>(istream& is, Course& d)
{
    string a, b, c;
    float x;
    int z, i = 0, k = 0;
    cout << "����������γ̴��š��γ����ơ�ѧ�֡�����������ѧ��ţ�����-1����" << endl;
    is >> a;
    if (a == "-1") { d.setno("-1"); return is; }
    is >> b;
    is >> x;
    is >> z >> c;
    Course t(a, b, x, z, c);
    while (1)
    {
        cout << "�����Ͽ�ʱ�䡢�ص㣬����-1����" << endl;
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
    cout << "��ʦ����\t��ʦ����\t����Ժϵ\t���ڿγ�����" << endl;
    os << d.hao << "\t\t" << d.name << "\t\t" << d.yuanxi << "\t\t" << d.c.size() << endl;
    cout << "���ڿγ�:" << endl;
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
    cout << "���������ʦ���š���ʦ������Ժϵ������-1����" << endl;
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
        if (a != -1) cout << "�Ѵ��ڴ��ſγ�" << endl;
        else { c.push_back(z); cout << "�����" << endl; }
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
        if (searchstudent(z.getnumber()) != -1) cout << "�Ѵ��ڴ�ѧ��ѧ��" << endl;
        else { s.push_back(z); cout << "ѧ����ӳɹ�" << endl; }
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
        if (searchteacher(z.gethao()) != -1) cout << "�Ѵ��ڴ˹��Ž�ʦ" << endl;
        else { t.push_back(z); cout << "��ʦ��ӳɹ�" << endl; }
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
        cout << "��������γ̵Ŀγ̺źͽ�ѧ���,����-1����" << endl;
        cin >> name;
        if (name == "-1") break;
        cin >> a;
        k = searchcourse(name, a);
        if (k != -1) { cout << c[k] << endl; c[k].displaystudent(); }
        else cout << "�γ̺�������������������" << endl;
    }
}

void Manager::querystudent()
{
    int k;
    string name; system("cls");
    while (1)
    {
        cout << "��������ѧ����ѧ��,����-1����" << endl;
        cin >> name;
        if (name == "-1") break;
        k = searchstudent(name);
        if (k != -1) cout << s[k] << endl;
        else cout << "ѧ��������������������" << endl;
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
        cout << "���������ʦ�Ĺ���,����-1����" << endl;
        cin >> name;
        if (name == "-1") break;
        k = searchteacher(name);
        if (k != -1) cout << t[k] << endl;
        else cout << "����������������������" << endl;
    }
}
void Manager::deletecourse()
{
    int k;
    string na, hao; system("cls");
    while (1)
    {
        cout << "����Ҫɾ���Ŀγ̵Ŀγ̺źͰ��,����-1����" << endl;
        cin >> na;
        if (na == "-1") break;
        cin >> hao;
        k = searchcourse(na, hao);
        if (k != -1) c.erase(c.begin() + k);
        else cout << "�γ̺�������������������" << endl;
    }
}
void Manager::deletestudent()
{
    int k;
    string na; system("cls");
    while (1)
    {
        cout << "����Ҫɾ����ѧ����ѧ��,����-1����" << endl;
        cin >> na;
        if (na == "-1") break;
        k = searchstudent(na);
        if (k != -1) s.erase(s.begin() + k);
        else cout << "ѧ��������������������" << endl;
    }
}
void Manager::deleteteacher()
{
    int k;
    string na; system("cls");
    while (1)
    {
        cout << "����Ҫɾ���Ľ�ʦ�Ĺ���,����-1����" << endl;
        cin >> na;
        if (na == "-1") break;
        k = searchteacher(na);
        if (k != -1) t.erase(t.begin() + k);
        else cout << "����������������������" << endl;
    }
}
void Manager::chargecourse()
{
    int k;
    string na, hao;
    Course zz; system("cls");
    while (1)
    {
        cout << "����Ҫ�޸ĵĿγ̵Ŀγ̺źͰ��,����-1����" << endl;
        cin >> na >> hao;
        if (na == "-1") break;
        k = searchcourse(na, hao);
        if (k != -1)
        {
            cout << c[k] << endl;
            cin >> zz;
            c[k] = zz;
            cout << "�޸ĺ����Ϣ��" << endl;
            cout << c[k] << endl;
        }
        else cout << "�γ̺�������������������" << endl;
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
        cout << "����Ҫ�޸ĵ�ѧ����ѧ��,����-1����" << endl;
        cin >> na;
        if (na == "-1") break;
        k = searchstudent(na);
        if (k != -1)
        {
            cout << s[k] << endl;
            cin >> zz;
            s[k] = zz;
            cout << "�޸ĺ����Ϣ��" << endl;
            cout << s[k] << endl;
        }
        else cout << "ѧ��������������������" << endl;
    }paixvs();
}
void Manager::chargeteacher()
{
    int k;
    string na; system("cls");
    Teacher zz;
    while (1)
    {
        cout << "����Ҫ�޸ĵĽ�ʦ�Ĺ���,����-1����" << endl;
        cin >> na;
        if (na == "-1") break;
        k = searchteacher(na);
        if (k != -1)
        {
            cout << t[k] << endl;
            cin >> zz;
            t[k] = zz;
            cout << "�޸ĺ����Ϣ��" << endl;
            cout << t[k] << endl;
        }
        else cout << "����������������������" << endl;
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
            //cout<<"����"<<c[i].sssn()<<"��ѡ�˴˿�"<<endl;
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
void Manager::load1()//����γ�
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
void Manager::load2()//����ѧ��
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
void Manager::load3()//�����ʦ
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
void Manager::save1()//����γ�
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
void Manager::save2()//����ѧ��
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
void Manager::save3()//������ʦ
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
void Manager::menudisplay1()//������
{
    cout << "*******************************************" << endl;
    cout << "               �𾴵Ĺ���Ա              " << endl;
    cout << "             ��ӭʹ��ѡ��ϵͳ              " << endl;
    cout << " 0:              �˳�                      " << endl;
    cout << " 1:              �γ̹���                  " << endl;
    cout << " 2:              ѧ������                  " << endl;
    cout << " 3:              ��ʦ����                  " << endl;
    cout << "*******************************************" << endl;
    return;
}
void Manager::menudisplay2(int a)//�ӽ���
{
    cout << "*******************************************" << endl;

    if (a == 1)
    {
        cout << "            ��ӭʹ�ÿγ̹���ϵͳ           " << endl;
        cout << " 0:              �˳�                      " << endl;
        cout << " 1:              ���ӿγ�                  " << endl;
        cout << " 2:              ɾ���γ�                  " << endl;
        cout << " 3:              �޸Ŀγ�                  " << endl;
        cout << " 4:              ��ѯ�γ�                  " << endl;
        cout << " 5:              չʾ���пγ̼�ѡ�ν��    " << endl;
    }
    if (a == 2)
    {
        cout << "            ��ӭʹ��ѧ������ϵͳ           " << endl;
        cout << " 0:              �˳�                      " << endl;
        cout << " 1:              ����ѧ��                  " << endl;
        cout << " 2:              ɾ��ѧ��                  " << endl;
        cout << " 3:              �޸�ѧ��                  " << endl;
        cout << " 4:              ��ѯѧ��                  " << endl;
        cout << " 5:              չʾ����ѧ��              " << endl;
    }
    if (a == 3)
    {
        cout << "            ��ӭʹ�ý�ʦ����ϵͳ           " << endl;
        cout << " 0:              �˳�                      " << endl;
        cout << " 1:              ���ӽ�ʦ                  " << endl;
        cout << " 2:              ɾ����ʦ                  " << endl;
        cout << " 3:              �޸Ľ�ʦ                  " << endl;
        cout << " 4:              ��ѯ��ʦ                  " << endl;
        cout << " 5:              չʾ������ʦ              " << endl;
    }
    cout << "*******************************************" << endl;
}
void Manager::menu1()//�������Ա�׽���
{
    int x;
    while (1)
    {
        system("cls");
        menudisplay1();//�������
        cout << "���������ѡ��:" << endl;
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

    if (a == 1)//�γ̹���
    {
        while (1)
        {
            menudisplay2(a);
            cout << "���������ѡ��" << endl;
            cin >> x;
            if (!x) break;
            switch (x)
            {
                case 1:
                    addcourse();//���ӿγ�
                    break;
                case 2:
                    deletecourse();//ɾ���γ�
                    break;
                case 3:
                    chargecourse();//�޸Ŀγ�
                    break;
                case 4:
                    querycourse();//��ѯ�γ�
                    break;
                case 5:
                    displaycourse(1);//չʾ���пγ̼�ѡ�ν��
                    break;
            }
            system("pause");
            system("cls");
        }
    }
    if (a == 2)//ѧ������
    {
        while (1)
        {
            menudisplay2(a);
            cout << "���������ѡ��" << endl;
            cin >> x;
            if (!x) break;
            switch (x)
            {
            case 1:
                addstudent();//����ѧ��
                break;
            case 2:
                deletestudent();//ɾ��ѧ��
                break;
            case 3:
                chargestudent();//�޸�ѧ��
                break;
            case 4:
                querystudent();//��ѯѧ�� 
                break;
            case 5:
                displaystudent();//չʾ����ѧ��
                break;
            }
            system("pause");
            system("cls");
        }
    }
    if (a == 3)//��ʦ����
    {
        while (1)
        {
            menudisplay2(a);
            cout << "���������ѡ��" << endl;
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

/////��������
#define SIZE 100//����û�����
int stucnt = 0;//�������浱ǰ��ע���û���
Manager user[SIZE];//���������������ʵ����Ϊ�û����ݵ���תվ
string Manager::Login()
{
    
   

    do
    {
        int ssw;
        dengluflag = -1;//����flag
        cout << "1.ѧ����¼" << endl;
        cout << "2.��ʦ��¼" << endl;
        cout << "��ѡ��" << endl;
        cin >> ssw;
        switch (ssw)
        {
        case 1://ѧ����¼
            user[0].read_student();//����ѧ������
            return Login_student();
        case 2: 
            user[0].read_teacher();//�����ʦ����
            return Login_teacher();
        }

    } while (dengluflag < 0);//���û���ҵ��˺���һֱѭ��


}

void Manager::setzhanghao_student(string _zhanghao)			  //����ѧ���ʺ�
{
    zhanghao=_zhanghao;
    //cout << "����ɹ�" << endl;
    ofstream ofile;
    ofile.open("user_student.txt", ios::app); 
    ofile << zhanghao << endl; 
    ofile.close();
}

void Manager::setzhanghao_teacher(string _zhanghao)			  //���ý�ʦ�ʺ�
{
    zhanghao = _zhanghao;
    cout << "����ɹ�" << endl;
    ofstream ofile;
    ofile.open("user_teacher.txt", ios::app);
    ofile << zhanghao << endl;
    ofile.close();
}

void Manager::setmima_student(string _mima)                 //����������֤��
{
    mima=_mima;
    //cout << "���óɹ�" << endl;
    ofstream ofile;
    ofile.open("user_student.txt", ios::app);
    ofile << mima << endl;
    ofile.close();
}
void Manager::setmima_teacher(string _mima)                 //����������֤��
{
    mima = _mima;
    //cout << "���óɹ�" << endl;
    ofstream ofile;
    ofile.open("user_teacher.txt", ios::app);
    ofile << mima << endl;
    ofile.close();
}
void Manager::checkC()						 			//��ѯ����
{
    cout << "�˺ţ�\n" << zhanghao << endl;
    cout << "���룺\n" << mima << endl;

}


bool Manager::zhanghaopipei(string _zhanghao)          //�˺��Ƿ�ƥ��
{
    if (zhanghao ==_zhanghao)return true;
    else return false;
}
bool Manager::mimapipei(string _mima)              //��֤���Ƿ�ƥ��
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
        //cout << "�ļ���ʧ�ܣ�" << endl;
        return;
    }

    for (int i = 0; !ifile.eof(); i++)//eof()ָ�뵽��β�Ƿ���ֵΪ1��������ѭ�������Ѿ����ļ��������û���Ϣ����
    {
        ifile >> user[i].zhanghao;
        ifile >> user[i].mima;
        stucnt++;
    }
    stucnt--;
    ifile.close();//�رմ𿪵������ļ�
}
void Manager::read_teacher()
{
    ifstream ifile;
    ifile.open("user_teacher.txt", ios::in);

    stucnt = 0;

    if (!ifile.is_open())
    {
        //cout << "�ļ���ʧ�ܣ�" << endl;
        return;
    }

    for (int i = 0; !ifile.eof(); i++)//eof()ָ�뵽��β�Ƿ���ֵΪ1��������ѭ�������Ѿ����ļ��������û���Ϣ����
    {
        ifile >> user[i].zhanghao;
        ifile >> user[i].mima;
        stucnt++;
    }
    stucnt--;
    ifile.close();//�رմ𿪵������ļ�
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
        cout << "1.ע���˺�" << endl;
        cout << "2.��½�����˺�" << endl;
        cout << "����0�˳�" << endl;
        cin >> SW;
        switch (SW)
        {
        case 1:

            do
            {
                system("cls");
                cout << "������ע���˺ţ���ѧ�ţ�" << endl;
                cin >> temp;
                for (int i = 0; i < stucnt; i++)
                {
                    if (user[i].zhanghaopipei(temp) == true)
                    {
                        cout << "�˺��ظ�������������" << endl;
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
                cout << "�������½����" << endl;
                cin >> temp;
                cout << "��ȷ�ϲ��ٴ������½����" << endl;
                cin >> tempp;
                system("cls");
                if (temp  != tempp)
                    cout << "�����������벻��ͬ������������" << endl;
                else 
                    break;//����ͬ��������������
            }

            user[stucnt].setmima_student(temp);
            cout << "ע��ɹ�,ע����Ϣ����" << endl;
            //user[stucnt].read();
            user[stucnt].checkC();
            stucnt++;
            system("pause");


            cout << "�����˺���Ϊѧ�Ű�Ҫ������" << endl;

            system("pause");
            addstudent();

            break;

        case 2:
            user[stucnt].read_student();//����ע���
            system("cls");
            cout << "�������˺�" << endl;
            cin >> temp;
            for (int i = 0; i < stucnt; i++)
            {
                if (user[i].zhanghaopipei(temp) == true)
                {
                    while (1)
                    {
                        cout << "�������½����" << endl;
                        cin >> temp1;
                        if (user[i].mimapipei(temp1) == true)
                        {
                            cout << "��½�ɹ�" << endl;
                            dengluflag = i;//û���ҵ��˺žͻᱣ�ֳ�ʼֵ-1
                            flag = 1;
                            break;
                        }
                        else
                        {
                            cout << "��֤�����������" << endl;
                        }
                    }
                }
            }
            if (dengluflag < 0)cout << "�˺Ų�����,�����������˺�" << endl;
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
        //dengluflag = -1;//����flag
        int zhanghaoflag = -1;
        system("cls");
        cout << "1.ע���˺�" << endl;
        cout << "2.��½�����˺�" << endl;
        cout << "����0�˳�" << endl;
        cin >> SW;
        switch (SW)
        {
        case 1:

            do
            {
                system("cls");
                cout << "������ע���˺ţ������ţ�" << endl;
                cin >> temp;
                for (int i = 0; i < stucnt; i++)
                {
                    if (user[i].zhanghaopipei(temp) == true)
                    {
                        cout << "�˺��ظ�������������" << endl;
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
                cout << "�������½����" << endl;
                cin >> temp;
                cout << "��ȷ�ϲ��ٴ������½����" << endl;
                cin >> tempp;
                system("cls");
                if (temp!=tempp)
                    cout << "�����������벻��ͬ������������" << endl;
                else
                    break;//����ͬ��������������
            } while (1);

            user[stucnt].setmima_teacher(temp);
            cout << "ע��ɹ�,ע����Ϣ����" << endl;
            //user[stucnt].read();
            user[stucnt].checkC();
            stucnt++;
            system("pause");

            cout << "�����˺���Ϊ���Ű�Ҫ������" << endl;
            addteacher();

            break;

        case 2:
            user[stucnt].read_teacher();
            system("cls");
            cout << "�������˺�" << endl;
            cin >> temp;
            for (int i = 0; i < stucnt; i++)
            {
                if (user[i].zhanghaopipei(temp) == true)
                {
                    while (1)
                    {
                        cout << "�������½����" << endl;
                        cin >> temp1;
                        if (user[i].mimapipei(temp1) == true)
                        {
                            cout << "��½�ɹ�" << endl;
                            dengluflag = i;//û���ҵ��˺žͻᱣ�ֳ�ʼֵ-1
                            flag = 1;
                            break;
                        }
                        else
                        {
                            cout << "��֤�����������" << endl;
                        }
                    }
                }
            }
            if (dengluflag < 0)cout << "�˺Ų�����,�����������˺�" << endl;
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
        while (1)//����˺�
        {
            system("cls");
            cout << "���������Ĺ���Ա�˺�(8��8)" << endl;
            cin >> temp;
            if (strcmp("88888888", temp) == 0)
            {
                cout << "�������½����(һ��)" << endl;
                break;
            }
            else
            {
                cout << "�˺Ŵ���,����������" << endl;
            }
        }
        while (1)//�������
        {
            cin >> temp;
            if (strcmp("88888888", temp) == 0)
            {
                cout << "��½�ɹ���" << endl; cout << "��ӭ������" << endl; break;
            }
            else
            {
                cout << "�������,����������" << endl;
            }
        }
        break;
    }
}
