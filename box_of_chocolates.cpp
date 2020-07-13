#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    int arr[n], maxi = INT32_MIN, ans = 0;
    vector<int> inds;
    for(int i = 0; i<n; i++) {cin>>arr[i]; maxi = max(maxi, arr[i]);}
    for(int i = 0; i<n; i++) 
        if(arr[i] == maxi) inds.push_back(i);
    sort(inds.begin(), inds.end());
    // if(inds.size() == 1) {
    //     if(inds[0] < n/2) ans = n/2;
    //     else ans = n-inds[0]+1;
    // }
    // else {
    //     int si = inds[0], ei = inds[inds.size()-1];
    //     ans = min((n/2)-1-si, n-1-ei);
    // }
    cout<<max((inds.back()- inds[0]) , 0)<<endl;
    // cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}