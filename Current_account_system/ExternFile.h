/*
*活期账户系统头文件
*/
#ifndef EXTERNFILE_H
#define EXTERNFILE_H

#include<bits/stdc++.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRADELOG_PATH "../CAsystem/tradeLog.csv"
#define ACCOUNT_PATH "../CAsystem/Account.csv"
using namespace std;
typedef int Status;
enum Sex{
    MALE,FEMALE
};
struct Account{
    string name;//名字
    Sex sex;//性别
    string telephone;//手机号
    short int cardID[4];//卡号
    string IDnumber;//身份证号
    string password;//密码
    double balance;//余额
    short int year,month,day,hour,minute,second;//时间
};

#endif
