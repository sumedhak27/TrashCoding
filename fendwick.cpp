#include <bits/stdc++.h>
using namespace std;

int get_sum(int bit[], int i) {
    int sum = 0; i++;
    while(i>0) {
        sum+=bit[i];
        i-= i&(-i);
    }
    return sum;
}

void update_bit(int bit[], int val, int i, int n) {
    i++;
    while(i<n+1) {
        bit[i]+=val;    
        i+= i&(-i);
    }
}

int* create_bit(int arr[], int n) {
    int *bit = new int[n+1];
    memset(bit,0,(n+1)*sizeof(int));
    for(int i = 0; i<n; i++) 
        update_bit(bit, arr[i], i, n);
    return bit  ;
}

int main() {
    int arr[]{2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int *bitree = create_bit(arr, size);
    for(int i = 0; i<size+1; i++) cout<<bitree[i]<<" ";
    cout<<endl; 
    cout<<get_sum(bitree, 5)<<endl;
    update_bit(bitree, 6, 3, size);
    cout<<get_sum(bitree, 5)<<endl;
}   