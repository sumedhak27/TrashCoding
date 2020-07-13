#include <iostream>
#include <algorithm>

using namespace std;

void solve() {  
    int n; cin>>n;
    int arr[n];
    for(int i =0 ;i< n; i++) cin>>arr[i];
    reverse(arr,arr+n);
    for(int i : arr) cout<<i<<" "; 
    cout<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}