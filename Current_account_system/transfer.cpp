/*
 * �˻�ת��
 */
#include<iostream>
#include "ExternFile.h"
using namespace std;
Status transfer(Account & account,TradeData & trade){
    double n=0;
    string pass="",ID="",tocardnum="";
    bool flag=true;
    cout<<"������Ҫת���Ŀ���˻���"<<endl;
    cin>>tocardnum;
    AccountData  accdata;
    Account &acc2=accdata.find(tocardnum,2);
    cout<<"���ҵ�"<<endl;
    do{
        //system("cls");
        cout<<"��ǰ�˺����Ϊ:"<<account.balance<<endl;
        cout<<"������ת�˽��:"<<endl;
        cin>>n;
        if(n<0.01){
            system("cls");
            cout<<"������Ϸ����!"<<endl;
            _sleep(1000);
        }
        else if(n>account.balance){
            system("cls");
            cout<<"����!"<<endl;
            _sleep(1000);
        }
        else{
            do{
                system("cls");
                cout<<"���:"<<n<<endl;
                cout<<"�������˻�����:"<<endl;
                if(pass!=account.password){
                    cin>>pass;
                    if(pass!=account.password){
                        system("cls");
                        cout<<"�����������������!"<<endl;
                        _sleep(1000);
                    }
                }else cout<<"******"<<endl;
                if(n>=50000&&pass==account.password){
                    cout<<"���������֤��ȷ��:"<<endl;
                    cin>>ID;
                    if(ID!=account.IDnumber){
                        system("cls");
                        cout<<"���֤�Ŵ�������������!"<<endl;
                        _sleep(1000);
                    }
                    else{
                        system("cls");
                        cout<<"��֤�ɹ�!"<<endl;
                        _sleep(1000);
                    }
                }
            }while(pass!=account.password||(n>=50000&&ID!=account.IDnumber));
            account.balance-=n;
            acc2.balance+=n;
            system("cls");
            CreateTradeInfo(trade,account,acc2,TradeType::TO,n);
            CreateTradeInfo(trade,acc2,account,TradeType::FROM,n);
            cout<<"ת�˳ɹ�!\n��ǰ�˺����Ϊ:"<<account.balance<<endl;
            flag=false;
            system("pause");
        }
    }while(flag);
    return OK;
}