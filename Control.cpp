#include "Control.h"
#include "Operation.h"
#include <fstream>  


Control::Control()
{     
    cout << "=====================================================\n\n\n\n\n" << endl;

    cout << "              ��ӭ����ѧ��ѡ��ϵͳ ��                      \n\n\n\n\n" << endl;

    cout << "=====================================================" << endl;
    system("pause");
    MainControl();
}

Control::~Control(){}

void Control::MainControl()
{
    int a;
   
    Manager s;
    Operation ll;
    //Account lo;
    while (1)
    {
        system("cls");
        cout << "��ӭ����ѡ��ϵͳ,��ѡ���Ž��в���" << endl;
        cout << "����Ա����1���û���½����0���˳�����-1" << endl;
        cin >> a;
        if (a == 1)
        {
            system("cls");
            cout<<"�������Աϵͳ" << endl;
            s.Login_manager();
            s.load1();
            s.load3();
            s.load2();
            //s.load3();
            s.menu1();
            s.save1();
            s.save2();
            s.save3();
        }
        else if (a == -1) break;
        else if (a == 0)
        {
            system("cls");
            cout << "�����û�ϵͳ" << endl;
            s.load1();
            s.load3();
            s.load2(); 
            string number;//���ε�¼���˺�
            number = s.Login();
            s.save1();
            s.save2();
            s.save3();
            ll.load1();
            ll.load3();
            ll.load2();
            //ll.load3();
            ll.menu1(number);
            //ll.menu1();
        }

    }
}