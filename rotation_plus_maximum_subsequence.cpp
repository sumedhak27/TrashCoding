#include <iostream>
#include <deque>
using namespace std;

void function(deque<int> arr) {
    int n = arr.size(), j = n;
    do {
        int global_max = arr[0], curr_max = arr[0];  
        for(int i = 1; i<n; i++) {
            curr_max = max(arr[i], curr_max+arr[i]);
            if(curr_max > global_max) global_max = curr_max;
        }
        cout<<global_max<<" ";
        int remomed = arr.front();
        arr.pop_front();
        arr.push_back(remomed);
    }while(--j);
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        deque<int> arr(n);
        for(int i = 0; i<n; i++) cin>>arr[i];
        // for(int i : arr) cout<<i<<" ";
        // cout<<endl;
        function(arr);
    }
    return 0;
}