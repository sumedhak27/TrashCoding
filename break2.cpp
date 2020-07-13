#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll a[100005],b[100005],c[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,h;
    cin >> t >> h;
    while(t--){
        ll i,j,k,n,v=1,w=1, temp=0, mini=1000000000000;
        cin>>n;

        for( i=0;i<n;i++){
            cin>>a[i];
            if(i>0 && a[i]!=a[i-1])
            v=0;
            mini=min(mini,a[i]);
        }

        for( i=0;i<n;i++){
            cin>>b[i];
            temp=max(temp,b[i]);
                if(i>0 && b[i]!=b[i-1])
                w=0;
        }

        sort(a,a+n);
        sort(b,b+n);
        i=0;k=0;
        set<ll>s;
        s.insert(a[0]);
        s.insert(b[0]);
        if(h==1){
            while(a[i]<b[i] && i!=n && s.count(a[i])){
                s.insert(a[i]);
                s.insert(b[i]);
                i++;
            }
            if(i==n)
                cout<<"YES"<<endl;
            
            else
                cout<<"NO"<<endl;   
        }
        else{
            if(n==2 &&( max(a[0],a[1])< min(b[0],b[1])|| min(a[0],a[1])>=max(b[0],b[1]) )){
                cout<<"NO"<<endl;
                continue ;	
            }

            while(a[i]<b[i]&& i!=n && s.count(a[i])){
                s.insert(a[i]);
                s.insert(b[i]);
                i++;
            }
            if(i==n){
                cout<<"YES"<<endl;
            
            }
            else{
                
                k=2*n;

                ll maxi= 0;
                for( i=0;i<n;i++){
                    c[i]=a[i];
                    c[n+i]=b[i];
                }
                sort(c,c+k);
                i=0;
            
                ll  cnt=1;
                for( i=0;i<2*n-1;i++){
                    ll cnt=1;
                    while(c[i]==c[i+1] && i!=2*n-1){
                        cnt++;
                        i++;
                    }
                    maxi = max(maxi,cnt);
                }
                
            
                if(maxi>k-maxi)
                    cout << "NO" << endl;
                else{
                    if(v && a[0]>=temp)
                        cout << "NO" << endl;
                    else if(w && b[0]<=mini)
                        cout << "NO" << endl;
                    else
                        cout << "YES" << endl;
                }
            }
        }
    }
    return 0;
}