#include<iostream>
#include<fstream>
#include<sstream>
#include "ExternFile.h"
using namespace std;
Status AccountWrite(AccountData& data,Account& account){
    long long len=data.getAccNumber();
    len++;
    account.SID="00000000000";
    string temp=to_string(len);
    account.SID=account.SID.substr(0,(11-temp.size()))+temp;
    account.tag=false;
    data.addAccount(account);
    return OK;
}
