#include<iostream>
#include<iomanip>
#include"ExternFile.h"
using namespace std;
int login(int flag=1){
    char c;
    do{
        system("cls");
        cout<<"             活期账户储蓄系统"<<endl;
        cout<<"============================================="<<endl;
        cout<<"|             请选择您的登录方式            |"<<endl;
        cout<<"|                                           |"<<endl;
        if(flag==1){
            cout<<"|           ----  用户登录  ----            |"<<endl;
            cout<<"|                                           |"<<endl;
            cout<<"|                管理员登录                 |"<<endl;
            cout<<"|                                           |"<<endl;
            cout<<"|                 用户注册                  |"<<endl;

        }
        else if(flag==2){
            cout<<"|                 用户登录                  |"<<endl;
            cout<<"|                                           |"<<endl;
            cout<<"|          ----  管理员登录  ----           |"<<endl;
            cout<<"|                                           |"<<endl;
            cout<<"|                 用户注册                  |"<<endl;
        }
        else if(flag==3){
            cout<<"|                 用户登录                  |"<<endl;
            cout<<"|                                           |"<<endl;
            cout<<"|                管理员登录                 |"<<endl;
            cout<<"|                                           |"<<endl;
            cout<<"|           ----  用户注册  ----            |"<<endl;
        }
        cout<<"|                                           |"<<endl;
        cout<<"============================================="<<endl;
        c=getchar();
        getchar();
        if((c=='w'||c=='W')&&flag>1)
            flag--;
        else if((c=='s'||c=='S')&&flag<3)
            flag++;
        else if(c=='q'||c=='Q')
            return 0;
        else if(c=='e'||c=='E')
            return flag;
    }while(1);
}
Status user(Account& acc,TradeData& tr){
    do{
        system("cls");
        char c;
        cout<<"姓名:"<<acc.name<<endl;
        cout<<"账号:"<<acc.cardID.substr(0,4)<<" **** **** "<<acc.cardID.substr(12,4)<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"1.余额 2.存款 3.取款 4.转账 5.账户 6.交易记录 7.退出登录 8.退出系统"<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        cin>>c;
        switch(c){
       case '1':
        Account_Balance(acc);
        break;
       case '2':
        Deposit(acc,tr);
        break;
       case '3':
        Withdrawal(acc,tr);
        break;
       case '4':
        break;
       case '5':
        system("cls");
        cout<<acc;
        system("pause");
        break;
       case '6':
        Transactions(acc,tr);
        break;
       case '7':
        return OK;
       case '8':
        exit(0);
        break;
       default:
        break;
       }
    }while(1);
}
void Login(AccountData& acc,TradeData& tr){
    int flag;
    string ID;
    string pass;
    Account* account;
    do{
        flag=login();
        if(flag==0)
            break;
        else if(flag==1){
            do{
                system("cls");
                cout<<"请输入您的账号:";
                cin>>ID;
                cout<<"请输入您的密码:";
                cin>>pass;
                system("cls");
                if(!(account=acc.find(ID,0))&&!(account=acc.find(ID,1)))
                   cout<<"账号输入错误!"<<endl;
                else if(pass!=account->password)
                    cout<<"密码错误!"<<endl;
                else{
                    cout<<"登录成功!"<<endl;
                    if(user(*account,tr)) flag=-1;
                }
                _sleep(1000);
            }while(flag!=-1);
        }
        else if(flag==2){

        }
        else if(flag==3){
            Account_Opening(acc);
            flag=-1;
            continue;
        }
    }while(1);
    return;
}
