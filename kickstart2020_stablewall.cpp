#include <bits/stdc++.h>
using namespace std;


void printmap(unordered_map<char, unordered_set<char>>& mp) {
    for(auto itr : mp) {
        cout<<itr.first<<" : ";
        if(itr.second.empty()) cout<<" empty";
        for(auto c : itr.second)
            cout<<c<<" ";
        cout<<endl;
    }
}

string solve() {
    string ans = "";
    int r,c; cin>>r>>c;
    vector<string> wall;
    wall.resize(r);
    unordered_map<char, unordered_set<char>> mp;
    for(int i = 0; i<r; i++) cin>>wall[i];
    for(int i = 0; i<r-1; i++) {
        for(int j = 0; j<c; j++) {
            if(mp.find(wall[i][j]) == mp.end()) 
                mp[wall[i][j]] = unordered_set<char>();
            if(wall[i][j] != wall[i+1][j])
                mp[wall[i][j]].insert(wall[i+1][j]);
        }
    }

    while(!mp.empty()) {
        char cc = 'a';
        // printmap(mp);
        for(auto itr : mp) {
            if(itr.second.empty()) {
                cc = itr.first;
                break;
            }
        }
        // cout<<"cc : "<<cc<<endl;
        if(cc == 'a') return "-1";
        mp.erase(cc);
        for(auto& itr : mp) {
            if(itr.second.find(cc)!=itr.second.end()) 
                itr.second.erase(cc);
        }   
        ans.push_back(cc);
    }
    return ans;
}

int main() {
    int t; cin>>t;
    for(int i = 0; i<t; i++) {
        cout<<"Case #"<<i+1<<": "<<solve()<<endl; 
    }
    return 0;
}