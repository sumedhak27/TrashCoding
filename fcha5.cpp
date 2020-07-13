#include <iostream>
#include <bitset>
#include <algorithm>
// #include <bits/stdc++.h>
#define M 12000001
typedef long long int ll;
using namespace std;

ll count_ones(bitset<M> bset, ll start, ll end) {
    ll counter = 0;
    for(ll i = start;  i<=end; i++) {
        if(bset[i] == 1) counter++;
    }
    return counter;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int fe_friday = 3, fe_l_sunday = 26;
    bitset<M> bset;
    // bool bset[M] = {0};
    int tdin_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int tdin_month_inly[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    ll cur_year = 2020;
    int cur_month = 0;
    int cur_friday = fe_friday;
    int cur_l_sunday = fe_l_sunday;
    for(ll i = 2019*12+1; i<M; i++) {
        cur_month = (cur_month+1)%12;
        if(cur_month == 0) cur_year++;
        if(cur_year%400 || (cur_year%4 == 0 && cur_year%100 != 0)) {
            cur_friday = (cur_friday+28)-tdin_month_inly[cur_month-1];
            if( cur_friday <= 0) cur_friday+=7;
            cur_l_sunday = (cur_l_sunday+35)-tdin_month_inly[cur_month-1];
            if( cur_l_sunday > tdin_month_inly[cur_month]) cur_l_sunday-=7;   
        }
        else{
            cur_friday = (cur_friday+28)-tdin_month[cur_month-1];
            if( cur_friday <= 0) cur_friday+=7;
            cur_l_sunday = (cur_l_sunday+35)-tdin_month[cur_month-1];
            if( cur_l_sunday > tdin_month[cur_month]) cur_l_sunday-=7;
        }
        if(cur_friday+10 >= (cur_l_sunday-7)) bset[i] = 1;
    }

    cur_year = 2020;
    cur_month = 0;
    cur_friday = fe_friday;
    cur_l_sunday = fe_l_sunday;
    for(ll i = 2019*12-1; i>=0; i--) {
        cur_month-1<0 ? cur_month = 11 : cur_month--;
        if(cur_month == 11) cur_year--;
        if(cur_year%400 || (cur_year%4 == 0 && cur_year%100 != 0)) {
            cur_friday = tdin_month_inly[cur_month] - (35-cur_friday);
            if( cur_friday <= 0) cur_friday+=7;
            if(28-cur_l_sunday < 0) cur_l_sunday = tdin_month_inly[cur_month]-(35-cur_l_sunday);
            cur_l_sunday = tdin_month_inly[cur_month]-(28-cur_l_sunday);   
        }
        else{
            cur_friday = tdin_month[cur_month] - (35-cur_friday);
            if( cur_friday <= 0) cur_friday+=7;
            if(28-cur_l_sunday < 0) cur_l_sunday = tdin_month[cur_month]-(35-cur_l_sunday);
            cur_l_sunday = tdin_month[cur_month]-(28-cur_l_sunday);
        }
        if(cur_friday+10 >= (cur_l_sunday-7)) bset[i] = 1;
    }

    // for(int i = 0 ; i < 48; i++) {
    //     cout<<bset[i];
    // }
    int t;
    cin>>t;
    while(t--) {
        int m1,m2; ll y1,y2;
        cin>>m1>>y1;
        cin>>m2>>y2;
        // cout<<count_ones(bset, (y1-1)*12+(m1-1), (y2-1)*12+(m2-1))<<endl;
        // cout<<count(bset+(y1-1)*12+(m1-1), bset+(y2-1)*12+(m2-1), true)<<endl;
    }
    // cout<<count_ones(bset, (2008*12+9)-1, (2020*12)+1-1 )<<endl;
    // cout<<count_ones(bset, (2019*12)+(2-1), (2020*12)+(2-1) )<<endl;
    // cout<<bset[2019*12+1]<<endl;
    return 0;
}