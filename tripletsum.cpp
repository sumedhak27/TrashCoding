#include<bits/stdc++.h>
using namespace std;
const int N = 10;

void print_triplet(int array[N], int s) {
    multiset<int> sa;
    for(int i = 0; i<N; i++) cin>>array[i];
    int low = 0, high = N-1;
    while(low<high) {
        if(array[low]+array[high] > s) high--;
        else if(s-array[low]+array[high]) {
            if(sa.find(s-array[low]+array[high])!=sa.end()) {
                cout<<array[low]<<" "<<s-array[low]+array[high]<<" "<<array[high]<<endl;
            }
        }

    }

}

int main() {
    int array[N] {100,23,43,5,34,234,17,83,35,2};
    int req_sum  = 45;
    print_triplet(array, req_sum);
    return 0;
}