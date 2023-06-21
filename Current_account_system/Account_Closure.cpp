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

    }
    else if(c=='Y'){
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
