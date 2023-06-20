#include<iostream>
#include<fstream>
#include<sstream>
#include "ExternFile.h"
using namespace std;
void TradeData::addTrade(const TradeInfo& info){
    trade.addlist(info);
    tradeNumber++;
    return;
}
Status TradeData::find(const string& s,TradeInfo& info){
    if(s.size()!=TRADEID_SIZE) return ERROR;
    long long temp=0;
    for(int i=0;i<s.size();++i){
        if(s[i]<'0'&&s[i]>'9') return ERROR;
        temp=temp*10+s[i]-'0';
    }
    if(temp>tradeNumber) return ERROR;
    info=trade[temp-1];
    return OK;
}
TradeData::TradeData(string path){
    ifstream in;
    in.open(path,ios::in);
    if(!in.is_open()){
        cout<<"Error:Fail to open system file!"<<endl;
        exit(1);
    }
    else{
        string line;
        string word;
        istringstream sin;
        while(getline(in,line)){
            TradeInfo info;
            sin.clear();
            sin.str(line);
            getline(sin,word,',');
            info.tradeID=word;
            getline(sin,word,',');
            info.type=(word=="1"?TradeType::IN:(word=="2"?TradeType::OUT:TradeType::INTER));
            getline(sin,word,',');
            info.name=word;
            getline(sin,word,',');
            info.cardID=word;
            if(info.type==TradeType::INTER){
                getline(sin,word,',');
                info.othername=word;
                getline(sin,word,',');
                info.otherID=word;
            }
            getline(sin,word,',');
            info.money=stod(word);
            //
            trade.addlist(info);
        }
        tradeNumber=trade.size();
    }
}
