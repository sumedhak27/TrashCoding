#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

void solve() {
    ull x, y, l, r;
    cin>>x>>y>>l>>r;
    ull maxres = 0, minind = l;
    for(ull i = l; i<=r; i++) {
        ull res = (x&i)*(y&i);
        if(res>maxres) {
            maxres = res;
            minind = i;
        }
    }
    cout<<minind<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--)
        solve();
}