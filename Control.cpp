#include "Control.h"
#include "Operation.h"
#include <fstream>  


Control::Control()
{     
    cout << "=====================================================\n\n\n\n\n" << endl;

    cout << "              欢迎来到学生选课系统 ！                      \n\n\n\n\n" << endl;

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
        cout << "欢迎来到选课系统,请选择编号进行操作" << endl;
        cout << "管理员输入1，用户登陆输入0，退出输入-1" << endl;
        cin >> a;
        if (a == 1)
        {
            system("cls");
            cout<<"进入管理员系统" << endl;
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
            cout << "进入用户系统" << endl;
            s.load1();
            s.load3();
            s.load2(); 
            string number;//本次登录的账号
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