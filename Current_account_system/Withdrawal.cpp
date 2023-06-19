/*
*账户取款
*/
#include<iostream>
#include "ExternFile.h"
using namespace std;

Status withdrawal(Account& account){
    system("cls");
    cout<<"当前账号余额为："<<account.balance<<endl;
    double n=0;
    cout<<"请输入取款数：";
    cin>>n;
    account.balance-=n;
    cout<<"当前账号余额为："<<account.balance<<endl;
    system("pause");
    return OK;
}

