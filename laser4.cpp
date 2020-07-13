#include <iostream>
using namespace std;

void solve() {
    int n, q; cin>>n>>q;
    int arr[n], ymin = INT32_MAX, ymax = INT32_MIN;
    for(int i = 0; i<n; i++) { 
        cin>>arr[i];
        ymin = min(ymin, arr[i]);
        ymax = max(ymax, arr[i]);
    }
    pair<int,int> lines[n-1];
    for(int i =0; i<n-1; i++)
        lines[i] = {arr[i], arr[i+1]};
    int* mat[ymax+1];
    for(int i = ymin; i<=ymax; i++) {
        mat[i] = new int[n-1];
        int counter = 0;
        for(int j = 0; j<n-1; j++) {
            int mini = min(lines[j].first, lines[j].second), maxi = max(lines[j].first, lines[j].second); 
            if((mini < i && i < maxi) || i == lines[j].second || (i == lines[j].first && j == 0))
                counter++;
            mat[i][j] = counter;
        }
    }    
    // for(int i = ymin; i<=ymax; i++) {
    //     cout<<i<<" -> ";
    //     for(int j = 0; j<n-1; j++)
    //         cout<<mat[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i = 0 ; i<q; i++) {
        int x1, x2, y; cin>>x1>>x2>>y;
        if(y>ymax) cout<<0<<endl;
        else cout<<mat[y][x2-2] - (x1-2 >= 0 ? mat[y][x1-2] : 0)<<endl;
    }
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