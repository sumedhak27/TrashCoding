#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binserach(vector<int>& nums, int low, int high, int target) {
        if(low>high) return -1;
        int mid = (low+high)/2;
        if(nums[mid] == target) return mid;
        if(nums[low]<nums[mid]) {
            if(nums[low] <= target && target<=nums[mid-1]) 
                return binserach(nums, low, mid-1, target);
            else 
                return binserach(nums, mid+1, high, target);
        }
        if(nums[mid+1]<=target && target<=nums[high])
            return binserach(nums, mid+1, high, target);
        return binserach(nums, low, mid-1, target);
    }

    int search(vector<int>& nums, int target) {
        return this->binserach(nums, 0, nums.size()-1, target);
    }
};

int main() {
    vector<int> nums{4,5,6,7,0,1,2};
    int target  = 3;
    Solution s;
    cout<<s.search(nums, target)<<endl;
}