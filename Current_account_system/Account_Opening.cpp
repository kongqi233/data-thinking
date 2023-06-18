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
Status Account_Creating(Account& account,string& createInfo){
    string temp;
    cout<<"请输入您的名字:"<<endl;
    if(CreateBack(temp)){
        account.name=temp;
        createInfo+="请输入您的名字:\n";
        createInfo+=temp;
        createInfo+='\n';
    }else return ERROR;
    getchar();
    cout<<"请输入您的性别:1.男 2.女"<<endl;
    if(CreateBack(temp)){
        if(temp.size()==1){
            if(temp[0]=='1')
                account.sex=Sex::MALE;
            else if(temp[0]=='2')
                account.sex=Sex::FEMALE;
            else return ERROR;
            createInfo+="请输入您的性别:1.男 2.女\n";
            createInfo+=temp;
            createInfo+='\n';
        }
        else return ERROR;
    }else return ERROR;
    cout<<"请输入您的手机号码:"<<endl;
    if(CreateBack(temp)){
        account.telephone=temp;
        createInfo+="请输入您的手机号码:\n";
        createInfo+=temp;
        createInfo+='\n';
    }else return ERROR;
    cout<<"请输入您的身份证号:"<<endl;
    if(CreateBack(temp)){
        account.IDnumber=temp;
        createInfo+="请输入您的身份证号:\n";
        createInfo+=temp;
        createInfo+='\n';
    }else return ERROR;
    cout<<"请输入您的密码:"<<endl;
    if(CreateBack(temp)){
        account.password=temp;
        createInfo+="请输入您的密码:\n";
        createInfo+=temp;
        createInfo+='\n';
    }else return ERROR;
    return OK;
}
Status Account_Opening(){
    Account account;
    string createInfo="";
    while(!Account_Creating(account,createInfo)){
        cout<<createInfo<<endl;
    }
    return OK;
}
