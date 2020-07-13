#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int ref[] = {2,4,8,6};
    ll k, d0, d1; cin>>k>>d0>>d1;
    ll sum = d0+d1;
    if(k==2) { 
        if(sum%3 == 0)  cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    ll d2 = (d0+d1)%10;
    sum += d2 + ((k-3)/4)*20;
    int rem = (k-3)%4, temp = d0+d1;
    while(rem--) {
        temp = (2*temp)%10;
        sum+=temp;
    }
    if(sum%3 == 0)  cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}