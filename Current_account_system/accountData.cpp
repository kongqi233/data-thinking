#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ExternFile.h"

AccountData::AccountData(string path){
    ifstream in;
    in.open(path, ios::in);
    if(in.is_open()){
        string s;
        getline(in,s);
        long long l=stoi(s);
        accountsNumber=l;
        accounts.reserve(l);
        phone.reserve(l);
        cardID.reserve(l);
        IDnumber.reserve(l);
        for(long long i=0;i<l;i++){
            getline(in,s);
            string word;
            istringstream sin;
            Account account;
            sin.clear();
            sin.str(s);
            getline(sin,word,',');
            account.SID=word;
            getline(sin,word,',');
            account.name=word;
            getline(sin,word,',');
            account.sex=Sex(stoi(word));
            getline(sin,word,',');
            account.telephone=word;
            getline(sin,word,',');
            account.cardID=word;
            getline(sin,word,',');
            account.IDnumber=word;
            getline(sin,word,',');
            account.password=word;
            getline(sin,word,',');
            account.balance=stod(word);
            account.year=account.month=account.day=account.hour=account.minute=account.second=0;
            account.xyear=account.xmonth=account.xday=account.xhour=account.xminute=account.xsecond=0;
            accounts.push_back(account);

            phone.push_back(stoipair(account.telephone,i));
            cardID.push_back(stoipair(account.cardID,i));;
            IDnumber.push_back(stoipair(account.IDnumber,i));;
        }
    }
    in.close();
    AccountData::sort<stoipair>(phone, 0, phone.size()-1, [](stoipair a,stoipair b){
        return a.key<b.key;
    });
    AccountData::sort<stoipair>(cardID, 0, cardID.size()-1, [](stoipair a,stoipair b){
        return a.key<b.key;
    });
    AccountData::sort<stoipair>(IDnumber, 0, IDnumber.size()-1, [](stoipair a,stoipair b){
        return a.key<b.key;
    });
}

AccountData::~AccountData(){
    ofstream out;
    out.open(ACCOUNT_PATH, ios::out | ios::trunc);
    out<<accounts.size()<<endl;
    for(int i=0;i<accounts.size();i++){
        out<<accounts[i].SID<<","<<accounts[i].name<<","<<accounts[i].sex<<","<<accounts[i].telephone<<",";
        out<<accounts[i].cardID<<","<<accounts[i].IDnumber<<","<<accounts[i].password<<","<<accounts[i].balance<<endl;
    }
    out.close();
}


template<typename U,typename T>
void AccountData::sort(T& q,int l,int r,std::function<bool(U,U)> const &f){
    int i=l,j=r;
    auto min=(l+r)/2;
    while (i<=j)
    {
        while (f(q[i],q[min])) i++;
        while (f(q[min],q[j])) j--;
        if(i<=j){q.swap(i,j);i++;j--;}
    }
    if(l<j) sort(q,l,j,f);
    if(i<r) sort(q,i,r,f);
}

Account& AccountData::find(const string &s,int n){
    myVector<stoipair> &p=cardID;
    switch (n) {
        case 0: p=phone;break;
        case 1: p=IDnumber;break;
    }
    int t=-1,l=0,r=p.size()-1,mid;
    while (l<=r) {
        mid=l+((r-l)>>1);
        if(p[mid].key<s) l=mid+1;
        else if(p[mid].key>s) r=mid-1;
        else{
            t=p[mid].value;break;
        }
    }
    if(t==-1) cout<<"输入错误"<<endl;
    else return accounts[t];
}

void AccountData::addAccount(const Account& acc){
    accounts.addlist(acc);
    accountsNumber++;
    return;
}

long long AccountData::getAccNumber(){
    return accountsNumber;
}
