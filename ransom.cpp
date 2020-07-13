#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++) cin>>arr[i];
        int gmax = INT32_MIN, gmin = INT32_MAX, ccount = 1;
        for(int i = 0; i<n-1; i++) {
            if(arr[i+1]-arr[i]<=2) ccount++;
            else {
                gmax = max(gmax,ccount);
                gmin = min(gmin, ccount);
                ccount=1;
            }      
        }
        gmax = max(gmax,ccount);
        gmin = min(gmin, ccount);
        cout<<gmin<<" "<<gmax<<endl;
    }
    return 0;
}