/*
*账户存款
*/
#include<iostream>
#include "ExternFile.h"
using namespace std;
Status Deposit(Account& account){
    system("cls");
    string pass;
    cout<<"当前账号余额为："<<account.balance<<endl;
    double n=0;
    cout<<"请输入存款数：";
    cin>>n;
    string ID;
    bool flag=true;
    while(flag) {
        if (n < 0.01) {
            cout << "请输入合法金额!" << endl;
            cin >> n;
        }
        else if (n<50000) {
            cout<<"请输入账户密码:"<<endl;
            cin >> pass;
            while (pass != account.password) {
                cout << "密码错误,请重新输入！" << endl;
                _sleep(1000);
                cin >> pass;
            }
            account.balance += n;
            cout << "存款成功\n当前账号余额为：" << account.balance << endl;
            system("pause");
            flag = false;
        } else if (n >= 50000) {
            system("cls");
            cout << "取款金额:" << n << endl;
            cout << "请输入账户密码:" << endl;

            cin >> pass;
            while (pass != account.password) {
                system("cls");
                cout << "密码错误,请重新输入！" << endl;
                _sleep(1000);
                cin >> pass;
            }
            cout << "请输入身份证号码确认：" << endl;
           
            cin >> ID;
            while (ID != account.IDnumber) {
                system("cls");
                cout << "身份证号错误，请重新输入!" << endl;
                _sleep(1000);
                cin>>ID;
            }
            system("cls");
            cout << "验证成功！" << endl;
            account.balance += n;
            cout << "存款成功!\n当前账号余额为:" << account.balance << endl;
            flag = false;
            _sleep(1000);
        }
    }
    return OK;
}
