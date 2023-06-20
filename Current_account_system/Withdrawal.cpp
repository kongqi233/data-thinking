/*
*账户取款
*/
#include<iostream>
#include "ExternFile.h"
using namespace std;
Status Withdrawal(Account& account){
    system("cls");
    cout<<"当前账号余额为:"<<account.balance<<endl;
    double n=0;
    string pass="",ID="";
    cout<<"请输入取款金额:"<<endl;
    cin>>n;
    bool flag=true;
    while(flag){
        if(n<0.01){
            cout<<"请输入合法金额!"<<endl;
            cin>>n;
        }
        else if(n>account.balance){
            cout<<"余额不足!"<<endl;
            cin>>n;
        }
        else{
            do{
                system("cls");
                cout<<"取款金额:"<<n<<endl;
                cout<<"请输入账户密码:"<<endl;
                if(pass!=account.password){
                    cin>>pass;
                    if(pass!=account.password){
                        system("cls");
                        cout<<"密码错误，请重新输入!"<<endl;
                        _sleep(1000);
                    }
                }else cout<<"******"<<endl;
                if(n>50000&&pass==account.password){
                    cout<<"请输入身份证号确认:"<<endl;
                    cin>>ID;
                    if(ID!=account.IDnumber){
                        system("cls");
                        cout<<"身份证号错误，请重新输入!"<<endl;
                        _sleep(1000);
                    }
                }
            }while(pass!=account.password||(n>50000&&ID!=account.IDnumber));
            system("cls");
            account.balance-=n;
            cout<<"取款成功!\n当前账号余额为:"<<account.balance<<endl;
            flag=false;
            _sleep(1000);
    }
    }
    return OK;
}

