/*
*显示所有账户信息(管理员模式)
*/
#include <iostream>
#include <conio.h>
#include <math.h>
#include "ExternFile.h"
using namespace std;
Status Account_info(const AccountData& data){
    int shownub=20;
    int page=0,pages=ceil(data.getAccNumber()/shownub);
    if(data.getAccNumber()==0){
        cout<<"无信息...请添加账户信息"<<endl;
    }
    else{
        char n1,n2;
        do
        {
            system("cls");
            cout<<"SID"<<"     name"<<"   sex       telephone         cardID                   IDnumber           balance"<<endl;
            for(int i=page*shownub;i<page*shownub+shownub;i++){
                cout<<data.getAccounts()[i]<<endl;
            }
            printf("------------------------------------------%d/%d------------------------------------------\n",page+1,pages);
            printf("--------------------------下一页请按 → ，上一页请按 ← ， 退出请按q---------------------------\n");
            n1=_getch(),n2=_getch();
            if(n2==77 && page<pages-1) page++;
            else if(n2==75 && page>0) page--;
        } while (n1!='q');
        system("cls");
    }
    return OK;
}

