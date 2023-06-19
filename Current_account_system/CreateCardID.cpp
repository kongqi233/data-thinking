/*
*创建卡号
*/
#include<iostream>
#include<time.h>
#include "ExternFile.h"
using namespace std;
Status CreateCardID(Account& account,short int ms){
    short int temp=0;
    char t[4],tt;
    for(int i=0;i<account.telephone.size();++i)
        temp+=(account.telephone[i]-'0');
    temp%=100;
    account.cardID[0]=6200+temp;//头四位62+手机号各位加和%100
    temp=0;
    for(int i=6;i<10;++i){
        t[i-6]=char(((account.IDnumber[i]-'0')+i)%10+'0');
    }
    tt=t[3];t[3]=t[0];t[0]=tt;
    for(int i=0;i<4;++i)
        temp=temp*10+t[i]-'0';
    account.cardID[1]=temp;//年份+身份证中位置 %10 首尾交换
    temp=0;
    for(int i=10;i<14;++i){
        t[i-6]=char(((account.IDnumber[i]-'0')+i)%10+'0');
    }
    tt=t[3];t[1]=t[3];t[1]=tt;
    for(int i=0;i<4;++i)
        temp=temp*10+t[i]-'0';
    account.cardID[2]=temp;//日期+身份证中位置 %10 第2 4位交换
    account.cardID[3]=ms*10;
    temp=0;
    for(int i=0;i<4;++i){
        int ttt;
        ttt=account.cardID[i]/1000*2;
        temp+=ttt/10;
        temp+=ttt%10;
        ttt=account.cardID[i]%10*2;
        temp+=ttt/10;
        temp+=ttt%10;
    }
    account.cardID[3]+=temp%10;//ms+校验位
    return OK;
}
