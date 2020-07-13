#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int pid, at, bt, tat, wt;
};

struct cf1 {
    bool operator() (Process const& p1, Process const& p2) {
        if(p1.at == p2.at) return p1.pid>p2.pid;
        return p1.at>p2.at;
    }
};

struct cf2 {
    bool operator ()(Process const& p1, Process const& p2) {
        if(p1.bt == p2.bt) return p1.pid > p2.pid;
        return p1.bt > p2.bt;
    }
};

struct cf3 {
    bool operator ()(Process const& p1, Process const& p2) {
        return p1.pid > p2.pid;
    }
};

int main() {
    // input of problem 
    priority_queue<Process, vector<Process>, cf1> inpr;
    cout<<"Enter number of processes : ";
    int n_pro;
    cin>>n_pro;
    for(int i = 0 ; i<n_pro; i++){
        int pid, at, bt;
        cin>>pid>>at>>bt;
        inpr.push({pid,at,bt,0,0});
    }  

    // solution with ready queue of ans queue
    priority_queue<Process, vector<Process>, cf2> ready_q;
    priority_queue<Process, vector<Process>, cf3> ans;
    int time = 0;
    cout<<"Sequence of execution is : ";
    while(!inpr.empty() || !ready_q.empty()) {
        while(!inpr.empty() && inpr.top().at <= time) {
            ready_q.push(inpr.top());
            inpr.pop();
        }
        if(ready_q.empty()) { time++; continue; }
        Process curr_p = ready_q.top();
        cout<<curr_p.pid<<" ";
        ready_q.pop();
        time+=curr_p.bt;
        curr_p.tat = time - curr_p.at;
        curr_p.wt = curr_p.tat - curr_p.bt;
        ans.push(curr_p);
    }
    cout<<endl<<endl;

    cout<<"process_id  arrival_time  burst_time  turn_around_time  waiting_time"<<endl;
    for(auto temp = ans; !temp.empty(); temp.pop()) 
        cout<<temp.top().pid<<"\t\t"<<temp.top().at<<"\t\t"<<temp.top().bt<<"\t\t"<<temp.top().tat<<"\t\t"<<temp.top().wt<<endl;
    return 0;
}

// 5
// 1 3 4
// 2 5 3
// 3 0 2
// 4 5 1
// 5 4 3