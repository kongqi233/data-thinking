/*
*储户销户
*/
#include<bits/stdc++.h>
#include "ExternFile.h"
using namespace std;
void Account_Closure(Account &a){
    char c;
    string s;
    cout<<"是否确认销户(Y/N):"<<endl;
    cin>>c;
    while(c!='N'&&c!='Y'){
        cout<<"输入错误，请重新输入:"<<endl;
        cin>>c;
    }
    if(c=='N'){
    cout<<"取消销户，即将退出"<<endl;
        _sleep(1000);
    //跳转界面
    }
    else if(c=='Y'){
        if(a.balance>0){
            cout<<"账户还有余额，无法销户"<<endl;
            cout<<"请选择是否取出(Y/N)："<<endl;
            cin>>c;
            if(c=='Y'){
                cout<<"已取出,请继续操作"<<endl;
                _sleep(1000);
            }
            else{
                cout<<"无法销户，即将退出"<<endl;
                _sleep(1000);
                //返回到界面
            }
        }
        cout<<"请输入密码验证："<<endl;
        cin>>s;
        while(s!=a.password){
            cout<<"密码错误，请重新输入："<<endl;
            cin>>s;
        }
        cout<<"密码正确，即将销户！"<<endl;
        _sleep(1000);
        a.tag=true;
        cout<<"销户成功！"<<endl;
    }

}
