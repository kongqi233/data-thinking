/*
*账户存款
*/
#include<iostream>
#include "ExternFile.h"
using namespace std;
Status Deposit(Account& account,TradeData& trade){
    system("cls");
    string pass="";
    double n=0;
    string ID="";
    bool flag=true;
    while(flag) {
        system("cls");
        cout<<"请输入存款金额:";
        cin>>n;
        if (n < 0.01)
            cout << "请输入合法金额!" << endl;
        else{
            do{
                system("cls");
                if(pass!=account.password){
                    cout<<"请输入账户密码:"<<endl;
                    pass=getpass();
                    if(pass!=account.password){
                        system("cls");
                        cout << "密码错误,请重新输入!" << endl;
                        _sleep(1000);
                        continue;
                    }
                }
                if(n>=50000){
                    system("cls");
                    cout << "请输入身份证号验证:" << endl;
                    cin >> ID;
                    if(ID!=account.IDnumber){
                        system("cls");
                        cout << "身份证号错误，请重新输入!" << endl;
                        _sleep(1000);
                        continue;
                    }
                    else{
                        system("cls");
                        cout << "验证成功！" << endl;
                        _sleep(1000);
                    }
                }
            }while (pass != account.password||(n>=50000&&ID!=account.IDnumber));
            system("cls");
            account.balance += n;
            CreateTradeInfo(trade,account,account,TradeType::IN,n);
            cout << "存款成功!\n当前账号余额为：" << account.balance << endl;
            system("pause");
            flag = false;
        }
    }
    return OK;
}
