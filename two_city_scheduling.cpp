#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int tcost = 0;
        multiset<int> a, b;
        int j = 0;
        for(auto& p : costs) {
            if(p[0]<p[1]) {
                a.insert(p[1]-p[0]);
                tcost+=p[0];
            }
            else {
                b.insert(p[0]-p[1]);
                tcost+=p[1];
            }
        }
        int i = 0;
        while(a.size()>(n/2)) {
            tcost+=(*(a.begin()));
            a.erase(a.begin());
        }
        while(b.size()>(n/2)){
            tcost+=(*(b.begin()));
            b.erase(b.begin());
        }
        return tcost;
    }
};

int main() {
    Solution s;
    vector<vector<int>> vec{{955,371},{706,603},{321,738},{122,541},{555,207},{790,344},{170,424},{512,771},{833,437},{655,376},{378,459},{276,702},{943,789},{614,489},{634,494},{958,328},{333,736},{475,887},{531,240},{152,923},{958,31},{1,536},{942,275},{618,174},{880,532},{672,808},{996,903},{85,204},{927,703},{96,181},{263,823},{947,92},{146,553},{875,123}};
    cout<<s.twoCitySchedCost(vec)<<endl;
}