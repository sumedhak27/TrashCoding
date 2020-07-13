#include <iostream>
using namespace std;

void solve() {
    int n, q; cin>>n>>q;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    pair<int,int> lines[n-1];
    for(int i =0; i<n-1; i++)
        lines[i] = {arr[i], arr[i+1]};
    for(int i = 0 ; i<q; i++) {
        int counter = 0;
        int x1, x2, y; cin>>x1>>x2>>y;
        for(int j = x1-1; j<x2-1; j++) {
            int mini = min(lines[j].first, lines[j].second), maxi = max(lines[j].first, lines[j].second); 
            if((mini < y && y < maxi) || y == lines[j].second || (y == lines[j].first && j == x1-1))
                counter++;
        }
        cout<<counter<<endl;
    }
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