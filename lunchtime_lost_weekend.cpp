#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    while(t--) {
        int sum=0;
        for(int i = 0; i<5; i++) {
            int t; cin>>t;
            sum+=t;
        }
        int p; cin>>p;
        sum*=p;
        if(sum>120) cout<<"Yes\n";
        else cout<<"No\n";
    }
}