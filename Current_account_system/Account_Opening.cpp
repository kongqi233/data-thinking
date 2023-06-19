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

Status CreateCheck(Account& account){
    system("cls");
    string temp;
    do{
        system("cls");
        cout<<"请重复您的密码:"<<endl;
        cin>>temp;
        if(temp.size()==1&&temp[0]=='b'||temp[0]=='B')
            return ERROR;
    }while(temp!=account.password);
    do{
        system("cls");
        cout<<"请确认您的信息:"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<setw(16)<<"姓名:"<<account.name<<endl;
        cout<<setw(16)<<"性别:"<<(account.sex==Sex::MALE?"男":"女")<<endl;
        cout<<setw(16)<<"手机号码:"<<account.telephone<<endl;
        cout<<setw(16)<<"身份证号:"<<account.IDnumber<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<setw(16)<<"Y/y 确认 "<<"N/n 返回"<<endl;
        cout<<"----------------------------------"<<endl;
        cin>>temp;
        if(temp=="Y"||temp=="y")
            break;
        if(temp=="N"||temp=="n")
            return ERROR;
    }while(temp!="Y"&&temp!="y"&&temp!="N"&&temp!="n");
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
    if(!CreateCheck(account)){
        account.password="";
        return ERROR;
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
