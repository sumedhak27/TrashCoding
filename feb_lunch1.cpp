#include <iostream>
using namespace std;

void solve() {
    int n,k; 
    cin>>n>>k;
    int n_of_heads_before_k = 0;
    int n_of_heads_after_k = 0;
    char inp[n+1];
    for(int i = 1; i<=n; i++) {
        cin>>inp[i];
    }
    for(int i=n; i>0; i--) {
        if(inp[i] == 'H' && i>(n-k)) n_of_heads_before_k++;
        else if(inp[i] == 'H' && i<=(n-k)) n_of_heads_after_k++;
        // cout<<"test : "<<n_of_heads_before_k<<" "<<n_of_heads_after_k<<endl;
    }
    if(n_of_heads_before_k%2 == 0) cout<<n_of_heads_after_k<<endl;
    else cout<<n-k-n_of_heads_after_k<<endl;
    
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