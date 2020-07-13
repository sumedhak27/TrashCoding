#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int size = 1e5;
int arr[size], mm[2*100*size+1];

ll solve() {
    int n;
    cin>>n;
    memset(mm, 0, 2*100*size+1);
    for(int i = 0; i<n; i++) cin>>arr[i];
    // unordered_map<int, int> mm;
    int lsum = 0, hsum = 0;
    for(int i = 0; i<n; i++) arr[i]<0 ? lsum-=arr[i] : hsum+=arr[i];
    mm[lsum]++;
    ll presum = 0, ans = 0;
    for(int i = 0; i<n; i++) {
        presum+=arr[i];
        for(int j = 0; j*j<=hsum && presum-j*j>=-lsum; j++) {
            ans+=mm[lsum+(presum-j*j)]; 
        }
        mm[lsum+presum]++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    for(int i = 1; i<=t; i++)
        cout<<"Case #"<<i<<": "<<solve()<<endl;
}