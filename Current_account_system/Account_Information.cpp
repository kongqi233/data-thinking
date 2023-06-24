/*
*显示所有账户信息(管理员模式)
*/
#include <cstddef>
#include <iostream>
#include <conio.h>
#include <math.h>
#include "ExternFile.h"
using namespace std;
Status Account_info(AccountData& data){
    int shownub=20;
    int page=0,pages=ceil(data.getAccNumber()/shownub);
    if(data.getAccNumber()==0){
        cout<<"无信息...请添加账户信息"<<endl;
    }
    else{
        char n1,n2;
        do{
            system("cls");
            cout<<"SID"<<"     name"<<"   sex       telephone         cardID                   IDnumber           balance       open time              close time         tag"<<endl;
            for(int i=page*shownub;i<page*shownub+shownub&&i<data.getAccNumber();i++){
                cout<<data.getAccounts()[i]<<endl;
            }
            printf("------------------------------------------------%d/%d---------------------------------------------\n",page+1,pages);
            printf("--------------------------下一页请按 → ，上一页请按 ← ， 退出请按q , 查询请按f---------------------------\n");
            n1=_getch(),n2=_getch();
            if(n2==77 && page<pages-1) page++;
            else if(n2==75 && page>0) page--;
            else if(n1=='f'){
                cout<<"请选择查询方式：1.电话号 2.卡号 3.身份证号"<<endl;
                int n;cin>>n;
                Account* p;
                switch (n) {
                    case 1:{
                        cout<<"请输入电话号"<<endl;
                        string s;cin>>s;
                        p=data.find(s,0);
                        if(p!=nullptr){
                            system("cls");
                            cout<<"SID"<<"     name"<<"   sex       telephone         cardID                   IDnumber           balance       open time              close time         tag"<<endl;
                            cout<<*p<<endl;
                            system("pause");
                        }
                        else{
                            cout<<"输入有误"<<endl;
                            _sleep(1000);
                        }
                        break;
                    }
                    case 2:{
                        cout<<"请输入卡号"<<endl;
                        string s;cin>>s;
                        p=data.find(s,2);
                        if(p!=nullptr){
                            system("cls");
                            cout<<"SID"<<"     name"<<"   sex       telephone         cardID                   IDnumber           balance       open time              close time         tag"<<endl;
                            cout<<*p<<endl;
                            system("pause");
                        }
                        else{
                            cout<<"输入有误"<<endl;
                            _sleep(1000);
                        }
                        break;
                    }
                    case 3:{
                        cout<<"请输入身份证号"<<endl;
                        string s;cin>>s;
                        p=data.find(s,1);
                        if(p!=nullptr){
                            system("cls");
                            cout<<"SID"<<"     name"<<"   sex       telephone         cardID                   IDnumber           balance       open time              close time         tag"<<endl;
                            cout<<*p<<endl;
                            system("pause");
                        }
                        else{
                            cout<<"输入有误"<<endl;
                            _sleep(1000);
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
        } while (n1!='q');
        system("cls");
    }
    return OK;
}

