#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll x, y;
vector<string> ans;
vector<vector<string>> dp;

bool compare(string& s1, string & s2) {
    return s1.size() < s2.size();
}

bool recf(ll i, ll j, string c_s, ll cstep, ll csum) {
    if(i == x && j == y) {ans.push_back(c_s); return 1;}
    //cout<<"test : "<<x<<" "<<y<<endl;
    if(csum > abs(x)+abs(y)) return 0;
    if(dp[i][j]!="") {ans.push_back(c_s+dp[i][j]); return 1;}

    bool b1 = recf(i, j-cstep, c_s+"S", cstep*2, csum+cstep);
    if(b1 && (dp[i][j]=="" || dp[i][j].length() > (ans[ans.size()-1].length() - c_s.length()))) dp[i][j] = ans[ans.size()-1].substr(c_s.length());
    bool b2 = recf(i+cstep, j, c_s+"E", cstep*2, csum+cstep);
    if(b2 && (dp[i][j]=="" || dp[i][j].length() > (ans[ans.size()-1].length() - c_s.length()))) dp[i][j] = ans[ans.size()-1].substr(c_s.length());
    bool b3 = recf(i-cstep, j, c_s+"W", cstep*2, csum+cstep);
    if(b3 && (dp[i][j]=="" || dp[i][j].length() > (ans[ans.size()-1].length() - c_s.length()))) dp[i][j] = ans[ans.size()-1].substr(c_s.length());
    bool b4 = recf(i, j+cstep, c_s+"N", cstep*2, csum+cstep);
    if(b4 && (dp[i][j]=="" || dp[i][j].length() > (ans[ans.size()-1].length() - c_s.length()))) dp[i][j] = ans[ans.size()-1].substr(c_s.length());
}

void solve(int tcn) {
    x, y; cin>>x>>y;
    dp.resize(x, vector<string>(y,""));
    recf(0, 0, "", 1, 0);
    sort(ans.begin(), ans.end(), compare);
    string answer = ans.size()==0 ? "IMPOSSIBLE" : ans[0];
    cout<<"Case #"<<tcn<<": "<<answer<<endl;
    ans.clear();
    dp.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t; cin>>t;
    for(int i =0; i<t; i++) 
        solve(i+1);
    return 0;
}

