#include <iostream>
using namespace std;

void solve() {
    int n; cin>>n;
    char axis = 'z';
    string s;
    cin>>s;
    int i = 0, j = 0;
    for(char c: s) {
        if(c=='L' && axis!='x') {i--; axis = 'x';}
        else if(c=='R' && axis!='x') {i++; axis = 'x';}
        else if(c=='U' && axis!='y') {j++; axis = 'y';}
        else if(c=='D' && axis!='y') {j--; axis = 'y';}
    }
    cout<<i<<" "<<j<<endl;
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