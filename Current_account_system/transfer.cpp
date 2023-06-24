/*
 * 账户转账
 */
#include<iostream>
#include "ExternFile.h"
using namespace std;
Status transfer(Account& account,AccountData& accdata,TradeData& trade)
{
    double n=0;
    string pass="",ID="",tocardnum="";
    bool flag=true;
    Account* acc2;
    do
    {
        system("cls");
        cout<<"请输入转账账户:"<<endl;
        cin>>tocardnum;
        if(tocardnum=="Q"||tocardnum=="q")
            return ERROR;
        acc2=accdata.find(tocardnum,2);
        if(acc2!=nullptr)
            break;
        else
        {
            cout<<"账户输入错误!"<<endl;
            _sleep(1000);
        }
    }
    while(1);
    do
    {
        cout<<"当前账号余额为:"<<account.balance<<endl;
        cout<<"请输入转账金额:"<<endl;
        cin>>n;
        if(n<0.01)
        {
            system("cls");
            cout<<"请输入合法金额!"<<endl;
            _sleep(1000);
        }
        else if(n>account.balance)
        {
            system("cls");
            cout<<"余额不足!"<<endl;
            _sleep(1000);
        }
        else
        {
            do
            {
                system("cls");
                cout<<"金额:"<<n<<endl;
                cout<<"请输入账户密码:"<<endl;
                if(pass!=account.password)
                {
                    pass=getpass();
                    if(pass=="Q"||pass=="q")
                        return ERROR;
                    if(pass!=account.password)
                    {
                        system("cls");
                        cout<<"密码错误，请重新输入!"<<endl;
                        _sleep(1000);
                    }
                }
                else cout<<"******"<<endl;
                if(n>=50000&&pass==account.password)
                {
                    cout<<"请输入身份证号确认:"<<endl;
                    cin>>ID;
                    if(ID=="Q"||ID=="q")
                        return ERROR;
                    if(ID!=account.IDnumber)
                    {
                        system("cls");
                        cout<<"身份证号错误，请重新输入!"<<endl;
                        _sleep(1000);
                    }
                    else
                    {
                        system("cls");
                        cout<<"验证成功!"<<endl;
                        _sleep(1000);
                    }
                }
            }
            while(pass!=account.password||(n>=50000&&ID!=account.IDnumber));
            account.balance-=n;
            acc2->balance+=n;
            system("cls");
            CreateTradeInfo(trade,account,*acc2,TradeType::TO,n);
            cout<<"转账成功!\n当前账号余额为:"<<account.balance<<endl;
            flag=false;
            system("pause");
        }
    }
    while(flag);
    return OK;
}
