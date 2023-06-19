/*
*储户开户
*/
#include<bits/stdc++.h>
#include "ExternFile.h"
using namespace std;
Status CreateBack(string& judge){
    string temp;
    cin>>temp;
    if(temp.size()==1&&temp[0]=='b'||temp[0]=='B')
        return ERROR;
    else
        judge=temp;
    return OK;
}
Status Account_Creating(Account& account){
    string temp;
    cout<<"请输入您的名字:"<<endl;
    if(account.name==""){
        if(CreateBack(temp))
            account.name=temp;
        else return ERROR;
    }
    else cout<<account.name<<endl;
    cout<<"请输入您的性别:1.男 2.女"<<endl;
    if(account.sex==Sex::NONE){
        if(CreateBack(temp)){
            if(temp.size()==1){
                if(temp[0]=='1')
                    account.sex=Sex::MALE;
                else if(temp[0]=='2')
                    account.sex=Sex::FEMALE;
                else return ERROR;
            }
            else return ERROR;
        }else{
            account.name="";
            return ERROR;
        }
    }
    else cout<<to_string(account.sex)<<endl;
    cout<<"请输入您的手机号码:"<<endl;
    if(account.telephone==""){
        if(CreateBack(temp)){
            account.telephone=temp;
        }else{
            account.sex=Sex::NONE;
            return ERROR;
        }
    }
    else cout<<account.telephone<<endl;
    cout<<"请输入您的身份证号:"<<endl;
    if(account.IDnumber==""){
        if(CreateBack(temp)){
            account.IDnumber=temp;
        }else{
            account.telephone="";
            return ERROR;
        }
    }
    else cout<<account.IDnumber<<endl;
    cout<<"请输入您的密码:"<<endl;
    if(account.password==""){
        if(CreateBack(temp)){
            account.password=temp;
        }else{
            account.IDnumber="";
            return ERROR;
        }
    }
    return OK;
}
Status Account_Opening(){
    Account account;
    while(!Account_Creating(account)){
        system("cls");
    }
    return OK;
}
