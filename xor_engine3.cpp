#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// #define P2(n) n, n ^ 1, n ^ 1, n 
// #define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n) 
// #define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n) 
// #define LOOK_UP P6(0), P6(1), P6(1), P6(0) 

// unsigned int table[256] = { LOOK_UP }; 
// unsigned int table[256];


// int Parity(int num) {
//     if(num < 256)
//         return table[num];
    
//     int max = 16; 
//     while (max >= 8) { 
//         num = num ^ (num >> max); 
//         max = max / 2; 
//     } 
//     return table[num & 0xff]; 
// } 

void solve() {
    int n, q; cin>>n>>q;
    int arr[n], evenp = 0, oddp = 0;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
        if(__builtin_parity(arr[i])) oddp++;
        else evenp++;
    }
    for(int i = 0; i<q; i++) {
        int p; cin>>p;
        if(__builtin_parity(p)) cout<<oddp<<" "<<evenp<<endl;
        else cout<<evenp<<" "<<oddp<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    // for(int i = 0; i<256; i++) {
    //     table[i] = __builtin_parity(i);
    // }
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}