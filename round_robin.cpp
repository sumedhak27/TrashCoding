#include <iostream>
#include <queue>

using namespace std;

struct Process {
    int pid, at, bt, tat, wt, rt, rbt;
};

struct cf1 {
    bool operator() (Process const& p1, Process const& p2) {
        if(p1.at == p2.at) return p1.pid>p2.pid;
        return p1.at>p2.at;
    }
};

struct cf3 {
    bool operator ()(const Process& p1, const Process& p2) {
        return p1.pid > p2.pid;
    }
};


int main() {
    // input of problem 
    priority_queue<Process, vector<Process>, cf1> inpr;
    cout<<"Enter number of processes : ";
    int n_pro, time_quantum;
    cin>>n_pro>>time_quantum;
    for(int i = 0 ; i<n_pro; i++){
        int pid, at, bt;
        cin>>pid>>at>>bt;
        inpr.push({pid,at,bt,0,0,INT32_MAX,bt});
    } 

    // Round Robin Algorithm
    queue<Process> ready;
    priority_queue<Process, vector<Process>, cf3> ans;
    int time = 0;
    cout<<"Sequence of execution is : ";
    while(!inpr.empty() && inpr.top().at<=time) {
        ready.push(inpr.top());
        inpr.pop();
    }
    while (!inpr.empty() || !ready.empty()) {
        bool flag = 0; Process curr_process;
        if(!ready.empty()) {
            curr_process = ready.front();
            cout<<curr_process.pid<<" ";
            ready.pop();
            if(curr_process.rt == INT32_MAX) curr_process.rt = time - curr_process.at;
            if(curr_process.rbt > time_quantum) {
                flag = 1;
                time+=time_quantum;
                curr_process.rbt-=time_quantum;
            }
            else {
                time+=curr_process.rbt;
                curr_process.rbt = 0;
                curr_process.tat = time - curr_process.at;
                curr_process.wt = curr_process.tat - curr_process.bt;
                ans.push(curr_process);
            }
        }
        else { time++;}
        while(!inpr.empty() && inpr.top().at<=time) {
            ready.push(inpr.top());
            inpr.pop();
        }
        if(flag) ready.push(curr_process);
    }
    cout<<endl<<endl;
    cout<<"process_id  arrival_time  burst_time  turn_around_time  waiting_time  responce time"<<endl;
    for(auto temp = ans; !temp.empty(); temp.pop()) 
        cout<<temp.top().pid<<"\t\t"<<temp.top().at<<"\t\t"<<temp.top().bt<<"\t\t"<<temp.top().tat<<"\t\t"<<temp.top().wt<<"\t\t"<<temp.top().rt<<endl;
    return 0;
}


// 5 2
// 1 3 4
// 2 5 3
// 3 0 2
// 4 5 1
// 5 4 3