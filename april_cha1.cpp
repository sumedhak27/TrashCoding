#include<iostream>
using namespace std;
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int max_ind = -6;
        bool flag = 0;
        for(int i = 0; i<n; i++) {
            int temp; cin>>temp;
            if(temp == 1) {
                if(i-max_ind < 6) { flag = 1; cout<<"NO"<<endl; break;}
                max_ind  = i;
            } 
        }
        if(!flag) cout<<"YES"<<endl;
    }
    return 0;
}