#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin>>n>>q;
    string s; cin>>s;
    unordered_map<char, int> mm;
    for(auto c : s) mm[c]++;
    for(int i = 0; i<q; i++) {
        int c; cin>>c;
        int ans = 0;
        for(auto itr : mm) ans+=max(0,itr.second-c);
        cout<<ans<<endl;
    }
}

int main() {
    int t; cin>>t;
    while(t--) {
        solve();
    }
}