#include<bits/stdc++.h>
using namespace std;

void solve(int tcn) {
    int n, d; cin>>n>>d;
    int mind = d;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    for(int i = n-1; i>=0; i--) {
        int j = -1, temp;
        do{
            j++;
            temp = ((d/arr[i])-j)*arr[i];
        }while(mind<temp);
        mind = temp;
    }
    cout<<"Case #"<<tcn+1<<": "<<mind<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    for(int i = 0; i<t; i++)
        solve(i);
}