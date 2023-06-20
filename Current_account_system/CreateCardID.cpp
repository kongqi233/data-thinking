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
    account.cardID="";
    for(auto &i:account.telephone) temp+=(i-'0');
    temp%=100;
    account.cardID+=to_string(6200+temp);//头四位62+手机号各位加和%100
    for(int i=6;i<10;++i){
        t[i-6]=char(((account.IDnumber[i]-'0')+i)%10+'0');
    }
    swap(t[0],t[3]);//年份+身份证中位置 %10 首尾交换
    for(auto c:t)
        account.cardID+=c;
    for(int i=10;i<14;++i){
        t[i-10]=char(((account.IDnumber[i]-'0')+i)%10+'0');
    }
    swap(t[1],t[3]);//日期+身份证中位置 %10 第2 4位交换
    for(auto c:t)
        account.cardID+=c;
    for(int i=0;i<3;++i){
        account.cardID+=ms%10+'0';
        ms/=10;
    }
    temp=0;
    for(int i=0;i<4;++i){
        int ttt;
        ttt=(account.cardID[i*4+0]-'0')*2;
        temp+=ttt/10;
        temp+=ttt%10;
        ttt=(account.cardID[i*4+2]-'0')*2;
        temp+=ttt/10;
        temp+=ttt%10;
    }
    account.cardID+=char('0'+temp%10);//ms(倒序)+校验位
    return OK;
}
