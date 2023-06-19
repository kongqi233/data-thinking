/*
*获取时间
*/
#include<iostream>
#include<time.h>
#include "ExternFile.h"
using namespace std;
Status GetTime(short int t[]){
    time_t now=time(NULL);
    tm* tm_t=localtime(&now);
    t[0]=tm_t->tm_year+1900;
    t[1]=tm_t->tm_mon+1;
    t[2]=tm_t->tm_mday;
    t[3]=tm_t->tm_hour;
    t[4]=tm_t->tm_min;
    t[5]=tm_t->tm_sec;
    return OK;
}
