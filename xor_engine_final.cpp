#include <iostream>
using namespace std;

void fastscan(int &number) 
{ 
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar(); 
    if (c=='-') { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 

void solve() {
    int n, q; 
    // cin>>n>>q;
    fastscan(n);
    fastscan(q);
    int arr[n], evenp = 0, oddp = 0;
    for(int i = 0; i<n; i++) {
        // cin>>arr[i];
        fastscan(arr[i]);
        if(__builtin_parity(arr[i])) oddp++;
        else evenp++;
    }
    for(int i = 0; i<q; i++) {
        int p; 
        // cin>>p;
        fastscan(p);
        if(__builtin_parity(p)) cout<<oddp<<" "<<evenp<<"\n";
        else cout<<evenp<<" "<<oddp<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; 
    // cin>>t;
    fastscan(t);
    while(t--) 
        solve();
    return 0;
}