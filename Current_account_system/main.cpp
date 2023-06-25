#include<iostream>
#include<iomanip>
#include<time.h>
#include<fstream>
#include "ExternFile.h"
using namespace std;
void createAcc(string,int );
void createTrade(string,AccountData&,int,int);
AccountData acc;
//TradeData tr;
int main(){
    //ofstream out;
    //out.open(TRADELOG_PATH,ios::out|ios::trunc);
    //out.close();
    //Login(acc,tr);
    //createAcc(ACCOUNT_PATH,1000);
    createTrade(TRADELOG_PATH,acc,1000,10000);
    return 0;
}
void createTrade(string path,AccountData& acc,int n,int m){
    ofstream out;
    out.open(path,ios::out|ios::trunc);
    srand(time(nullptr));
    for(int i=1;i<=m;++i){
        TradeInfo info;
        info.tradeID="000000000000";
        string temp=to_string(i);
        info.tradeID=info.tradeID.substr(0,(12-temp.size()))+temp;
        out<<info.tradeID<<",";
        int type=rand()%3+1;
        info.type=(type==1?TradeType::IN:(type==2?TradeType::OUT:TradeType::TO));
        out<<info.type<<",";
        int t1=rand()%n;
        int t2=t1;
        if(info.type==TradeType::TO){
            while(t2==t1)
                t2=rand()%n+1;
        }
        info.name=acc.getAccounts()[t1].name;
        out<<info.name<<",";
        info.cardID=acc.getAccounts()[t1].cardID;
        out<<info.cardID<<",";
        if(info.type!=TradeType::TO){
            out<<",,";
        }
        else{
            info.othername=acc.getAccounts()[t2].name;
            out<<info.othername<<",";
            info.otherID=acc.getAccounts()[t2].cardID;
            out<<info.otherID<<",";
        }
        info.money=rand();
        out<<info.money<<",";
        info.year=rand()%23+2000;info.month=rand()%12+1;info.day=rand()%28+1;info.hour=rand()%24;info.minute=rand()%60;info.second=rand()%60;
        out<<info.year<<setw(2)<<setfill('0')<<info.month<<setw(2)<<info.day<<setw(2)<<info.hour<<setw(2)<<info.minute<<setw(2)<<info.second<<","<<setfill(' ');
        int tt=rand()%30+1;
        string in="";
        for(int j=1;j<=tt;++j)
            in+=char(rand()%26+'a');
        info.info=(rand()%2==0?"无":in);
        out<<info.info<<endl;
        acc.getAccounts()[t1].tradeID.addlist(info.tradeID);
        if(info.type==TradeType::TO){
            TradeInfo info2;
            info2.tradeID="000000000000";
            string temp=to_string(++i);
            info2.tradeID=info2.tradeID.substr(0,(12-temp.size()))+temp;
            info2.type=TradeType::FROM;
            info2.name=info.othername;
            info2.cardID=info.otherID;
            info2.othername=info.name;
            info2.otherID=info.cardID;
            info2.money=info.money;
            info2.info=info.info;
            info2.year=info.year;info2.month=info.month;info2.day=info.day;info2.hour=info.hour;info2.minute=info.minute;info2.second=info.second;
            out<<info2.tradeID<<","<<info2.type<<","<<info2.name<<","<<info2.cardID<<","<<info2.othername<<","<<info2.otherID<<","<<info2.money<<","
            <<info2.year<<setw(2)<<setfill('0')<<info2.month<<setw(2)<<info2.day<<setw(2)<<info2.hour<<setw(2)<<info2.minute<<setw(2)<<info2.second<<","<<setfill(' ')<<info2.info<<endl;
            acc.getAccounts()[t2].tradeID.addlist(info2.tradeID);
        }
    }
    out.close();
}
void createAcc(string path,int n){
    ofstream out;
    out.open(path,ios::out|ios::trunc);
    out<<n<<endl;
    srand(time(nullptr));
    for(int i=1;i<=n;++i){
        Account a;
        a.SID="00000000000";
        string temp=to_string(i);
        a.SID=a.SID.substr(0,(11-temp.size()))+temp;
        out<<a.SID<<",";
        int t=rand()%10+2;
        a.name="";
        for(int j=1;j<=t;++j)
            a.name+=char(rand()%26+'a');
        out<<a.name<<",";
        a.sex=(rand()%2==0?Sex::FEMALE:Sex::MALE);
        out<<a.sex<<",";
        a.telephone="1";
        for(int j=1;j<=10;++j)
            a.telephone+=char(rand()%10+'0');
        out<<a.telephone<<",";
        a.IDnumber="";
        for(int j=1;j<=6;++j)
            a.IDnumber+=char(rand()%10+'0');
        a.IDnumber+=to_string(rand()%100+1923);
        int time=rand()%12+1;
        if(time<10)
           a.IDnumber+="0";
        a.IDnumber+=to_string(time);
        time=rand()%28+1;
        if(time<10)
           a.IDnumber+="0";
        a.IDnumber+=to_string(time);
        for(int j=1;j<=4;++j)
            a.IDnumber+=char(rand()%10+'0');
        CreateCardID(a,rand()%1000);
        out<<a.cardID<<",";
        out<<a.IDnumber<<",";
        a.password="";
        for(int j=1;j<=6;++j)
            a.password+=char(rand()%10+'0');
        out<<a.password<<",";
        a.year=rand()%23+2000;a.month=rand()%12+1;a.day=rand()%28+1;a.hour=rand()%24;a.minute=rand()%60;a.second=rand()%60;
        a.xyear=a.xmonth=a.xday=a.xhour=a.xminute=a.xsecond=0;
        a.tag=rand()%2;
        if(a.tag){
            a.balance=0;
            a.xyear=rand()%23+2000;a.xmonth=rand()%12+1;a.xday=rand()%28+1;a.xhour=rand()%24;a.xminute=rand()%60;a.xsecond=rand()%60;
        }
        else
            a.balance=rand();
        out<<a.balance<<",";
        out<<a.year<<setw(2)<<setfill('0')<<a.month<<setw(2)<<a.day<<setw(2)<<a.hour<<setw(2)<<a.minute<<setw(2)<<a.second<<",";
        out<<setw(4)<<setfill('0')<<a.year<<setw(2)<<a.month<<setw(2)<<a.day<<setw(2)<<a.hour<<setw(2)<<a.minute<<setw(2)<<a.second<<","<<setfill(' ');
        out<<a.tag<<","<<endl;
    }
    out.close();
}
