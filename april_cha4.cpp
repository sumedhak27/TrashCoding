#include <bits/stdc++.h>
using namespace std;
const int N = 200;
vector<bool> is_prime(N, true);

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve() {
    int n; cin>>n;
    int countn = 1, counts = 1;
    vector<bool> done(n+1,true);
    
    for(int i = 2; i<=N; i++) {
        if(is_prime[i] || done[i]) 
    }
}

int main() {
    is_prime[0] = 0; is_prime[1] = 0;
    for(int i = 2; i*i < N; i++){
        if(is_prime[i]) {
            for(int j = i*2; j<N; j+=i)
                is_prime[j] = 0;
        }
    }

    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}