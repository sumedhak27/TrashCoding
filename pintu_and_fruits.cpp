#include <iostream>
#include <unordered_map>
using namespace std;

void solve() {
    int n, m;
    cin>>n>>m;
    int f[n], p[n];
    for(int i = 0 ; i< n; i++) cin>>f[i];
    for(int i = 0 ; i< n; i++) cin>>p[i];
    unordered_map<int,int> tp;
    for(int i = 0 ; i<n; i++) tp[f[i]]+=p[i];
    int mintp = INT32_MAX;
    for(auto itr = tp.begin(); itr != tp.end(); itr++){
        if(itr->second < mintp) {
            mintp = itr->second;
        }
    }
    cout<<mintp<<endl;    
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