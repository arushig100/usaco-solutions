#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct paths{
    int beg;
    int end;
};

int n;
paths ar[100000];
int num[100000];
bool sortA(paths a, paths b){
    return a.beg < b.beg;
}

int main(){
    freopen("planting.in","r",stdin);
    freopen("planting.out","w",stdout);

    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> ar[i].beg >> ar[i].end;
        
        // begins with lower farm and ends with higher
        if(ar[i].end < ar[i].beg){
            int m = ar[i].end;
            ar[i].end = ar[i].beg;
            ar[i].beg = m;
        }
    }
    for(int i = 0; i < n; i++){
        num[i] = 0;
    }
    
    sort(ar, ar+n-1, sortA);

    for(int i = 0; i < n-1; i++){
        num[ar[i].beg]++;
        num[ar[i].end]++;
    }
    
    int maxx = 0;
    for(int i = 0; i < n; i++){
        if(num[i] > maxx){
            maxx = num[i];
        }
    }
    cout << maxx + 1 << endl;
}
