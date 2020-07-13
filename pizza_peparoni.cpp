#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int n; cin>>n;
    int mat[n][2] = {0};
    int p1 = 0, p2 = 0;
    string arr[n];
    for(int i = 0 ; i < n; i++){
        int rp1 = 0,rp2 = 0;
        string s; cin>>s;
        arr[i] = s;
        for(int i = 0; i<n; i++) {
            if(i < n/2)
                rp1+=(int)s[i]-'0';
            else 
                rp2+=(int)s[i]-'0'; 
        }
        mat[i][0] = rp1; mat[i][1] = rp2;
        p1+=rp1; p2+=rp2;
    }
    // for(int i = 0; i<n; i++){
    //     cout<<mat[i][0]<<" "<<mat[i][1]<<endl;
    // }
    int diff = p1-p2, rdiff = diff/2;
    for(int i = 0; i<n; i++){
        if(mat[i][0]-mat[i][1] == rdiff) {
            reverse(begin(arr[i]),end(arr[i]));
            p1-=rdiff; p2+=rdiff;
            diff = p1-p2;
            rdiff = diff/2;
            if(rdiff == 0) break;
        }
    }
    for(string s : arr) cout<<s<<endl;

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