#include<bits/stdc++.h>
using namespace std;


int q_partition(int l,int h,vector<int>&v,int &sw1,int &comp1){
    int piv=l;
    int i=l+1;
    int j=h;
    while(i<=j){
        while(i<=j&&v[piv]>v[i]){
            comp1++;
            i++;
        }
        while(i<=j&&v[piv]<v[j]){
            comp1++;
            j--;
        }
        if(i<j){
            sw1++;
            swap(v[i],v[j]);
        }
    }
    swap(v[piv],v[j]);
    sw1++;
    return j;
}


void qsort(int l,int h,vector<int>&v,int &sw1,int &comp1){
    if(l<h){
        int p=q_partition(l,h,v,sw1,comp1);
        qsort(l,p-1,v,sw1,comp1);
        qsort(p+1,h,v,sw1,comp1);
    }
}

void solve(vector<int>&v,int &sw1,int &comp1){
    int l=0;
    int h=v.size()-1;
    qsort(l,h,v,sw1,comp1);
}


// Randomized 
int q_partition_r(int l,int h,vector<int>&v,int &sw2,int &comp2){
    int piv_idx=l+rand()%(h-l+1);
    swap(v[piv_idx],v[l]);
    int piv=l;
    int i=l+1;
    int j=h;
    while(i<=j){
        while(i<=j&&v[piv]>v[i]){
            comp2++;
            i++;
        }
        while(i<=j&&v[piv]<v[j]){
            comp2++;
            j--;
        }
        if(i<j){
            sw2++;
            swap(v[i],v[j]);
        }
    }
    swap(v[piv],v[j]);
    sw2++;
    return j;
}


void qsort_r(int l,int h,vector<int>&v,int &sw2,int &comp2){
    if(l<h){
        int p=q_partition_r(l,h,v,sw2,comp2);
        qsort_r(l,p-1,v,sw2,comp2);
        qsort_r(p+1,h,v,sw2,comp2);
    }
}

void solve_r(vector<int>&v,int &sw2,int &comp2){
    int l=0;
    int h=v.size()-1;
    qsort_r(l,h,v,sw2,comp2);
}



int main(){
    srand(time(0));
    vector<int>v={7,6,5,4,3,2,1};
    int sw1=0,comp1=0;
    int sw2=0,comp2=0;
    vector<int>v2=v;
    solve(v,sw1,comp1);
    cout<<"Comp1 : "<<comp1<<" sw1 : "<<sw1<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    solve_r(v2,sw2,comp2);
    cout<<"Comp2 : "<<comp2<<" sw2 : "<<sw2<<endl;

    for(auto i:v2){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}