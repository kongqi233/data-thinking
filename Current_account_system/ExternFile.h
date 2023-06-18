/*
*活期账户系统头文件
*/
#ifndef EXTERNFILE_H
#define EXTERNFILE_H
#define INTEREST_RATE 0.011//利率
enum Sex{
    MALE,FEMALE
};
typedef struct{
    string name;//名字，最大长度20
    Sex sex;//性别
    string telephone;//手机号，长度11
    short int cardID[4];//卡号，长度16
    string IDnumber;//身份证号，长度18
    string password;//密码，长度6
    double balance;//余额
    short int year,month,day,hour,minute,second;//时间
} Account;
typedef 
#endif
