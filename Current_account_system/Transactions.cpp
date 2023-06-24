/*
*账户交易信息
*/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<conio.h>
#include <type_traits>
#include "ExternFile.h"
using namespace std;
Status Transactions(Account& acc,TradeData& tr){
    system("cls");
    char c;
    cout<<"交易信息如下:"<<endl;
    string temp;
    TradeInfo* info;
    cout<<"-------------------------------------"<<endl;
    for(int i=0;i<acc.tradeID.size();++i){
        temp=acc.tradeID[i];
        info=tr.find(temp);
        if(info){
            cout<<setw(16)<<"交易流水号:"<<info->tradeID<<endl;
            cout<<setw(16)<<"交易类型:"<<(info->type==TradeType::IN?"存款":(info->type==TradeType::OUT?"取款":(info->type==TradeType::TO?"转账(转出)":"转账(转入)")))<<endl;
            cout<<setw(16)<<"姓名:"<<info->name<<endl;
            cout<<setw(16)<<"卡号:"<<info->cardID<<endl;
            if(info->type==TradeType::FROM||info->type==TradeType::TO){
                cout<<setw(16)<<(info->type==TradeType::TO?"转入方姓名:":"转出方姓名:")<<info->othername<<endl;
                cout<<setw(16)<<(info->type==TradeType::TO?"转入方卡号:":"转出方卡号:")<<info->otherID<<endl;
            }
            cout<<setw(16)<<"交易金额:"<<info->money<<endl;
            cout<<setw(16)<<"交易时间:"<<info->year<<"-"<<setw(2)<<setfill('0')<<info->month<<"-"<<setw(2)<<setfill('0')<<info->day<<" "
                <<setw(2)<<setfill('0')<<info->hour<<":"<<setw(2)<<setfill('0')<<info->minute<<":"<<setw(2)<<setfill('0')<<info->second<<endl;
            cout<<setfill(' ')<<setw(16)<<"交易备注:"<<info->info<<endl;
            cout<<"-------------------------------------"<<endl;
        }
        else{
            cout<<"第"<<i+1<<"条交易信息错误"<<endl;
            break;
        }
    }
    cout<<"-------------任意键返回--------------"<<endl;
    c=_getch();
    c=_getch();
    return OK;
}
Status Trade_AllInfo(TradeData& tr,AccountData& acc){
    int shownub=30;
    int page=0,pages=ceil(tr.getTrNumber()*1.0/shownub);
    if(tr.getTrNumber()==0){
        cout<<"暂无交易信息"<<endl;
        _sleep(1000);
    }
    else{
        char n1,n2;
        do{
            system("cls");
            cout<<"tradeID"<<" "<<"type"<<" "<<"name"<<" "<<"cardID"<<" "<<"another name"<<" "<<"another cardID"<<" "<<"time"<<" "<<"info"<<endl;
            for(int i=page*shownub;i<page*shownub+shownub&&i<tr.getTrNumber();i++){
                cout<<tr.getTrades()[i]<<endl;
            }
            printf("------------------------------------------------%d/%d---------------------------------------------\n",page+1,pages);
            printf("--------------------------下一页请按 → ，上一页请按 ← ， 退出请按q , 查询请按f---------------------------\n");
            n1=_getch(),n2=_getch();
            if(n2==77 && page<pages-1) page++;
            else if(n2==75 && page>0) page--;
            else if(n1=='f'){
                cout<<"请选择查询方式：1.流水号 2.时间 3.卡号"<<endl;
                int n;cin>>n;
                TradeInfo* p;
                string s;
                switch (n) {
                case 1:{
                    cout<<"请输入流水号:"<<endl;
                    cin>>s;
                    p=tr.find(s);
                    if(p!=nullptr){
                        system("cls");
                        cout<<"tradeID"<<" "<<"type"<<" "<<"name"<<" "<<"cardID"<<" "<<"another name"<<" "<<"another cardID"<<" "<<"time"<<" "<<"info"<<endl;
                        cout<<*p<<endl;
                        system("pause");
                    }
                    else{
                        cout<<"输入有误!"<<endl;
                        _sleep(1000);
                    }
                    break;
                }
                case 2:{
                    cout<<"请输入需要查找的日期，如20230612"<<endl;
                    string s;cin>>s;bool f=false;
                    int year=stoi(s.substr(0,4)),month=stoi(s.substr(4,2)),day=stoi(s.substr(6,2));
                    int tpage,tpages,cnt,size=0;
                    for(int i=0;i<tr.getTrades().size();i++){
                        if(tr.getTrades()[i].year==year  &&tr.getTrades()[i].month==month && tr.getTrades()[i].day==day){
                            if(!f){
                                f=true;tpage=0;cnt=i;
                            }
                            size++;
                        }
                    }
                    if(!f){
                        cout<<"输入有误"<<endl;
                        _sleep(1000);
                    }
                    else{
                        char tn1,tn2;
                        tpages=ceil(size/shownub);
                        do {
                            system("cls");
                            cout<<"tradeID"<<" "<<"type"<<" "<<"name"<<" "<<"cardID"<<" "<<"another name"<<" "<<"another cardID"<<" "<<"time"<<" "<<"info"<<endl;
                            for(int i=tpage*shownub+cnt;i<tpage*shownub+shownub && i-tpage*shownub-cnt<size;i++){
                                cout<<tr.getTrades()[i]<<endl;
                            }
                            printf("------------------------------------------------%d/%d---------------------------------------------\n",page+1,pages);
                            printf("-----------------------------------下一页请按 → ，上一页请按 ← ------------------------------------\n");
                            tn1=_getch(),tn2=_getch();
                            if(tn2==77 && tpage<tpages-1) tpage++;
                            else if(tn2==75 && tpage>0) tpage--;
                        }while (tn1!='q');
                    }
                }
                break;
                case 3:{
                    cout<<"请输入账户卡号:"<<endl;
                    cin>>s;
                    Account* a=acc.find(s,2);
                    if(a!=nullptr)
                        Transactions(*a,tr);
                    else{
                        cout<<"输入有误!"<<endl;
                        _sleep(1000);
                    }
                }
                default:
                    break;
                }
            }
        } while (n1!='q');
        system("cls");
    }
}
