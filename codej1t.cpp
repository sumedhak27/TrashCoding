#include <bits/stdc++.h>
using namespace std;

void solve(int tcn) {
    int n; cin>>n;
    string lms, rms, ms = lms+rms;
    cin>>ms;
    int ap1 = ms.find_first_of("*");
    int ap2 = ms.find_last_of("*");
    lms = ms.substr(0, ap1);
    rms = ms.substr(ap2+1);
    // cout<<"### "<<lms<<" "<<rms<<endl;
    for(int i = 1; i<n; i++) {
        string s; cin>>s;
        int tap1 = s.find_first_of("*");
        int tap2  = s.find_last_of("*");
        string tlms = s.substr(0, tap1);
        string trms = s.substr(tap2+1);
        // cout<<"### "<<tlms<<" "<<trms<<endl;
        if(tlms == "");
        else if(tlms.length() >= lms.length()) {
            // cout<<" ## "<<tlms.substr(0,lms.length())<<" "<<lms<<endl;
            if(tlms.substr(0,lms.length()) == lms) lms = tlms;
            else { lms = "*"; break;}
        }
        else {
            // cout<<" ## "<<lms.substr(0,tlms.length())<<" "<<tlms<<endl;
            if(lms.substr(0,tlms.length()) == tlms);
            else { lms = "*"; break;}
        }
        if(trms == "");
        else if(trms.length() >= rms.length()) {
            // cout<<" ## "<<trms.substr(trms.length()-rms.length())<<" "<<rms<<endl;
            if(trms.substr(trms.length()-rms.length()) == rms) rms = trms;
            else { rms = "*"; break; }
        }
        else {
            // cout<<" ## "<<rms.substr(rms.length()-trms.length())<<" "<<trms<<endl;
            if(rms.substr(rms.length()-trms.length()) == trms);
            else { rms = "*"; break;}
        }
    }
    if(lms!="*" && rms!="*") ms = lms+rms;
    else ms = "*";
    cout<<"Case #"<<tcn<<": "<<ms<<endl;
}

int main() {    
    int t; cin>>t;
    for(int i = 1; i<=t; i++)
        solve(i);
    return 0;
}