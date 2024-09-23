
//////////////////////////////�γ���//////////////////////////////////////
#ifndef STUDENT_H
#define STUDENT_H
#include <map>
#include <vector>

#include "Message.h"
//#include <iostream>
//using namespace std;

class Course//����γ���Ϣ
{
    std::vector<Message>sss;
    std::map<std::string, int>ss;//ѧ����λ��
    std::map<std::string, int>::iterator ss1;
    std::string  no, name, banhao, Teacher, where[5];//�γ̴��š��γ����ơ���ѧ��ţ��ο���ʦ���Ͽεص�
    int number, time[5], n;//���������Ͽ�ʱ�䣬�Ͽδ���
    float xuefen, chengji;//ѧ�֣��ɼ�
public:
    Course(std::string n, std::string na, float fen, int x, std::string z) : no(n), name(na), xuefen(fen), number(x), banhao(z) { chengji = 0; Teacher = "-1"; }//�γ̴��š��γ����ơ�ѧ�֡�����������ѧ���
    Course() {
        name = "-1"; no = "-1"; banhao = "-1"; Teacher = "-1";
        xuefen = 0; number = 0; chengji = 0; //�޲ι�������Ĭ��ֵ
    }
    std::string getno() { return no; }//��ȡ�γ̴���
    void setno(std::string n) { no = n; }//���ÿγ̴���
    std::string getbanhao() { return banhao; }//��ȡ���
    void setbanhao(std::string n) { banhao = n; }//���ð��
    std::string getname() { return name; }//��ȡ�γ���
    void setname(std::string n) { name = n; }//���Ŀγ���
    std::string getteacher() { return Teacher; }//��ȡ�ο���ʦ
    std::string getsssnumber(int a) { return sss[a].snumber; }//��ȡ����ѧ��ѧ��
    std::string getsssname(int a) { return sss[a].sname; }//��ȡ����ѧ������
    std::string getsssclas(int a) { return sss[a].sclas; }//��ȡ����ѧ�����
    float getsssps(int a) { return sss[a].ps; }//��ȡƽʱ�ɼ�             
    float getsssks(int a) { return sss[a].ks; }//��ȡ���Գɼ�
    void displaystudent();//��ʾ���ſγ̵�����ѧ����Ϣ
    int sssn() { return sss.size(); }//��ȡ���ſε�ѡ������
    void addstudent(std::string a, std::string b, std::string c, float x, float y);//�����ſ�������һ��ѧ��
    void erasestudent(std::string a);//�����ſ���ɾ�����ѧ��ѧ�ŵ�ѧ��
    void setteacher(std::string n) { Teacher = n; }//�����ο���ʦ�ı��
    float getxuefen() { return xuefen; }//��ȡѧ��
    void setxuefen(float n) { xuefen = n; }//����ѧ��
    int getnumber() { return number; }//��ȡ������
    void setnumber(int n) { number = n; }//���ÿ�����
    float getichengji(std::string a) { return sss[ss[a]].ps * 0.3 + sss[ss[a]].ks * 0.7; }//��ѧ�Ż�ȡ�ɼ���ƽʱ�ɼ������Գɼ�=3��7
    int getn() { return n; }//��ȡ�Ͽδ���
    void paixv();//����map������ͬ��vector�����仯
    void tianjiaps(std::string a, float b) { sss[ss[a]].ps = b; }//����ѧ�ź�ƽʱ�ɼ����������ƽʱ�ɼ�
    void tianjiaks(std::string a, float b) { sss[ss[a]].ks = b; }//����ѧ�źͿ��Գɼ���������ÿ��Գɼ�
    float getps(std::string a) { ss1 = ss.find(a); if (ss1 != ss.end()) return sss[ss[a]].ps; else return -1; }
    float getks(std::string a) { ss1 = ss.find(a); if (ss1 != ss.end()) return sss[ss[a]].ks; else return -1; }
    float getchengji(std::string a) { ss1 = ss.find(a); if (ss1 != ss.end()) return sss[ss[a]].ps * 0.3 + sss[ss[a]].ks * 0.7; else return -1; }//��ȡ�������ųɼ���ƽʱ�ɼ������Գɼ�=3��7
    int gettime(int a) { return time[a]; }//��ȡ�Ͽε�ʱ��
    std::string getwhere(int a) { return where[a]; }//��ȡ�Ͽεص�
    void chengjipaixu();//���ݳɼ��Ըÿγ��ڵ�ѧ����������
    friend std::ostream& operator<<(std::ostream& os, Course& d);//��ʾ���ſε�������Ϣ
    friend std::istream& operator>>(std::istream& is, Course& d);//�������ſε���Ϣ������һ�ſ�
   
};
#endif