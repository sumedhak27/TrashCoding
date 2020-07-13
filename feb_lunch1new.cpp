#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    char arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    int j = n-1, counter = 0;
    while(j>=0 && counter<k) {
        if(arr[j] == 'H') {
            for(int i = 0; i<j; i++) {
                if(arr[i] == 'H') arr[i] = 'T';
                else arr[i] = 'H';
            }
        }
        counter++;
        j--;
    }
    cout<<count(arr, arr+(n-k), 'H')<<endl;
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