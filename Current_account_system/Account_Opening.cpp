/*
*储户开户
*/
#include<iostream>
#include<iomanip>
#include<conio.h>
#include "ExternFile.h"
using namespace std;
Status CreateBack(string& judge){//判回退
    string temp;
    cin>>temp;
    if(temp.size()==1&&temp[0]=='b'||temp[0]=='B')
        return ERROR;
    else if(temp.size()==1&&temp[0]=='E'||temp[0]=='e')
        return EXIT;
    else
        judge=temp;
    return OK;
}
Status CreateCheck(Account& account){//开户确认
    system("cls");
    string temp;
    char c;
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
        cout<<setw(16)<<"Y/y 确认 "<<" N/n 返回"<<endl;
        cout<<"----------------------------------"<<endl;
        c=_getch();
        if(c=='N'||c=='n')
            return ERROR;
    }while(c!='Y'&&c!='y'&&c!='N'&&c!='n');
    return OK;
}
Status Account_Creating(Account& account){//获取开户信息
    string temp;
    cout<<"请输入您的名字:"<<endl;
    if(account.name==""){
        if(CreateBack(temp)==OK)
            account.name=temp;
        else return EXIT;
    }
    else cout<<account.name<<endl;
    cout<<"请输入您的性别:1.男 2.女"<<endl;
    if(account.sex==Sex::NONE){
        Status s=CreateBack(temp);
        if(s==OK){
            if(temp.size()==1){
                if(temp[0]=='1')
                    account.sex=Sex::MALE;
                else if(temp[0]=='2')
                    account.sex=Sex::FEMALE;
                else return ERROR;
            }
            else return ERROR;
        }else if(s==ERROR){
            account.name="";
            return ERROR;
        }else return EXIT;
    }
    else cout<<to_string(account.sex)<<endl;
    cout<<"请输入您的手机号码:"<<endl;
    if(account.telephone==""){
        Status s=CreateBack(temp);
        if(s==OK){
            account.telephone=temp;
        }else if(s==ERROR){
            account.sex=Sex::NONE;
            return ERROR;
        }else return EXIT;
    }
    else cout<<account.telephone<<endl;
    cout<<"请输入您的身份证号:"<<endl;
    if(account.IDnumber==""){
        Status s=CreateBack(temp);
        if(s==OK){
            account.IDnumber=temp;
        }else if(s==ERROR){
            account.telephone="";
            return ERROR;
        }else return EXIT;
    }
    else cout<<account.IDnumber<<endl;
    cout<<"请输入您的密码:"<<endl;
    if(account.password==""){
        Status s=CreateBack(temp);
        if(s==OK){
            account.password=temp;
        }else if(s==ERROR){
            account.IDnumber="";
            return ERROR;
        }else return EXIT;
    }
    if(!CreateCheck(account)){
        account.password="";
        return ERROR;
    }
    return OK;
}
Status Account_Opening(AccountData& data){
    system("cls");
    clock_t s,e;
    Account account;
    s=clock();
    while(1){
        Status s=Account_Creating(account);
        if(s==ERROR)
            system("cls");
        else if(s==OK)
            break;
        else if(s==EXIT)
            return ERROR;
    }
    e=clock();
    CreateCardID(account,(e-s)%1000);
    short int time[6]={0};
    GetTime(time);
    account.year=time[0];account.month=time[1];account.day=time[2];
    account.hour=time[3];account.minute=time[4];account.second=time[5];
    account.xyear=account.xmonth=account.xday=account.xhour=account.xminute=account.xsecond=0;
    account.balance=0;
    AccountWrite(data,account);
    char c;
    do{
        system("cls");
        cout<<"开户成功！"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<setw(16)<<"姓名:"<<account.name<<endl;
        cout<<setw(16)<<"性别:"<<(account.sex==Sex::MALE?"男":"女")<<endl;
        cout<<setw(16)<<"手机号码:"<<account.telephone<<endl;
        cout<<setw(16)<<"身份证号:"<<account.IDnumber<<endl;
        cout<<setw(16)<<"账户卡号:"<<account.cardID.substr(0,4)<<" "<<account.cardID.substr(4,4)<<" "<<account.cardID.substr(8,4)<<" "<<account.cardID.substr(12,4)<<endl;
        cout<<setw(16)<<"开户时间:"<<account.year<<"-"<<setw(2)<<setfill('0')<<account.month<<"-"<<setw(2)<<setfill('0')<<account.day<<" "
            <<setw(2)<<setfill('0')<<account.hour<<":"<<setw(2)<<setfill('0')<<account.minute<<":"<<setw(2)<<setfill('0')<<account.second<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<setw(16)<<setfill(' ')<<"B/b 返回登录 "<<"E/e 退出系统"<<endl;
        cout<<"----------------------------------"<<endl;
        c=_getch();
        if(c=='E'||c=='e')
            exit(0);
    }while(c!='B'&&c!='b'&&c!='E'&&c!='e');
    return OK;
}
