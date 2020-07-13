#include <iostream>
#include <algorithm>
using namespace std;
int n; string s;

int giveStringSum(string s) {
    int sum = 0;
    for(int i = 0; i<s.length(); i++)
        sum+= (int(s[i])-'a'+1);
    return sum;
}

int solve() {
    cin>>n>>s;
    int isum = giveStringSum(s);
    int curr_ans = 0;
    if(isum == n) return 0;
    if(isum > n) {
        sort(s.begin(),s.end(), greater<int>());
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie(); 
    solve();
    return 0;
}