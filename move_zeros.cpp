#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zi = 0, nzi = 0;
        // cout<<"test : "<<nums.size()<<" "<<zi<<" "<<nzi<<endl;
        while(true) {
            while(nums[zi] != 0) zi++;
            while(nums[nzi] == 0 || nzi<=zi) nzi++;
            // cout<<"test : "<<zi<<" "<<nzi<<endl;
            if(nzi<nums.size() && zi<nums.size()) {
                int temp = nums[zi];
                nums[zi] = nums[nzi];
                nums[nzi] = temp;    
            }  
            else break;          
            zi++;nzi++;
        }
        for(auto i : nums) cout<<i<<" ";
        cout<<endl;
    }
};
int main() {
    Solution s;
    vector<int> nums(5);
    nums[0] = 0; nums[1] = 1; nums[2] = 0; nums[3] = 3; nums[4] = 12;
    s.moveZeroes(nums);
    return 0;
}