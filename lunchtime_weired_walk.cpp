#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        ll a[n], b[n];
        for(ll i = 0; i<n; i++) cin>>a[i];
        for(ll i = 0; i<n; i++) cin>>b[i];
        ll dist_a = 0, dist_b = 0, wd = 0;
        for(ll i = 0; i<n; i++) {
            if(dist_a == dist_b && a[i]==b[i]) wd+=a[i];
            dist_a+=a[i];
            dist_b+=b[i];
        }
        cout<<wd<<"\n";
    }
}