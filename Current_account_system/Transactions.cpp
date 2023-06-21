/*
*交易信息
*/
#include<bits/stdc++.h>
#include "ExternFile.h"
using namespace std;
Status Transactions(Account& acc,TradeData& tr){
    //system("cls");
    cout<<"您的交易信息如下:"<<endl;
    string temp;
    TradeInfo info;
    cout<<"-------------------------------------"<<endl;
    for(int i=0;i<acc.tradeID.size();++i){
        temp=acc.tradeID[i];
        info=tr.find(temp);
        cout<<setw(16)<<"交易流水号:"<<info.tradeID<<endl;
        cout<<setw(16)<<"交易类型:"<<(info.type==TradeType::IN?"存款":(info.type==TradeType::OUT?"取款":(info.type==TradeType::TO?"转账(转出)":"转账(转入)")))<<endl;
        cout<<setw(16)<<"姓名:"<<info.name<<endl;
        cout<<setw(16)<<"卡号:"<<info.cardID<<endl;
        if(info.type==TradeType::FROM||info.type==TradeType::TO){
            cout<<setw(16)<<(info.type==TradeType::TO?"转入方姓名:":"转出方姓名:")<<info.othername<<endl;
            cout<<setw(16)<<(info.type==TradeType::TO?"转入方卡号:":"转出方卡号:")<<info.otherID<<endl;
        }
        cout<<setw(16)<<"交易金额:"<<info.money<<endl;
        cout<<setw(16)<<"交易时间:"<<info.year<<"-"<<setw(2)<<setfill('0')<<info.month<<"-"<<setw(2)<<setfill('0')<<info.day<<" "
            <<setw(2)<<setfill('0')<<info.hour<<":"<<setw(2)<<setfill('0')<<info.minute<<":"<<setw(2)<<setfill('0')<<info.second<<endl;
        cout<<setfill(' ')<<setw(16)<<"交易备注:"<<info.info<<endl;
        cout<<"-------------------------------------"<<endl;
    }
    return OK;
}
