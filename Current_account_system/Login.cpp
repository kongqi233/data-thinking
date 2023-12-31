#include <cstdio>
#include<iostream>
#include<iomanip>
#include<conio.h>
#include <unistd.h>
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
            cout<<"|                                           |"<<endl;
            cout<<"|(w/W)上移  (s/S)下移   (e/E)进入  (q/Q)退出|"<<endl;

        }
        else if(flag==2){
            cout<<"|                 用户登录                  |"<<endl;
            cout<<"|                                           |"<<endl;
            cout<<"|          ----  管理员登录  ----           |"<<endl;
            cout<<"|                                           |"<<endl;
            cout<<"|                 用户注册                  |"<<endl;
            cout<<"|                                           |"<<endl;
            cout<<"|(w/W)上移  (s/S)下移   (e/E)进入  (q/Q)退出|"<<endl;
        }
        else if(flag==3){
            cout<<"|                 用户登录                  |"<<endl;
            cout<<"|                                           |"<<endl;
            cout<<"|                管理员登录                 |"<<endl;
            cout<<"|                                           |"<<endl;
            cout<<"|           ----  用户注册  ----            |"<<endl;
            cout<<"|                                           |"<<endl;
            cout<<"|(w/W)上移  (s/S)下移   (e/E)进入  (q/Q)退出|"<<endl;
        }
        cout<<"|                                           |"<<endl;
        cout<<"============================================="<<endl;
        c=_getch();
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
string getpass(){
    string s;
    char c;
    do {
        c=_getch();
        if(c==8){
            printf("\b \b");
            s.pop_back();
        }
        else if(c!=13){
            putchar('*');
            s.push_back(c);
        }
    }while(c!=13);
    putchar('\n');
    return s;
}
Status user(Account& acc,AccountData& data,TradeData& tr){
    do{
        system("cls");
        char c;
        cout<<"姓名:"<<setw(30)<<left<<acc.name<<right;
        cout<<"账号:"<<acc.cardID.substr(0,4)<<" **** **** "<<acc.cardID.substr(12,4)<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<"1.余额 2.存款 3.取款 4.转账 5.账户 6.销户 7.交易记录 8.退出登录 9.退出系统"<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
        c=_getch();
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
        transfer(acc,data,tr);
        break;
       case '5':{
        system("cls");
        string pass;
        do{
            system("cls");
            cout<<"请输入账户密码:";
            pass=getpass();
        }while(pass!=acc.password&&pass!="b"&&pass!="B");
        if(pass=="b"||pass=="B")
            break;
        system("cls");
        cout<<setw(16)<<"姓名:"<<acc.name<<"\n"
        <<setw(16)<<"性别:"<<(acc.sex==Sex::MALE?"男":"女")<<"\n"
        <<setw(16)<<"手机号:"<<acc.telephone<<"\n"
        <<setw(16)<<"卡号:"<<acc.cardID<<"\n"
        <<setw(16)<<"身份证号:"<<acc.IDnumber<<"\n"
        <<setw(16)<<"余额:"<<acc.balance<<"\n"
        <<setw(16)<<"开户时间:"<<acc.year<<"-"<<setw(2)<<setfill('0')<<acc.month<<"-"<<setw(2)<<acc.day<<" "
        <<setw(2)<<acc.hour<<":"<<setw(2)<<acc.minute<<":"<<setw(2)<<acc.second<<setfill(' ')<<"\n";
        cout<<"-----------任意键返回-----------"<<endl;
        c=_getch();
        break;
        }
       case '6':
        Account_Closure(acc,data);
        break;
       case '7':
        Transactions(acc,tr);
        break;
       case '8':
        return OK;
       case '9':
        return EXIT;
       default:
        break;
       }
    }while(1);
}
Status admin_account(AccountData& data,TradeData& tr){
    do{
        system("cls");
        cout<<"请输入您要查询的账户卡号:"<<endl;
        string ID;
        cin>>ID;
        Account* acc;
        if(ID=="Q"||ID=="q")
            return OK;
        acc=data.find(ID,2);
        if(acc!=nullptr){
            char c;
            do{
                system("cls");
                cout<<setw(16)<<"姓名:"<<acc->name<<"\n"
                <<setw(16)<<"性别:"<<(acc->sex==Sex::MALE?"男":"女")<<"\n"
                <<setw(16)<<"手机号:"<<acc->telephone<<"\n"
                <<setw(16)<<"卡号:"<<acc->cardID<<"\n"
                <<setw(16)<<"身份证号:"<<acc->IDnumber<<"\n"
                <<setw(16)<<"余额:"<<acc->balance<<"\n"
                <<setw(16)<<"开户时间:"<<acc->year<<"-"<<setw(2)<<setfill('0')<<acc->month<<"-"<<setw(2)<<acc->day<<" "
                <<setw(2)<<acc->hour<<":"<<setw(2)<<acc->minute<<":"<<setw(2)<<acc->second<<setfill(' ')<<"\n"
                <<setw(16)<<"是否销户:"<<(acc->tag?"是\n":"否\n")
                <<setw(16)<<"销户时间:"<<setw(4)<<setfill('0')<<acc->xyear<<"-"<<setw(2)<<acc->xmonth<<"-"<<setw(2)<<acc->xday<<" "
                <<setw(2)<<acc->xhour<<":"<<setw(2)<<acc->xminute<<":"<<setw(2)<<acc->xsecond<<setfill(' ')<<endl;
                cout<<"--------------------------------------"<<endl;
                cout<<"------B/b 返回  F/f 查看交易记录------"<<endl;
                c=_getch();
                if(c=='F'||c=='f'){
                    Transactions(*acc,tr);
                }
            }while(c!='B'&&c!='b');
        }
        else{
            system("cls");
            cout<<"账户输入错误!"<<endl;
            _sleep(1000);
        }
    }while(1);
}
Status admin(AccountData& acc,TradeData& tr){
    char c;
    do{
        system("cls");
        cout<<"                   账户管理                    "<<endl;
        cout<<"账户数量:"<<acc.getAccNumber()<<"\t\t已销户账户:"<<acc.getCloNumber()<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"1.账户查看 2.所有账户信息 3.所有交易信息 4.返回登入 5.退出系统"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        c=_getch();
        switch(c){
        case '1':
            admin_account(acc,tr);
            break;
        case '2':
            Account_info(acc);
            break;
        case '3':
            Trade_AllInfo(tr,acc);
            break;
        case '4':
            return OK;
        case '5':
            return EXIT;
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
                if(ID=="Q"||ID=="q"){
                    flag=-1;
                    break;
                }
                cout<<"请输入您的密码:";
                pass=getpass();
                if(pass=="Q"||pass=="q"){
                    flag=-1;
                    break;
                }
                system("cls");
                if(!(account=acc.find(ID,0))&&!(account=acc.find(ID,1))&&!(account=acc.find(ID,2)))
                   cout<<"账号输入错误!"<<endl;
                else if(pass!=account->password)
                    cout<<"密码错误!"<<endl;
                else{
                    cout<<"登录成功!"<<endl;
                    if(user(*account,acc,tr)==OK) flag=-1;
                    else return;
                }
                _sleep(1000);
            }while(flag!=-1);
        }
        else if(flag==2){
            do{
                system("cls");
                cout<<"请输入管理员账号:";
                ID=getpass();
                if(ID=="Q"||ID=="q"){
                    flag=-1;
                    break;
                }
                cout<<"请输入管理员密码:";
                pass=getpass();
                if(pass=="Q"||pass=="q"){
                    flag=-1;
                    break;
                }
                system("cls");
                if(ID!=ADMIN||pass!=ADMIN_PASS)
                    cout<<"账号或密码错误!"<<endl;
                else{
                    cout<<"登录成功，欢迎管理员!"<<endl;
                    _sleep(1000);
                    system("cls");
                    if(admin(acc,tr)==OK) flag=-1;
                    else return;
                }
                _sleep(1000);
            }while(flag!=-1);
        }
        else if(flag==3){
            if(Account_Opening(acc)!=EXIT) flag=-1;
            else return;
            continue;
        }
    }while(1);
    return;
}
