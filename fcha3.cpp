#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef map<int, vector<pair<char,int> >, greater<int>> ds;
typedef vector< pair<char,int> > vp;

// inline void log_st_a(bool st_a[]) {
//     for(int i = 0; i<4; i++){
//         cout<<st_a[i]<<" ";
//     }
//     cout<<endl;
// }

ds delete_all_nodes(char m, int st, ds map2) {
    for(ds::iterator itr = map2.begin(); itr!=map2.end(); itr++) {
        vp temp(itr->second.begin(), itr->second.end());
        for(vp::iterator itr2 = temp.begin(); itr2!=temp.end(); itr2++)
            if(itr2->first == m || itr2->second == st){
                // cout<<itr2->first<<" test "<<itr2->second<<endl;
                temp.erase(itr2--);
            }
        itr->second = temp;
        if(itr->second.size() == 0) map2.erase(itr);
    }
    return map2;
}

int rec_fuc(ds map2, int cur_profit, int ticket_val,char m, int st, bool st_a[]) {
    map2 = delete_all_nodes(m, st, map2);
    if(ticket_val == 0 || map2.empty()) {
        int _count = count(st_a,st_a+4,true);
        return cur_profit-(_count*100);
    }
    auto itr = map2.begin();
    cur_profit += itr->first*ticket_val;
    int max_profit = INT32_MIN;
    for(auto it : itr->second) {
        // cout<<it.first<<" test "<<it.second<<endl; 
        st_a[(int)it.first-65] = false;
        max_profit = max(max_profit, rec_fuc(map2,cur_profit, ticket_val-25, it.first, it.second, st_a));
    }
    return max_profit;
}

int theatre_pro(ds map2, bool st_a[]) {
    if(map2.empty()) return -400;
    auto itr = map2.begin();
    int cur_profit = itr->first*100;
    int max_profit = INT32_MIN;
    for(auto it : itr->second) {
        // cout<<it.first<<" test "<<it.second<<endl; 
        st_a[(int)it.first-65] = false;
        // log_st_a(st_a);
        max_profit = max(max_profit, rec_fuc(map2,cur_profit, 75, it.first, it.second, st_a));
    }
    return max_profit;
}


// inline void log_map1(map<pair<char,int> , int> map1) {
//      for(auto en : map1)
//             cout<<en.first.first<<" "<<en.first.second<<" : "<<en.second<<endl;
// }

// inline void log_map2(ds map2) {
//     for(auto en : map2) {
//         cout<<en.first<<" -> ";
//         for(auto it : en.second)
//             cout<<"("<<it.first<<", "<<it.second<<") ";
//         cout<<endl;
//     }
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin>>t;
    int ans[t] = {0};
    int counter = 0;
    while(t--) {
        int n;
        cin>>n;
        bool st_a[4] = {true, true, true, true};
        // log_st_a(st_a);
        map<pair<char,int> , int> map1;
        for(int i = 0; i < n; i++) {
            char m;
            int st;
            cin>>m>>st;
            map1[{m,st}]++;
        }
        ds map2;

        for(auto en : map1){
            vector<pair<char,int> > vtemp(map2[en.second].begin(), map2[en.second].end());
            vtemp.push_back(make_pair(en.first.first, en.first.second));
            map2[en.second] = vtemp;
        }
        
        ans[counter] = theatre_pro(map2, st_a);
        cout<<ans[counter++]<<endl;
    }
    int sum = 0;
    sum = accumulate(ans, ans+(counter), sum);
    cout<<sum<<endl;
    return 0;
}