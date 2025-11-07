#include<bits/stdc++.h>
using namespace std;

// Normal partition
int partition(int l,int h,vector<int>&v,int &sw,int &comp){
    int p = v[l];
    int i = l + 1;
    int j = h;
    while(true){
        while(i <= j && v[i] <= p){
            i++;
            comp++; // comparison
        }
        comp++; // for the failed condition
        while(i <= j && v[j] > p){
            j--;
            comp++; // comparison
        }
        comp++; // for the failed condition
        if(i >= j) break;
        swap(v[i], v[j]);
        sw++; // swap count
    }
    swap(v[l], v[j]);
    sw++;
    return j;
}

void qsort(vector<int>&v,int l,int r,int &sw,int &comp){
    if(l < r){
        int p = partition(l, r, v, sw, comp);
        qsort(v, l, p - 1, sw, comp);
        qsort(v, p + 1, r, sw, comp);
    }
}

// Randomized partition
int r_partition(int l,int h,vector<int>&v,int &sw,int &comp){
    int p_idx = l + rand() % (h - l + 1);
    swap(v[l], v[p_idx]);
    sw++;
    int p = v[l];
    int i = l + 1;
    int j = h;
    while(true){
        while(i <= j && v[i] <= p){
            i++;
            comp++;
        }
        comp++;
        while(i <= j && v[j] > p){
            j--;
            comp++;
        }
        comp++;
        if(i >= j) break;
        swap(v[i], v[j]);
        sw++;
    }
    swap(v[l], v[j]);
    sw++;
    return j;
}

void r_qsort(vector<int>&v,int l,int r,int &sw,int &comp){
    if(l < r){
        int p = r_partition(l, r, v, sw, comp);
        r_qsort(v, l, p - 1, sw, comp);
        r_qsort(v, p + 1, r, sw, comp);
    }
}

int main(){
    srand(time(0));

    vector<int> v1 = {10,6,4,3,2,1};
    vector<int> v2 = v1;

    int sw1 = 0, comp1 = 0;
    int sw2 = 0, comp2 = 0;

    // Normal QuickSort
    qsort(v1, 0, v1.size() - 1, sw1, comp1);

    // Randomized QuickSort
    r_qsort(v2, 0, v2.size() - 1, sw2, comp2);

    cout << "Sorted (Normal): ";
    for(auto i : v1) cout << i << " ";
    cout << "\nSwaps: " << sw1 << "  Comparisons: " << comp1 << "\n\n";

    cout << "Sorted (Randomized): ";
    for(auto i : v2) cout << i << " ";
    cout << "\nSwaps: " << sw2 << "  Comparisons: " << comp2 << "\n";

    return 0;
}
