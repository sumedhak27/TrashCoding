#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    string origin; cin>>origin;
    int min_ra = (origin=="INDIAN"? 200 : 400);
    int laddus = 0;
    cin.ignore();
    for(int i = 0; i<n; i++) {
        string s; getline(cin,s);
        istringstream ss(s);
        string act; int ros;
        ss>>act;
        if(ss) ss>>ros;
        if(act=="CONTEST_WON") laddus+=(300 + max(0,20-ros));
        else if(act=="TOP_CONTRIBUTOR") laddus+=300;
        else if(act=="BUG_FOUND") laddus+=ros;
        else laddus+=50;
        // cout<<laddus<<endl;
    }
    cout<<laddus/min_ra<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}