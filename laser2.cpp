#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

typedef pair<int,int> pii;
typedef unordered_map<int,int> umii;

umii add_umii(umii u1, umii u2) {
    umii res;
    for(auto itr = u1.begin(); itr!=u1.end(); itr++) res[itr->first]+=itr->second;
    for(auto itr = u2.begin(); itr!=u2.end(); itr++) res[itr->first]+=itr->second;
    return res;
}

umii bst_util(int arr[], pii lines[], int s_x, int e_x, int st_i, umii* st) {
    if(s_x+1 == e_x) {
        umii temp;
        int mini = min(lines[s_x-1].first, lines[s_x-1].second), maxi = max(lines[s_x-1].first, lines[s_x-1].second);
        if(s_x == 1) temp[lines[s_x-1].first]++;
        for(int i = mini + 1; i<maxi; i++) 
            temp[i]++;
        temp[lines[s_x-1].second]++;
        st[st_i] = temp;
        return temp;
    }
    int mid = (s_x + e_x)/2;
    st[st_i] = add_umii(bst_util(arr, lines, s_x, mid, st_i*2+1, st), bst_util(arr, lines, mid, e_x, st_i*2+2, st));
    return st[st_i];
}

umii* build_seg_tree(int arr[], pii lines[], int n_lines) {
    int max_size = 2*pow(2, ceil(log2(n_lines))) - 1;
    umii *st = new umii[max_size];
    bst_util(arr, lines, 1, n_lines+1, 0, st);
    return st; 
}

int gs_util(umii* st, int s_x, int e_x, int qs_x, int qe_x, int st_i, int height) {
    if(qs_x <= s_x && qe_x >= e_x){
        if(st[st_i].find(height)!=st[st_i].end())
            return st[st_i][height];
        return 0;
    }
    if(e_x <= qs_x || s_x >= qe_x) return 0;
    int mid = (s_x + e_x)/2;
    return (
        gs_util(st, s_x, mid, qs_x, qe_x, 2*st_i+1, height) + 
        gs_util(st, mid, e_x, qs_x, qe_x, 2*st_i+2, height)
        );
}

int getSum(umii* st, int n_lines, int qs_x, int qe_x, int height) {
    if(qs_x < 0 || qe_x > n_lines+1 || qs_x > qe_x) return -1;
    return gs_util(st, 1, n_lines+1, qs_x, qe_x, 0, height);
}

void print_st(umii* st) {
    for(int i = 0; i<7; i++) {
        if(st[i].empty()) { cout<<"empty"<<endl<<endl; continue;}
        for(auto itr = st[i].begin(); itr!= st[i].end(); itr++) {
            cout<<itr->first<<" : "<<itr->second<<endl;
        }
        cout<<endl;
    }
}

void solve() {
    int n, q; cin>>n>>q;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    pair<int,int> lines[n-1];
    for(int i =0; i<n-1; i++)
        lines[i] = {arr[i], arr[i+1]};
    umii* st = build_seg_tree(arr, lines, n-1);
    // print_st(st);
    for(int i = 0; i<q; i++) {
        int x1, x2, y; cin>>x1>>x2>>y;
        cout<<getSum(st,n-1, x1, x2, y)<<endl;
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