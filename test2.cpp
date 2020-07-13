#include <bits/stdc++.h>
using namespace std;

void solve() {
    int ref[] = {2,4,8,6};
    long long int k, d0, d1; cin>>k>>d0>>d1;
    long long int sum = d0+d1, ci = 2, next_d = sum%10, refi = 0;
    if(k>2) {
        while((next_d != 2 && next_d !=4 && next_d != 6 && next_d != 8) && ci<=k) {
            sum+=next_d;
            next_d = sum%10;
            ci++;
        }
        next_d == 2 ? refi=0 : next_d == 4 ? refi=1 : next_d == 8 ? refi=2 : refi=3;
        sum+=((k-ci)/4)*20;
        ci+=((k-ci)/4)*4;
        while(k!=ci) {
            sum+= ref[refi];
            refi = (refi+1)%4;
            ci++;
        }
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