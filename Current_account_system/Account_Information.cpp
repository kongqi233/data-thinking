/*
*显示所有账户信息(管理员模式)
*/
#include<iostream>
#include <conio.h>
#include "ExternFile.h"
using namespace std;
void Account_info(AccountData data){
    int shownub=10;
    int page=0,pages=data.getAccNumber()/shownub+1;
    if(data.getAccNumber()==0){
        cout<<"无信息...请添加账户信息"<<endl;
    }
    else{
        char n1,n2;
        do
        {
            system("cls");
            cout<<"SID\t"<<endl;
            for(int i=page*shownub;i<page*shownub+shownub;i++){
                cout<<data.getAccounts()[i]<<endl;
            }
            printf("------------------------------------------%d/%d------------------------------------------\n",page,pages);
            cout<<"--------------------------下一页请按 → ，上一页请按 ← ，退出请按q---------------------------"<<endl;
            n1=_getch(),n2=_getch();
            if(n2==77) page++;
            else if(n2==75) page--;
        } while (n1!='q');
        system("cls");
    }
}

