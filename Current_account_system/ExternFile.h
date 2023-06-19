/*
*活期账户系统头文件
*/
#ifndef EXTERNFILE_H
#define EXTERNFILE_H

#include<iostream>
#include "myVector.cpp"
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRADELOG_PATH "./CAsystem/tradeLog.csv"
#define ACCOUNT_PATH "./CAsystem/Account.csv"
#define NAME_MAX_SIZE 30
#define SID_SIZE 11
#define TELEPHONE_SIZE 11
#define IDNUMBER_SIZE 18
#define PASSWORD_SIZE 6
using namespace std;
typedef int Status;
enum Sex{
    NONE,MALE,FEMALE
};
struct Account{
    string SID;//系统内部标识,定长11位
    string name;//名字，限长30
    Sex sex=Sex::NONE;//性别
    string telephone;//手机号，定长11
    short int cardID[4];//卡号，定长16
    string IDnumber;//身份证号，定长18
    string password;//密码，定长6
    double balance;//余额
    short int year,month,day,hour,minute,second;//开户时间
    short int xyear,xmonth,xday,xhour,xminute,xsecond;//销户时间
};
Status Account_Balance(Account&);
Status Account_Opening(void);
Status Withdrawal(Account&);

class AccountData{
    myVector<Account> accounts;
    public:
    AccountData(string path=ACCOUNT_PATH);
    ~AccountData();
};

#endif
