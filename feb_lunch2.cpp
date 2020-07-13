#include <iostream>
#include <map>
using namespace std;

void solve() {
   int n,k;
   cin>>n>>k;
   int arr[n];
   map<int, int> counts;
   for(int i = 0 ; i<n; i++) cin>>arr[i];
   int max_length = 0, curr_length = 0, start_i = 0, curr_dn = 0;
   for(int i = 0 ; i<=n; i++){
       if(counts.size() < k) {
            counts[arr[i]]++;
            curr_length++;
       }
       if(counts.size() == k) {
           max_length = max(max_length, curr_length-1);
           while(counts.size() == k){
               counts[arr[start_i]]--;
               if(counts[arr[start_i]] == 0) counts.erase(arr[start_i]);
               start_i++;
               curr_length--;
           }
       }
   }
    max_length = max(max_length, curr_length-1);
    cout<<max_length<<endl;
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