#include <bits/stdc++.h>
using namespace std;
signed main() {
    int *arr = new int [1000];
    for(int i=0;i<5;i++) cin>>arr[i];
    for(int i=4;i>=1;i--) cout<<arr[i]<<endl;
    delete []arr;
}