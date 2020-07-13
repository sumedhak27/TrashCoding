#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    multiset<int> att, def;
    for(int i = 0; i<n; i++) {
        int temp; cin>>temp;
        att.insert(temp);
    }
    for(int i = 0; i<n; i++) {
        int temp; cin>>temp;
        def.insert(temp);
    }
    set<int> thirdset;
    bool flag = 0;
    int an = *att.begin();
    int dn = *def.begin();
    if(dn > an)
        thirdset.insert(an); thirdset.insert(dn);
    for(int i =0 ; i<n; i++){
        an = *att.begin();
        dn = *att.begin();
        if(dn > an && thirdset.count(an)) {
            att.erase(att.begin());
            def.erase(def.begin());
            thirdset.insert(an); thirdset.insert(dn);
        }
        else {
            flag = 1;
            break;
        }
    }
    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t, s; cin>>t>>s;
    if(s == 1)
        while(t--) 
            solve();
    return 0;
}