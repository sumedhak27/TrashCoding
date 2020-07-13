#include <bits/stdc++.h>
#include <chrono>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        set<int> visited;
        while(n!=1 && !visited.count(n)) {
            visited.insert(n);
            int digit, num = n;
            n = 0;
            while(num) {
                digit = (num%10);
                num/=10;
                n += (digit * digit);
            }
        }
        if(n == 1) return true;
        return false;
    }
};

int main() {
    auto start = chrono::high_resolution_clock::now();
    Solution s;
    for(int i = 0; i<1020; i++) s.isHappy(i);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    time_taken*=1e-9;
    cout<<"Time taken = "<< fixed << time_taken << setprecision(9)<<endl;        
}