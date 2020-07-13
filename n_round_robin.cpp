#include<iostream>
#include<queue>
#include<numeric>

using namespace std;

const int n = 5;

double avg_waiting_time(int at[], int bt[]) {
    int rem_bt[n], wt[n] = {0};
    copy(bt, bt+n, rem_bt);
    queue<int> processes;
    int curr_t = 0, time_quantum = 2, i = 0;
    while(at[i]<=curr_t)
        processes.push(i++);
    int total_t = 0;
    total_t = accumulate(bt,bt+n,total_t);
    while(curr_t < total_t) {
        int curr_p = processes.front();
        processes.pop();
        if(rem_bt[curr_p] > time_quantum) {
            curr_t+=time_quantum;
            rem_bt[curr_p]-=time_quantum;
        }
        else {
            curr_t+=rem_bt[curr_p];
            rem_bt[curr_p] = 0;
            wt[curr_p] = curr_t - at[curr_p] - bt[curr_p];
        }while(at[i]<=curr_t && i<n)
            processes.push(i++);
        if(rem_bt[curr_p] > 0) processes.push(curr_p);
    }
    double avg_wt = 0;
    avg_wt = accumulate(wt, wt+n, avg_wt)/n; 
    return avg_wt;
}

int main() {

    int arrival_t[n] = {0,2,3,5,6};
    int burst_t[n] = {4,3,2,3,1};
    cout<<"Average waiting time : "<<avg_waiting_time(arrival_t, burst_t);
    return 0;
}