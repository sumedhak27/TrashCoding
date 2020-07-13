#include <iostream>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, p;
        cin>>n>>p;
        int arr[n] = {0};
        int ans[n] = {0};
        for(int i = 0; i<n; i++) {
            cin>>arr[i];
        }
        bool  b = true; int max_ind = 0;
        for(int i =0 ; i<n; i++) {
            if(p%arr[i] == 0) continue;
            else {
                b = false;
                max_ind = i;
            } 
        }
        ans[max_ind]+= (p/arr[max_ind])+1;
        if(b) cout<<"NO"<<endl;
        else {
            cout<<"YES ";
            for(int i:ans) cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}