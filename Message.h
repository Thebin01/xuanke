
#ifndef STUDENT_A
#define STUDENT_A
#include<string>
struct Message//��Ϣ��
{
    std::string snumber;//ѧ�Ź���
    std::string sname;//����
    std::string sclas;//ѧԺ���༶
    float ps;//ƽʱ�ɼ�
    float ks;//���Գɼ�
};
#pragma region
#define ccc(a,b) \
do \
{ \
    return a.snumber < b.snumber;\
} \
while (0)

#pragma endregion

#endif