#include<iostream>
#include "ExternFile.h"
using namespace std;
Status CreateTradeInfo(TradeData& tr,Account& acc1,Account& acc2,TradeType type,double money,string information){
    TradeInfo info,info2;
    long long len=tr.getTrNumber();
    len++;
    info.tradeID="000000000000";
    string temp=to_string(len);
    info.tradeID=info.tradeID.substr(0,(12-temp.size()))+temp;
    info.type=type;
    info.money=money;
    info.name=acc1.name;
    info.cardID=acc1.cardID;
    if(type==TradeType::TO){
        info.othername=acc2.name;
        info.otherID=acc2.cardID;
        len++;
        info2.tradeID="000000000000";
        temp=to_string(len);
        info.tradeID=info.tradeID.substr(0,(12-temp.size()))+temp;
        info2.type=TradeType::FROM;
        info2.name=acc2.name;
        info2.cardID=acc2.cardID;
        info2.money=money;
        info2.othername=acc1.name;
        info2.otherID=acc1.cardID;
    }
    short int t[6];
    GetTime(t);
    info.year=t[0];info.month=t[1];info.day=t[2];info.hour=t[3];info.minute=t[4];info.second=t[5];
    info.info=information;
    tr.addTrade(info);
    acc1.tradeID.addlist(info.tradeID);
    if(type==TradeType::TO){
        info2.year=t[0];info2.month=t[1];info2.day=t[2];info2.hour=t[3];info2.minute=t[4];info2.second=t[5];
        info2.info=information;
        tr.addTrade(info2);
        acc2.tradeID.addlist(info2.tradeID);
    }
    return OK;
}
