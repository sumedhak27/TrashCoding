#include<bits/stdc++.h>
const long long int M = 1e9+7;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++) cin>>arr[i];
        sort(arr, arr+n, greater<int>());
        long long int sum = 0;
        for(int i = 0; i<n; i++) {
            if(arr[i] - i <=0 ) break;
            sum+= (arr[i] - i);
            sum%=M;
        }
        cout<<sum%M<<"\n";
    }
    return 0;
}