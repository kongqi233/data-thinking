/*
*创建卡号
*/
#include<iostream>
#include <string>
#include<time.h>
#include "ExternFile.h"
using namespace std;
Status CreateCardID(Account& account,short int ms){
    short int temp=0;
    char t[4];
    for(auto &i:account.telephone) temp+=(i-'0');
    temp%=100;
    account.cardID.replace(0,4,to_string(6200+temp));//头四位62+手机号各位加和%100
    for(int i=6;i<10;++i){
        t[i-6]=char(((account.IDnumber[i]-'0')+i)%10+'0');
    }
    swap(t[0],t[3]);
    account.cardID.replace(4,4,t);//年份+身份证中位置 %10 首尾交换
    for(int i=10;i<14;++i){
        t[i-6]=char(((account.IDnumber[i]-'0')+i)%10+'0');
    }
    swap(t[1],t[3]);
    account.cardID.replace(8,4,t);//日期+身份证中位置 %10 第2 4位交换
    account.cardID.replace(12,4,to_string(ms*10));
    temp=0;
    for(int i=0;i<4;++i){
        int ttt;
        ttt=stoi(account.cardID.substr(i*4,4))/1000*2;
        temp+=ttt/10;
        temp+=ttt%10;
        ttt=stoi(account.cardID.substr(i*4,4))%10*2;
        temp+=ttt/10;
        temp+=ttt%10;
    }
    account.cardID[15]='0'+temp%10;//ms+校验位
    return OK;
}
