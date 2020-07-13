#include <iostream>
#include <set>
using namespace std;

void solve() {
    int n, q; cin>>n>>q;
    int ypnts[n];
    set<int> s_ypnts;
    for(int i = 0; i<n; i++) { 
        cin>>ypnts[i]; 
        s_ypnts.insert(ypnts[i]);
    }
    int s_y_arr[s_ypnts.size()], k = 0;
    for(auto itr = s_ypnts.begin(); itr!=s_ypnts.end(); itr++) s_y_arr[k++] = *itr;  
    pair<int,int> lines[n-1];
    for(int i = 0; i<n-1; i++)
        lines[i] = {ypnts[i], ypnts[i+1]};
    int* arrpnt[s_ypnts.size()-1];
    for(int i = 0; i<s_ypnts.size()-1; i++) 
        arrpnt[i] = new int[n-1];
    
    for(int i = 0; i<s_ypnts.size()-1; i++) {
        int counter = 0;
        for(int j = 0; j<n-1; j++) {
            int mini = min(lines[j].first, lines[j].second), maxi = max(lines[j].first, lines[j].second);
            if( (mini < s_y_arr[i] && s_y_arr[i] > maxi) || (s_y_arr[i] == 1 && lines[j].first == 1) )
                counter++; 
            arrpnt[i][j] = counter;
        }
    }
    
    for(int i = 0; i<q; i++) {
        int x1, x2, y; cin>>x1>>x2>>y;
        int ind = 0;
        for(int j = 1; j<s_ypnts.size(); j++) {
            if(y > s_y_arr[j]) ind = j-1;
            else break;
        }
        cout<<arrpnt[ind][x2-1] - arrpnt[ind][x1-1]<<endl;
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