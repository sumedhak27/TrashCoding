#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int process_id, arrival_time, burst_time, turn_around_time, waiting_time;
};

struct compare_struct1 {
    bool operator() (Process const& p1, Process const& p2) {
        if(p1.arrival_time == p2.arrival_time) return p1.process_id>p2.process_id;
        return p1.arrival_time>p2.arrival_time;
    }
};

struct compare_struct2{
    bool operator() (Process const& p1, Process const& p2) {
        return p1.process_id>p2.process_id;
    }
};

int main() {
    priority_queue<Process, vector<Process>, compare_struct1> p_q1;
    priority_queue<Process, vector<Process>, compare_struct2> p_q2;
    int n_pro;
    cin>>n_pro;
    for(int i = 0 ; i<n_pro; i++){
        int pid, at, bt;
        cin>>pid>>at>>bt;
        p_q1.push({pid,at,bt,0,0});
    }  
    int time = 0;
    
    cout<<endl<<"Process execution according to first come first serve is :";
    while(!p_q1.empty()){
        Process c_process = p_q1.top();
        p_q1.pop();
        cout<<c_process.process_id<<" ";
        if(time<c_process.arrival_time) time = c_process.arrival_time;
        time+=c_process.burst_time;
        c_process.turn_around_time = time - c_process.arrival_time;
        c_process.waiting_time = c_process.turn_around_time - c_process.burst_time;
        p_q2.push(c_process);
    }

    // for(auto temp = p_q1; !temp.empty(); temp.pop()) {
    //     cout<<temp.top().process_id<<" ";
    // }
    cout<<endl<<endl;

    cout<<"process_id  arrival_time  burst_time  turn_around_time  waiting_time"<<endl;
    for(auto temp = p_q2; !temp.empty(); temp.pop()) 
        cout<<temp.top().process_id<<"\t\t"<<temp.top().arrival_time<<"\t\t"<<temp.top().burst_time<<"\t\t"<<temp.top().turn_around_time<<"\t\t"<<temp.top().waiting_time<<endl;
    return 0;
}

// 5           
// 1 3 4          
// 2 5 3          
// 3 0 2          
// 4 5 1          
// 5 4 3          