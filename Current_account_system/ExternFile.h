/*
*活期账户系统头文件
*/
#ifndef EXTERNFILE_H
#define EXTERNFILE_H
enum Sex{
    MALE,FEMALE
};
typedef struct{
    char* name;//名字
    Sex sex;//性别
    char* telephone;//手机号
    short int cardID[4];//卡号
    char* IDnumber;//身份证号
    char* password;//密码
    double balance;//余额
    short int year,month,day,hour,minute,second;//时间
} Account;
void p(void);
#endif
