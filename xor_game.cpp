#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int a[n];
        unordered_map<int,int> b;
        int xor_val = 0;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            xor_val^=a[i];
        }
        for(int i = 0; i<n; i++) {
            int temp; cin>>temp;
            b[temp]++;
            xor_val^=temp;
        }
        int ans[n] = {-1}, ind = 0;
        bool flag = false;
        for(int i : a) {
            int search_val = xor_val^i;
            if(b[search_val] > 0){
                b[search_val]--;
                ans[ind++] = search_val;
            }
            else {
                flag = 1;
                cout<<-1<<endl;
                break;
            }
        }
        if(!flag) {
            for(int i : ans) cout<<i<<" ";
            cout<<endl;
        }
    }
}