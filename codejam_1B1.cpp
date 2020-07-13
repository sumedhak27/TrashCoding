#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    int T;
    T = t;
    
    while(t--){
        long long int x;
        long long int y;
        
        cin>>x>>y;
        
        if(((abs(x) + abs(y)) & 1) == 0)
            cout << "Case #" << T - t << ": IMPOSSIBLE"<<endl; 
        else{
            int steps = floor(log2((abs(x) + abs(y))));
            int stepVal = (1 << steps);
            
            string ans = ""; 
            for(int i=steps; i>=0; i--){
                if(abs(x) > abs(y)){
                    if(x > 0){
                        x -= stepVal;
                        ans += "E";
                    } else {
                        x += stepVal;
                        ans += "W";
                    }
                } else {
                    if(y > 0){
                        y -= stepVal;
                        ans += "N";
                    } else {
                        y += stepVal;
                        ans += "S";
                    }
                }
                
                stepVal /= 2;
                
            }
            
            reverse(ans.begin(), ans.end());
            
            cout << "Case #" << T - t << ": " << ans<<endl; 
            
        }
    }
    
    return 0;
}