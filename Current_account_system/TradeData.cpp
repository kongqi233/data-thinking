#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include "ExternFile.h"
using namespace std;
void TradeData::addTrade(const TradeInfo& info){
    trade.addlist(info);
    tradeNumber++;
    return;
}
TradeInfo* TradeData::find(const string& s){
    if(s.size()!=TRADEID_SIZE){
        cout<<"交易流水号格式错误!1"<<endl;
        return nullptr;
    }
    else{
        long long temp=0;
        int flag=0;
        for(int i=0;i<s.size();++i){
            if(s[i]<'0'||s[i]>'9'){
                cout<<"交易流水号格式错误!2"<<endl;
                flag=1;
                return nullptr;
            }
            temp=temp*10+s[i]-'0';
        }
        if(temp>tradeNumber){
            cout<<"交易流水号格式错误!3"<<endl;
            return nullptr;
        }
        else return &trade[temp-1];
    }
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
            info.type=(word=="1"?TradeType::IN:(word=="2"?TradeType::OUT:(word=="3"?TradeType::TO:TradeType::FROM)));
            getline(sin,word,',');
            info.name=word;
            getline(sin,word,',');
            info.cardID=word;
            getline(sin,word,',');
            info.othername=word;
            getline(sin,word,',');
            info.otherID=word;
            getline(sin,word,',');
            info.money=stod(word);
            getline(sin,word,',');
            info.year=stoi(word.substr(0,4));
            info.month=stoi(word.substr(4,2));
            info.day=stoi(word.substr(6,2));
            info.hour=stoi(word.substr(8,2));
            info.minute=stoi(word.substr(10,2));
            info.second=stoi(word.substr(12,2));
            getline(sin,word);
            info.info=word;
            trade.addlist(info);
        }
        tradeNumber=trade.size();
    }
    in.close();
}
TradeData::~TradeData(){
    ofstream out;
    out.open(TRADELOG_PATH,ios::out | ios::trunc);
    for(int i=0;i<tradeNumber;i++){
        out<<trade[i].tradeID<<","<<to_string(trade[i].type)<<","<<trade[i].name<<","<<trade[i].cardID<<","<<trade[i].othername<<","<<trade[i].otherID
        <<","<<trade[i].money<<","<<trade[i].year<<setw(2)<<setfill('0')<<trade[i].month<<setw(2)<<trade[i].day<<setw(2)
        <<trade[i].hour<<setw(2)<<trade[i].minute<<setw(2)<<trade[i].second<<","<<setfill(' ')<<trade[i].info<<endl;
    }
    out.close();
}
long long TradeData::getTrNumber(){
    return tradeNumber;
}
//TradeInfo& TradeData::test(){
//    return trade[tradeNumber-1];
//}
