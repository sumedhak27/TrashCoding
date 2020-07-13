#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n; cin>>n;
        int a = 0,b = 0, cla = n, clb = n;
        string s; cin>>s;
        int i;
        for( i = 0 ; i < s.length(); i++) {
            if(i&1) {
                if(s[i] == '1') 
                    b++; 
                clb--;
            }
            else {
                if(s[i] == '1')
                    a++;
                cla--;
            }
            // cout<<i<<" "<<a<<" "<<b<<endl;
            if((clb + b) < a) {i++; break;}
            if((cla + a) < b) {i++; break;}
        }
        // cout<<a<<b<<endl;
        cout<<i<<endl;
    }
    return 0;
}
