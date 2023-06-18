/*
*储户开户
*/
#include<bits/stdc++.h>
#include "ExternFile.h"
using namespace std;
Status Account_Creating(string& createInfo){
    Account account;
    cout<<"请输入您的名字:"<<endl;
    cin>>account.name;
    getchar();
    cout<<"请输入您的性别:1.男 2.女"<<endl;
    char sex=getchar();
    if(sex=='1')
        account.sex=Sex::MALE;
    else if(sex=='2')
        account.sex=Sex::FEMALE;
    cout<<"请输入您的手机号码:"<<endl;
    cin>>account.telephone;
    cout<<"请输入您的身份证号:"<<endl;
    cin>>account.IDnumber;
    cout<<"请输入您的密码:"<<endl;
    cin>>account.password;
    return OK;
}
Status Account_Opening(){
    string createInfo="";
    while(!Account_Creating(createInfo)){
        cout<<createInfo<<endl;
    }
    return OK;
}
