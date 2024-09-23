
#ifndef STUDENT_A
#define STUDENT_A
#include<string>
struct Message//信息类
{
    std::string snumber;//学号工号
    std::string sname;//名字
    std::string sclas;//学院。班级
    float ps;//平时成绩
    float ks;//考试成绩
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