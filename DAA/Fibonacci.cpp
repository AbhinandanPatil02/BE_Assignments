#include<iostream>
using namespace std;


int fibo_re(int n){
    if(n<=1)return n;
    return fibo_re(n-1)+fibo_re(n-2);
}

void print_re_fibo(int n){
    for(int i=0;i<=n;i++){
        cout<<fibo_re(i)<<" ";
    }
}


void fibo_itr(int n){
    if(n<0)return;
    if(n==0){
        cout<<"0";
        return;
    }
    int a=0,b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=2;i<=n;i++){
        int c=a+b;
        a=b;
        b=c;
        cout<<c<<" ";
    }
}

int main(){
    
    while(true){
        cout<<"Enter num : ";
        int n;
        cin>>n;
        // print_re_fibo(n);
        fibo_itr(n);
        cout<<endl;
        cout<<"Want to continue ? (y/n)";
        string a;
        cin>>a;
        if(a=="n")break;
    }
    
    return 0;
}