#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<pair<int, int>> op;
        int start = -1, end = -1;
        for(int i = 0; i<n; i++) {
            int num; cin>>num;
            if(start == -1) {
                if(num == 1){
                    start = i;
                    end = i;
                }
            }
            else {
                if(num == 1) end = i;
                else {
                    op.push_back({start, end});
                    start = -1;
                }
            }
        }
        // for(auto& p : op) cout<<p.first<<","<<p.second<<"\t";
        // cout<<endl;
        int ans = 0;
        /*
        for(int i = 0; i<op.size(); i++) {
            int subt = op[(i+(op.size()-1))%op.size()].second - op[i].first;
            cout<<"test : "<<subt<<endl;
            if(subt == 0) ans = 0;
            else if(subt>0) ans = min(ans, subt-1);
            else ans = min(ans, n+subt);
        }
        */
        for(int i = 0; i<op.size(); i++) {
            if(op[i].first == op[i].second) {
                int diff1 = op[i].first - op[i==0? op.size()-1 : i-1].second;
                int diff2 = op[(i+1)%op.size()].first - op[i].second; 
                if(diff1<0) diff1+=n;
                if(diff2<0) diff2+=n;
                ans+=min(diff1,diff2);    
            }
            else ans+=(op[i].second - op[i].first);
        }
        cout<<ans<<"\n";
    }
}