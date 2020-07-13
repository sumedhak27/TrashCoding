#include <bits/stdc++.h>
using namespace std;

struct Time {
    int st, et; 
    bool operator <(const Time& t) const {
        return this->st < t.st;
    }
};

void solve(int i) {
    multimap<Time, int> mm;
    int n; cin>>n;
    string ans;
    ans.resize(n);
    for(int i = 0; i<n; i++) {
        int st, et; cin>>st>>et;
        mm.insert({{st, et}, i});
    }
    // for(auto itr : mm) {
    //     cout<<itr.first.st<<" "<<itr.first.et<<endl;
    // }
    int c = 0, j = 0;
    for(auto itr : mm) {
        if(itr.first.st >= c) {
            c = itr.first.et;
            ans[itr.second] = 'C';
        }
        else if(itr.first.st >= j) {
            j = itr.first.et;
            ans[itr.second] = 'J';
        }
        else {
            ans = "IMPOSSIBLE";
            break;
        }
    }
    ans.shrink_to_fit();
    cout<<"Case #"<<i<<": "<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t; cin>>t;
    for(int i = 0; i<t; i++) 
        solve(i+1);
    return 0;
}