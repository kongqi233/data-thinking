#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ExternFile.h"

AccountData::AccountData(string path){
    ifstream in;
    in.open(path, ios::in);
    if(in.is_open()){
        string s;
        getline(in,s);
        cout<<stoi(s)<<endl;
        for(long long i=0;i<stoi(s);i++){
            getline(in,s);
            string word;
            istringstream sin;
            sin.clear();
            sin.str(s);
            getline(sin,word,',');
            accounts[i].SID=word;
            getline(sin,word,',');
            accounts[i].name=word;
            getline(sin,word,',');
            accounts[i].sex=Sex(stoi(word));
            getline(sin,word,',');
            accounts[i].telephone=word;
            getline(sin,word,',');
            for(int j=0;j<4;j++){
                accounts[i].cardID[j]=stoi(word.substr(j*4,4));
            }
            getline(sin,word,',');
            accounts[i].IDnumber=word;
            getline(sin,word,',');
            accounts[i].password=word;
            getline(sin,word,',');
            accounts[i].balance=stod(word);
            accounts[i].year=accounts[i].month=accounts[i].day=accounts[i].hour=accounts[i].minute=accounts[i].second=0;
            accounts[i].xyear=accounts[i].xmonth=accounts[i].xday=accounts[i].xhour=accounts[i].xminute=accounts[i].xsecond=0;
        }   
    }
    in.close();
}

AccountData::~AccountData(){
    ofstream out;
    out.open(ACCOUNT_PATH, ios::out | ios::trunc);
    out<<accounts.size()<<endl;
    for(int i=0;i<accounts.size();i++){
        out<<accounts[i].SID<<","<<accounts[i].name<<","<<accounts[i].sex<<","<<accounts[i].telephone<<",";
        out<<to_string(accounts[i].cardID[0])+to_string(accounts[i].cardID[1])+to_string(accounts[i].cardID[2])+to_string(accounts[i].cardID[3])<<",";
        out<<accounts[i].IDnumber<<","<<accounts[i].password<<","<<accounts[i].balance<<endl;
        
    }
    out.close();
}