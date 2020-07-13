#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, p;
        cin>>n>>p;
        int arr[n] = {0};
        int ans[n] = {0};
        bool b = true;
        for(int i = 0; i<n; i++) {
           cin>>arr[i];
           if(p%arr[i]!=0) b = false;
        }
        if(b == true) {cout<<"NO"<<endl; continue;}
        // for(int i = 0; i<n; i++) cout<<"test : "<<arr[i]<<" ";
        int min_nd_ind = INT32_MAX, min_d_ind = INT32_MAX, cur_p = p;
        int cur_sum = 0;
        for(int i = n-1; i>=0; i--) {
            if(p%arr[i] != 0) {
                ans[i]+=(cur_p/arr[i]);
                b = false;
                cur_p-=arr[i]*ans[i];
                cur_sum+=arr[i]*ans[i];
                min_nd_ind = min(min_nd_ind, i);
            }
            else {
                ans[i]+=(cur_p/arr[i])-1;
                cur_p-=arr[i]*ans[i];
                min_d_ind = min(min_d_ind, i);
                cur_sum+=arr[i]*ans[i];
            }
        }
        ans[min_nd_ind]++;
        cur_sum+=arr[min_nd_ind]*ans[min_nd_ind];
        while(cur_sum > p){
            cur_sum-=arr[min_d_ind];
            ans[min_d_ind]--;
        }
        ans[min_d_ind]++;
        cout<<"YES ";
        for(int i : ans) cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}