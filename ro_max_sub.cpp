#include <iostream>

using namespace std;

void leftRotatebyOne(int arr[], int n) 
{ 
    int temp = arr[0], i; 
    for (i = 0; i < n - 1; i++) 
        arr[i] = arr[i + 1]; 
  
    arr[i] = temp; 
} 

void max_sum_subarray(int arr[], int n) {
    int global_max = arr[0], curr_max = arr[0];
    int start_ind = 0, end_ind = 0;
    for(int i = 1; i<n;i++) {
        curr_max = max(arr[i], curr_max+arr[i]);
        if(curr_max == arr[i]) start_ind = i;
        else end_ind = i;
        if(curr_max > global_max) global_max = curr_max;
    }
    cout<<global_max<<" ";
    if(start_ind == end_ind)
        for(int i =0; i<n-1; i++)
            cout<<global_max<<" ";
    else {
        int discarded_sum ; int b = 0;
        for(int i = 0 ; i<n-1; i++){
            leftRotatebyOne(arr,n);
            start_ind--;end_ind--;
            if(end_ind <0) end_ind = n-1;
            if(b==1) {
                global_max+=arr[n-1];
            }
            else if( b==-1){
                if(discarded_sum+arr[n-1] > global_max-arr[n-1]) {
                    b == 1;
                    global_max = discarded_sum+arr[n-1];
                }
                else global_max = global_max-arr[n-1];
            } 
            if(start_ind<0) {
                start_ind = n-1;
                if(arr[start_ind] > global_max-arr[start_ind]){
                    b = 1;
                    // discarded_sum = global_max-arr[start_ind];
                    global_max = arr[start_ind];
                }
                else{
                    b = -1;
                    discarded_sum = arr[start_ind];
                    global_max = global_max-arr[start_ind];
                }
                cout<<global_max<<" ";
            }
            else cout<<global_max<<" ";
        }
    }
    
}


int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++) cin>>arr[i];
        max_sum_subarray(arr,n);
        cout<<endl;
    }
    return 0;
}