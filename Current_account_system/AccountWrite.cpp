#include<iostream>
#include<fstream>
#include<sstream>
#include "ExternFile.h"
using namespace std;
Status AccountWrite(Account& account){
    ifstream in(ACCOUNT_PATH,ios::in);
    if(!in.is_open()){
        cout<<"Error:Fail to open system file!"<<endl;
        exit(1);
    }
    string line;
    istringstream strin;
    getline(in,line);
    in.close();
    long long temp=0;
    for(int i=0;i<line.size();++i)
        temp=temp*10+line[0]-'0';
    temp++;
    changeAN(temp);
    string t=to_string(temp);
    account.SID="00000000000";
    short int tt=t.size();
    account.SID=account.SID.substr(0,account.SID.size()-tt)+t;
    ofstream out;
    out.open(ACCOUNT_PATH,ios::app);
    out<<"1"<<","<<account.SID<<","<<account.name<<","<<to_string(account.sex)<<","<<account.telephone<<","
    <<account.cardID[0]<<account.cardID[1]<<account.cardID[2]<<account.cardID[3]<<","<<account.IDnumber<<","
    <<account.password<<","<<account.balance<<","<<account.year<<account.month<<account.day<<" "<<account.hour<<account.minute<<account.second<<","<<endl;
    out.close();
    return OK;
}
