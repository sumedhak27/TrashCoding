#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

// inline void log_mat(int mat[][4]) {
//     for(int i = 0; i<4; i++) {
//         for(int j = 0; j<4; j++) {
//             cout<<mat[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

int main() {
    int t;
    cin>>t;
    int ans[t] = {0};
    int counter = 0;
    while(t--) {
        int n;
        cin>>n;
        int mat[4][4] = {0};
        for(int i = 0; i<n; i++) {
            char m; int st;
            cin>>m>>st;
            mat[(int)m-65][st/3-1]++;
        }
        // log_mat(mat);
        int max_sum = INT32_MIN;
        for(int i = 0 ; i < 4; i++) {
            int temp_sol[4] = {0};
            // temp_sol[0]+=mat[0][i];
            temp_sol[0] = mat[0][i];
            for(int j = 0; j < 4; j++) {
                if(j == i) continue;
                // temp_sol[1]+=mat[1][j];
                temp_sol[1] = mat[1][j];
                for(int k = 0 ; k < 4; k++){
                    if(k == i || k == j) continue;
                    // temp_sol[2]+=mat[2][k];
                    temp_sol[2] = mat[2][k];
                    for(int l = 0; l < 4; l++){
                        if(l == i || l == j || l == k) continue;
                        // temp_sol[3]+=mat[3][l];
                        temp_sol[3] = mat[3][l];
                        int temp_temp[4];
                        copy(begin(temp_sol), end(temp_sol), begin(temp_temp));
                        sort(temp_temp, temp_temp+4, greater<int>());
                        int ti_val = 100, sum = 0;
                        for(int m = 0; m<4; m++) {
                            if(temp_temp[m] == 0) sum-=100; 
                            else {
                                sum+=temp_temp[m]*ti_val; 
                                ti_val-=25;
                            }
                        }
                        if(sum > max_sum) max_sum = sum;
                        // temp_sol[3]-=mat[3][l];
                        temp_sol[3] = 0;

                    }
                    // temp_sol[2]-=mat[2][k];
                    temp_sol[2] = 0;
                }
                // temp_sol[1]-=mat[1][j];
                temp_sol[1] = 0;
            }
            // temp_sol[0]-=mat[0][i];
            temp_sol[0] = 0;
        }
        ans[counter] = max_sum;
        cout<<ans[counter++]<<endl;
    }
    int sum = 0;
    sum = accumulate(ans, ans+counter, sum);
    cout<<sum<<endl;
    return 0;
}