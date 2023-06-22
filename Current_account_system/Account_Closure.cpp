/*
*储户销户
*/
#include<iostream>
#include<iomanip>
#include "ExternFile.h"
using namespace std;
Status Account_Closure(Account &a){
    char c;
    string pass="",ID="";
    do{
        system("cls");
        cout<<setw(16)<<"是否确"<<"认销户"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<setw(16)<<"Y/y 确认 "<<" N/n 取消"<<endl;
        cin>>c;
        if(c!='N'&&c!='n'&&c!='Y'&&c!='y'){
            system("cls");
            cout<<"输入错误!"<<endl;
            _sleep(500);
        }
    }while(c!='N'&&c!='n'&&c!='Y'&&c!='y');
    if(c=='N'||c=='n'){
        system("cls");
        cout<<"取消销户，即将返回..."<<endl;
        _sleep(1000);
        return ERROR;
    }
    else if(c=='Y'||c=='y'){
        if(a.balance>0){
            system("cls");
            cout<<"请将余额取出再进行销户"<<endl;
            _sleep(1000);
            return ERROR;
        }
        else{
            do{
                system("cls");
                cout<<"请输入密码验证:"<<endl;
                if(pass!=a.password){
                    cin>>pass;
                    if(pass=="B"||pass=="b")
                        return ERROR;
                }else cout<<"******"<<endl;
                cout<<"请输入身份证号验证:"<<endl;
                cin>>ID;
                if(ID=="b"||ID=="B")
                    return ERROR;
            }while(pass!=a.password||ID!=a.IDnumber);
        }
        system("cls");
        cout<<"验证成功，即将销户！"<<endl;
        _sleep(1000);
        a.tag=true;
        system("cls");
        cout<<"销户成功！"<<endl;
        _sleep(1000);
    }
    return OK;
}
