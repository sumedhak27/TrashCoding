#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

inline int char_to_int(char c) {return (int)c-48;}

struct node {
    string n_name;
    int g_val, f_val;
};

void print_node(node n){
    cout<<"( "<<n.n_name<<", "<<n.g_val<<", "<<n.f_val<<" ) "<<endl;
}

void display_graph(vector<vector<pair<int,int> > > graph) {
    cout<<endl;
    for(int i = 0 ; i<graph.size(); i++) {
        cout<<i<<" -> ";
        for(int j = 0; j< graph[i].size(); j++) {
            cout<<"("<<graph[i][j].first<<" ,"<<graph[i][j].second<<") ";
        }
        cout<<endl;
    }
    cout<<endl;
}


bool compare_func(node n1, node n2) {
    if(n1.f_val == n2.f_val) return n1.g_val<n2.g_val;
    return n1.f_val<n2.f_val; 
}

void a_star(vector<vector<pair<int,int> > > graph, int h[], int start , int goal) {
    // display_graph(graph);
    deque<node> open;
    vector<node> closed;
    node s_n = {to_string(start), 0, h[start]};
    open.push_back(s_n);
    sort(open.begin(), open.end(), compare_func);
    closed.push_back(s_n);
    open.pop_front();
    while(1) {
        node c_n = closed.back();
        int c_n_name = char_to_int(c_n.n_name.back());
        // cout<<"Test : "<<char_to_int(c_n.n_name.back())<<" <- back char"; print_node(c_n);
        if(c_n_name == goal) break; 
        for(int i = 0; i < graph[c_n_name].size(); i++) {
            // cout<<"I am here. "<<graph[c_n_name][i].first<<" "<<graph[c_n_name][i].first<<endl;
            node n_n = { c_n.n_name+to_string(graph[c_n_name][i].first), c_n.g_val+graph[c_n_name][i].second ,c_n.g_val+graph[c_n_name][i].second+h[graph[c_n_name][i].first]};
            // cout<<"New node : "; print_node(n_n);
            open.push_back(n_n);
        }
        sort(open.begin(), open.end(), compare_func);
        closed.push_back(open.front());
        open.pop_front();
    }

    cout<<endl<<"open list"<<endl;
    for(auto itr: open) cout<<"( "<<itr.n_name<<", "<<itr.g_val<<", "<<itr.f_val<<" ) ";
    cout<<endl<<"closed list"<<endl;
    for(auto itr: closed) cout<<"( "<<itr.n_name<<", "<<itr.g_val<<", "<<itr.f_val<<" ) ";
    cout<<endl;
}

int main() {

    int n_nodes;
    // cout<<"Total number of Nodes in a graph : ";
    cin>>n_nodes;
    vector<vector<pair<int,int> > > graph(n_nodes);
    int heuristic_val[n_nodes] = {0};
    for(int i = 0 ; i < n_nodes; i++){
        // cout<<"Heuristic value of node "<<i<<" : ";
        cin>>heuristic_val[i];
        int n_childs;
        // cout<<"Number of childs for node "<<i<<" : ";
        cin>>n_childs;
        for(int j = 0; j < n_childs; j++) {
            int c_node, e_dist;
            cin>>c_node>>e_dist;
            graph[i].push_back(make_pair(c_node, e_dist));
        }
    }
    display_graph(graph);
    a_star(graph, heuristic_val, 0, 5);
    return 0;
}

// input 
// 5
// 8 2 1 1 2 4
// 6 3 2 2 3 5 4 12
// 2 1 3 2
// 1 1 4 3
// 0 0 

// 6
// 4 2 1 1 5 12 
// 2 2 2 3 3 1
// 6 1 4 3
// 2 2 4 1 5 2
// 3 1 5 3
// 0 0