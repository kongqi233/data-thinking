#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>0
#include "ExternFile.h"
using namespace std;
void createAcc(string,int n);
int main(){
    //Login(acc,tr);
    createAcc(ACCOUNT_PATH,1000);
    return 0;
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
        out<<a.tag<<endl;
    }
    out.close();
}
