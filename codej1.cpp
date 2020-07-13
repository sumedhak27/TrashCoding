#include <bits/stdc++.h>

using namespace std;

void solve(int tcn) {
    int n; cin>>n;
    int max_length = 0;
    string max_string;
    cin>>max_string;
    int i = 1;
    for(i = 1; i<n; i++) {
        string s; cin>>s;
        if(s.length() >= max_string.length()) {
            // cout<<"test : "<<s.substr(s.length()-max_string.length()+1, max_string.length()-1)<<endl;
            if("*" + s.substr(s.length()-max_string.length()+1, max_string.length()-1) == max_string) {
                max_string = s;
            }
            else {
                max_string = "*"; break;
            }
        }
        else {
            // cout<<"test 2 : "<<max_string.substr(max_string.length()+1-s.length(), s.length()-1)<<endl;
            if("*" + max_string.substr(max_string.length()-s.length()+1, s.length()-1) == s);
            else {
                max_string = "*"; break;
            }
        }
    }
    i++;
    if(max_string == "*") {
        for(;i<n;i++) {
            string s; cin>>s;
        }
    }
    else max_string = max_string.substr(1,max_string.length()-1);
    
    
    cout<<"Case #"<<tcn<<": "<<max_string<<endl;
}

int main() {
    int t; cin>>t;
    for(int i = 1; i<=t; i++)
        solve(i);
    return 0;
}