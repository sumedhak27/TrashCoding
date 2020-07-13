#include <iostream>
using namespace std;

void solve(int i) {
    string ans = "";
    string s; cin>>s;
    int obc = 0;
    for(int i = 0; i<s.length(); i++) {
        int digit = (int)s[i] - '0';
        if(obc<digit) {
            for(int j = 0; j<digit-obc; j++) {
                ans.push_back('(');
            }
            obc+=(digit-obc);
        }
        else if(obc>digit) {
            for(int j = 0; j<obc-digit; j++) {
                ans.push_back(')');
            }
            obc-= (obc-digit);
        }
        ans.push_back((char)digit+'0');
    }
    while(obc--) ans.push_back(')');
    cout<<"Case #"<<i<<": "<<ans<<endl;
}

int main() {
        
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t; cin>>t;
    for(int i = 1; i<=t; i++)
        solve(i);
    return 0;
}