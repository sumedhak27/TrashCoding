#include <bits/stdc++.h>
using namespace std;

void solve(int i) {
    int n; cin>>n;
    int k = 0, r = 0, c = 0;
    int arr[n][n];
    unordered_map<int, int> mm;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cin>>arr[i][j];
            if(i==j) k+=arr[i][j];
        }
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            mm[arr[i][j]]++;
            if(mm[arr[j][i]] > 1) { cout<<"test : "<<mm[arr[i][j]]<<endl; r++; break;}
        }
        mm.clear();
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            mm[arr[j][i]]++;
            if(mm[arr[j][i]] > 1) {c++; break;}
        }
        mm.clear();
    }
    cout<<"Case #"<<i<<": "<<k<<" "<<r<<" "<<c<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t; cin>>t;
    for(int i = 1 ; i<=t; i++) 
        solve(i);
    return 0;
}