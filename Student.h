
/////////////////////////ѧ����//////////////////////////////////////
#ifndef STUDENT_Z
#define STUDENT_Z
#include"Course.h"
#include<map>
#include<vector>
#include <string>
class Student {
    std::vector<Course>c;//�洢ѧ��ѡ�Ŀ�
    std::vector<Course>::iterator it;//����һ��ָ�뷽�����
    std::map<std::string, int>ma;
    std::map<std::string, int>::iterator ma1;
    Course z;
    std::string name, number, clas;//������ѧ�š��༶
    int n;//��ѡ�γ��ܺ�
    float average, jidian, zong;//ƽ���ɼ������㣬�ܳɼ�
    float s;//�γ̼����ܺ�

    std::string kebiao[6][8];//�α�
    float all;//�ѻ�ȡ��ѧ��
public:
    Student(std::string num, std::string na, std::string cla) :number(num), name(na), clas(cla)//��������ѧ��ѧ�š��������༶����һ��ѧ��
    {
        for (int i = 0; i <= 5; i++)
            for (int j = 0; j <= 7; j++)
                kebiao[i][j] = "--------";
    }
    Student() {
        name = "-1"; number = "-1"; clas = "-1";
    }
    std::string getnumber() { return number; }//��ȡѧ��
    void setnumber(std::string m) { number = m; }//����ѧ��
    std::string getname() { return name; }//��ȡ����
    void setname(std::string m) { name = m; }//��������
    std::string getclas() { return clas; }//��ȡ�༶
    void setclas(std::string m) { clas = m; }//���ð༶
    int getn() { return c.size(); }//��ȡѧ���ĸ���
    void setn(int a) { n = a; }//����ѧ��ѡ�������ܺ�
    float getxuefen() { return all; }//��ȡ��ѧ���Ѿ���ȡ��ѧ��
    float getjidian() { return jidian; }//��ȡ��ѧ���ļ���
    void setjidian(float a) { jidian = a; }//���ü���
    float getaverage() { return average; }//��ȡƽ���ɼ�
    void NEW();//��ƽ���ɼ��ͼ�����и���
    void add(Course a);//����ѧ��ѡ��һ���γ�
    void erasee(std::string noo);//�˳�ѧ��ѡ��һ�ſγ�
    float dankechengji(int i) { return c[i].getichengji(number); }//��ȡ��ѧ������һ�ſ��еĳɼ�
    void paixv();//���ݿγ̴����ѧ������
    void kebiaodisplay();//��ʾ�α�
    void displayalll();//���뼨�㣬������ڼ�Ȩ�ֳܷ�����ѧ�֣���Ȩ�ֵܷ��ڸÿƳɼ�����10���̼�ȥ5�Ĳ���Ըÿ�ѧ��
    int chake(int a) { if (kebiao[a % 10][a / 10] != "--------") return 1; else return 0; }//�жϿα��Ӧλ���Ƿ�Ϊ��
    int chakecheng(std::string a) { ma1 = ma.find(a); if (ma1 != ma.end()) return ma[a]; else return -1; }//�жϸ����Ƿ�ѡ��˿�
    std::string courseno(int k) { return c[k].getno(); }//��ȡ����ѡ��ĵڼ����γ̵Ĵ���
    std::string coursehao(int j) { return c[j].getbanhao(); }//��ȡ����ѡ��ĵڼ����γ̵İ��
    friend std::ostream& operator<<(std::ostream& os, Student& d);//��ʾ����������Ϣ
    friend std::istream& operator>>(std::istream& is, Student& d);//������Ϣʵ����һ��ѧ���ࣨ����һ��ѧ����
    void displayall();//��ʾ��������һ�ſγ��е����гɼ�
};
#endif