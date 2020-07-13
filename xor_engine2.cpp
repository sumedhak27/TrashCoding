#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long int ll;

void solve() {
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    unordered_map<int, unordered_set<int> > mm;
    int num1s[n] = {0};
    for(int i = 0 ; i<n; i++) {
        int temp = arr[i];
        if(mm[arr[i]].size()==0) {
            int j = 0;
            do {
                if(temp & 1) mm[arr[i]].insert(j);
                j++;
            } while (temp>>=1);
        }
        num1s[i] = mm[arr[i]].size();
    }
    for(int i = 0; i<q; i++) {
        int p; cin>>p;
        int temp = p;
        int j = 0;
        do {
            if(temp & 1) mm[p].insert(j);
            j++;
        } while (temp>>=1);
        int evenc = 0,oddc = 0;
        for(int j = 0; j < n; j++) {
            int matched = 0, unmatched = 0;
            for(auto itr = mm[p].begin(); itr!=mm[p].end(); itr++) {
                if(mm[arr[j]].find(*itr)!=mm[arr[j]].end()) matched++;
                else unmatched++;
            }
            if((num1s[j]+unmatched-matched) & 1) oddc++;
            else evenc++;
        }
        
        cout<<evenc<<" "<<oddc<<endl;
    }
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