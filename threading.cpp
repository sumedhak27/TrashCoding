#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;
const int M = 2, N = 2, K = 2;
int A[M][K] = {{1, 2}, {3, 4}};
int B[K][N] = {{5, 6}, {7, 8}};
int C[M][N];

// cal function called for calculation of each digit in result matrix C
void cal(int i , int j) {
    int val = 0; 
    for(int k = 0; k<K; k++) 
        val+= A[i][k]*B[k][j];
    C[i][j] = val;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    // thread array of size M*N
    thread t[M*N];
    int p = 0;
    for(int i = 0; i<M; i++) {
        for(int j = 0; j<N; j++) {
            // creating thread for calculation of accessing 
            // i'th row and j'th row of A and B respectively
            // to calculate C[i][j]
            t[p++] = thread(cal, i, j);
        }
    }
    // waiting for all the threads to join to main calling program
    for(int i = 0; i<M*N; i++) t[i].join();

    // calculating time required for matrix multiplication
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    time_taken *= 1e-9;
    cout<<endl<<"Time taken = "<< fixed << time_taken << setprecision(9)<<endl;

    for(int i = 0; i<M; i++) {
        for(int j = 0; j<N; j++)
            cout<<C[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}