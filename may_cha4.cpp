#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

void solve() {
    ull x, y, l, r;
    cin>>x>>y>>l>>r;
    if(x==0 || y==0) cout<<0<<endl;
    ull cnum = 0;
    cnum = x|y;
    // 1.
    while(cnum>r)
        cnum-=pow(2,floor(log2(cnum)));
    // 2.
    // if(cnum>r) 
    //     cnum-=pow(2,ceil(log2(cnum-r)));
    if(((x&r)*(y&r)) > ((x&cnum)*(y&cnum))) cout<<r<<endl;
    else cout<<cnum<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) 
        solve();
}
