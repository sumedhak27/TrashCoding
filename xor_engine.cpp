#include <iostream>
using namespace std;
typedef long long int ll;

bool is_odd[100000001];

void solve() {
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    for(int i = 0; i<q; i++) {
        int p; cin>>p;
        int evenc = 0,oddc = 0;
        // for(int j = 0; j<n; j++) {
        //     if(is_odd[ (p ^ arr[j]) ]) oddc++;
        //     else evenc++;
        // }
        for(int j = 0; j<n; j++) {
            if( __builtin_parity(p ^ arr[j])) oddc++;
            else evenc++;
        }
        cout<<evenc<<" "<<oddc<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    // for(ll i = 0 ; i<100000000; i++) {
    //     is_odd[i] = __builtin_parity(i);
    // }
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}