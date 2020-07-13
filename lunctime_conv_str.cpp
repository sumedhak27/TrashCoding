#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string s1, s2;
        cin>>s1>>s2;
        unordered_map<char, set<int>> charind;
        unordered_map<char, set<int>> replace;
        bool poss = 1;
        for(int i = 0; i<n; i++) 
            charind[s1[i]].insert(i);
        for(int i = 0; i<n; i++) {
            if(s1[i] == s2[i]) continue;
            else{
                if(s1[i]<s2[i] || charind.find(s2[i])==charind.end()) {
                    poss = 0;
                    break;
                }
                replace[s2[i]].insert(i);
            }
        }
        if(!poss)  cout<<"-1\n";
        else {
            cout<<replace.size()<<"\n";
            for(auto& itr: replace) {
                for(auto& ind : charind[itr.first]) {
                    itr.second.insert(ind);
                }
                //itr.second.insert(charind[itr.first]);
                cout<<itr.second.size()<<" ";
                for(auto& num: itr.second) cout<<num<<" ";
                cout<<endl;
            }
        }

    }
}