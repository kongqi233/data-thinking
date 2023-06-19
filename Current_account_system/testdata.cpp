#include <bits/stdc++.h>
#include "ExternFile.h"
using namespace std;
int main(){
    ofstream out;
    out.open(ACCOUNT_PATH, ios::out | ios::trunc);
    out<<100<<endl;
    for(int i=1;i<=100;i++){
        out<<i<<",";
        string s("aaaa");
        for(auto &i:s) i+=rand()%26;
        out<<s<<","<<Sex(i%2)<<",";
        s="13900000000";
        for(int i=3;i<s.length();i++) s[i]+=rand()%10;
        out<<s<<","<<(long long)(rand()%10000*(long long)1e12+rand()%10000*(long long)1e8+rand()%10000*(long long)1e4+rand()%10000)<<",";
        s="110101000000000000";
        for(int i=6;i<s.length();i++) s[i]+=rand()%10;
        out<<s<<",";
        s="000000";for(auto &i:s) i+=rand()%10;
        out<<s<<","<<rand()%100000<<endl;
    }
    out.close();
    cout<<"yes";
}