#include <bits/stdc++.h>
using namespace std;

int rangeand(int m, int n) {
    if( m == 0 ) return 0;
    int ans = m;
    if(floor(log2(m)) != floor(log2(n))) return 0;
    for(int i = m+1; i<=n; i++) ans&=i;
    return ans;
}

int main() {
    
    cout<<rangeand(20000, 2147483647);
}