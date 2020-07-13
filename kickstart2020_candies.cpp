#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll* bit1, *bit2;

ll get_sum(ll arr[], ll i) {
    ll sum = 0;
    while(i>0) {
        sum+=arr[i];
        i-= i&(-i);
    }
    return sum;
}

void addinto_bit1(ll arr[], ll i, ll val, ll n) {
    i++;
    bool add = i&1?1:0;
    while(i<n+1) {
        if(add)
            arr[i]+=val;
        else
            arr[i]-=val;
        i+= i&(-i);
    }
}

void addinto_bit2(ll arr[], ll i, ll val, ll n) {
    ll multiplier = ++i;
    bool add = i&1?1:0;
    while(i<n+1) {
        if(add)
            arr[i]+=(val*multiplier);
        else
            arr[i]-=(val*multiplier);
        i+= i&(-i);
    }
}

int solve() {
    ll n, q; cin>>n>>q;
    bit1 = new ll[n+1];
    bit2 = new ll[n+1];
    memset(bit1, 0, (n+1)*sizeof(ll));
    memset(bit2, 0, (n+1)*sizeof(ll));
    for(ll i = 0; i<n; i++) {
        ll t; cin>>t;
        addinto_bit1(bit1, i, t, n);
        addinto_bit2(bit2, i, t, n);
    }

    ll ret_val = 0;
    for(ll i = 0; i<q; i++) {
        char uqc; ll n1,n2; cin>>uqc>>n1>>n2;
        if(uqc == 'Q') {
            ll cans = 0;
            ll mul = 1;
            if(!(n1&1)) mul=-1;
            if(n1==n2) 
                cans = get_sum(bit1, n2) - get_sum(bit1, n1-1); 
            else
                cans = get_sum(bit2, n2) - get_sum(bit2, n1-1) - (n1-1)*(get_sum(bit1, n2) - get_sum(bit1, n1-1));
            // cout<<endl<<"query : "<<mul*cans<<endl;
            ret_val+=(mul*cans); 
        }
        else {
            ll mul = 1;
            if(!(n1&1)) mul=-1;
            ll old_val = mul*(get_sum(bit1, n1) - get_sum(bit1, n1-1));
            addinto_bit1(bit1, n1-1, n2-old_val, n);
            addinto_bit2(bit2, n1-1, n2-old_val, n);
            // ll new_val = mul*(get_sum(bit1, n1) - get_sum(bit1, n1-1));
            // cout<<"update : "<<old_val<<", "<<new_val<<endl;
        }

    }
    return ret_val;
}

int main() {
    int t; cin>>t;
    for(int i = 1; i<=t; i++) 
        cout<<"Case #"<<i<<": "<<solve()<<endl;
}