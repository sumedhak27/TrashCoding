#include <iostream>
typedef long long int ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        ll n, k;
        cin>>n>>k;
        ll arr[n], give[n], take[n];
        for(ll i = 0; i<n; i++) {
            cin>>arr[i];
            give[i] = arr[i]%k;
            give[i]!=0 ? take[i] = k - give[i] : take[i] = 0;
        }
        // for(int i : arr) cout<<i<<" ";
        // cout<<endl;
        // for(int i : give) cout<<i<<" ";
        // cout<<endl;
        // for(int i : take) cout<<i<<" ";
        // cout<<endl;
        ll b =0, e = n-1;
        ll r = 0;
        while(b<=e) {
            if(take[e] > r) r+=give[b++];
            else if(take[e] <= r) {
                r-=take[e];
                take[e] = 0; give[e--] = 0;
                // if(b == e) break;
            }
        }
        cout<<r<<endl;
    }

    return 0;
}
