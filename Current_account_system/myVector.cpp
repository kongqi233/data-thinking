#ifndef myvector
#define myvector
#include <iostream>
template<typename T>
class myVector
{
private:
    T* data=nullptr;
    std::size_t sizen,max_size;
public:
    myVector(std::size_t n=10){
        data=new T[n+10];
        max_size=n+10;
        sizen=0;
    }
    template<typename...Args>
    myVector(Args... args){
        data=new T[20];
        max_size=20;
        sizen=0;
        addlist(args...);
    }
    ~myVector(){
        delete[] data;
    }
    std::size_t size() const {
        return sizen;
    }
    bool empty() const {
        return sizen==0;
    }
    T& operator[](int i){
        return data[i];
    }
    const T& operator[](int i)const{
        return data[i];
    }
    void erase(int pos){
        for(int i=pos+1;i<sizen;i++) data[i-1]=data[i];
        sizen--;
    }
    void swap(int i,int j){
        if(i<sizen&&j<sizen){
            T t=data[i];data[i]=data[j];data[j]=t;
        }
    }
    void addlist(const T& t){
        push_back(t);
    }
    template<typename...Args>
    void addlist(const T& t,Args... args){
        push_back(t);
        addlist(args...);
    }
    myVector& push_back(const T& t){
        if(sizen==max_size) reserve(max_size*1.5);
        data[sizen++]=t;
        return *this;
    }
    myVector& insert(int pos,const T& t){
        if(sizen==max_size) reserve(max_size*1.5);
        for(int i=sizen;i>pos;i--) data[i]=data[i-1];
        data[pos]=t;
        sizen++;
    }
    void reserve(std::size_t n){
        if(n<=max_size) return;
        T* t=data;
        data=new T[n+10];
        max_size=n+10;
        for(int i=0;i<sizen;i++) data[i]=t[i];
        delete[] t;
    }
};

#endif