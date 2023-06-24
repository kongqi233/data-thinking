/*
*活期账户系统头文件
*/
#ifndef EXTERNFILE_H
#define EXTERNFILE_H

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include<iomanip>
#include "myVector.cpp"
#define OK 1
#define ERROR 0
#define EXIT -1
#define TRADELOG_PATH "../CAsystem/tradeLog.csv"
#define ACCOUNT_PATH "../CAsystem/Account.csv"
#define NAME_MAX_SIZE 30
#define SID_SIZE 11
#define TELEPHONE_SIZE 11
#define IDNUMBER_SIZE 18
#define PASSWORD_SIZE 6
#define TRADEID_SIZE 12
#define ADMIN "admin"
#define ADMIN_PASS "admin"
using namespace std;
typedef int Status;
enum Sex{
    NONE=0,MALE=1,FEMALE=2
};
struct Account{
    string SID;//系统内部标识,定长11位
    string name;//名字，限长30
    Sex sex=Sex::NONE;//性别
    string telephone;//手机号，定长11
    string cardID;//卡号，定长16
    string IDnumber;//身份证号，定长18
    string password;//密码，定长6
    double balance;//余额
    short int year,month,day,hour,minute,second;//开户时间
    short int xyear,xmonth,xday,xhour,xminute,xsecond;//销户时间
    bool tag;
    myVector<string> tradeID;
    friend ostream& operator<<(ostream& os,const Account& acc){
        os<<acc.SID<<"\t"<<acc.name<<"\t"<<acc.sex<<"\t"<<acc.telephone<<"\t"<<acc.cardID<<"\t"<<acc.IDnumber<<"\t"<<acc.password<<"\t";
        return os;
    }
};
enum TradeType{
    IN=1,OUT=2,TO=3,FROM=4
};
struct TradeInfo{
    string tradeID;//交易流水号,定长12
    TradeType type;//交易类型
    string name;//交易人姓名
    string cardID;//交易卡号
    string othername;//被转账人姓名
    string otherID;//被转账人卡号
    double money;//交易金额
    short int year,month,day,hour,minute,second;//交易时间
    string info="无";//交易备注
    friend ostream& operator<<(ostream& os,const TradeInfo& tr){
        os<<tr.tradeID<<"\t"<<tr.type<<"\t"<<tr.name<<"\t"<<tr.cardID<<"\t"<<tr.othername<<"\t"<<tr.otherID<<"\t"<<tr.money<<"\t"
        <<tr.year<<"-"<<setw(2)<<setfill('0')<<tr.month<<"-"<<setw(2)<<tr.day<<" "
        <<setw(2)<<tr.hour<<":"<<setw(2)<<tr.minute<<":"<<setw(2)<<tr.second<<setfill(' ')<<"\t"<<tr.info;
        return os;
    }
};
struct stoipair{
    string key;
    int value;
    stoipair(string key="",int value=0):key(key),value(value){};
};
class AccountData{
    myVector<Account> accounts;
    long long accountsNumber;
    long long closureNumber;
    public:
    myVector<stoipair> phone,cardID,IDnumber;
    template<typename U,typename T>
    static void sort(T& q,int l,int r,std::function<bool(U,U)> const &f);
    Account* find(const string& s,int n);
    void addAccount(const Account&);
    long long getAccNumber()const{return accountsNumber;}
    void setCloNumber(){closureNumber++;}
    long long getCloNumber(){return closureNumber;}
    const myVector<Account>& getAccounts()const{return accounts;}
    //Account& test();
    AccountData(string path=ACCOUNT_PATH);
    ~AccountData();
};
class TradeData{
    myVector<TradeInfo> trade;
    long long tradeNumber;
public:
    void addTrade(const TradeInfo&);
    TradeInfo* find(const string&);
    long long getTrNumber();
    const myVector<TradeInfo>& getTrades()const{return trade;}
    //TradeInfo& test();
    TradeData(string path=TRADELOG_PATH);
    ~TradeData();
};
Status Account_Balance(Account&);
Status Account_Opening(AccountData&);
Status Withdrawal(Account&,TradeData&);
Status CreateCardID(Account&,short int);
Status GetTime(short int[]);
Status AccountWrite(AccountData&,Account&);
Status Deposit(Account&,TradeData&);
Status CreateTradeInfo(TradeData&,Account&,Account&,TradeType,double,string ="无");
Status Transactions(Account& acc,TradeData& tr);
Status Account_Closure(Account&,AccountData&);
void Login(AccountData&,TradeData&);
Status Account_info(AccountData&);
Status Trade_AllInfo(TradeData&,AccountData&);

#endif
