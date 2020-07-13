#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n; cin>>n;
    int arr[n];
    unordered_map<int, int> m;
    for(int i = 0; i<n; i++) {cin>>arr[i];}
    for(int i = 1; i<n; i++) {arr[i]+=arr[i-1];}
    for(int i = 0; i<n; i++) m[arr[i]]++; 
    int ans = 0;
    for(int i = n-1; i>=0; i--) {
        double sr = sqrt(arr[i]);
        if(floor(sr) == ceil(sr)) ans++;
        for(int ntf = floor(sr); ntf>=0; ntf--) {
            if(m.find(arr[i] - ntf*ntf)!=m.end()){
                ans+=m[arr[i] - ntf*ntf];
                if(ntf == 0) {
                    ans--;
                    m[arr[i] - ntf*ntf]--;
                }
            } 
        }
    }
    return ans;
}

int main() {
    int t; cin>>t;
    for(int i = 0; i<t; i++) {
        cout<<"Case #"<<i+1<<": "<<solve()<<endl; 
    }
    return 0;
}