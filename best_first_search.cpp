#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef vector<vector<pair<int,int> > > vvpii; 

struct node {
    string n_name;
    int g_val;
};

struct compare_struct {
    bool operator ()(node const& n1, node const& n2) {
        return n1.g_val>n2.g_val;
    }
};

inline int char_to_int(char c) { return (int)c-48; }

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

void print_open_closed_list(priority_queue<node, vector<node>, compare_struct> open, vector<node> closed) {
    cout<<"Open List : "<<endl;
    for(auto temp = open; !temp.empty(); temp.pop()) cout<<"( "<<temp.top().n_name<<", "<<temp.top().g_val<<" )";
    cout<<endl;
    cout<<"Closed List : "<<endl;
    for(auto itr : closed) cout<<"( "<<itr.n_name<<", "<<itr.g_val<<" )";
    cout<<endl<<endl;
} 

void bfs(vvpii graph, int h[], int start, int end) {
    priority_queue<node, vector<node>, compare_struct> open;
    vector<node> closed;
    node s_n = {to_string(start), h[0]};
    closed.push_back(s_n);
    while(1) {
        node c_n = closed.back();
        int c_n_name = char_to_int(c_n.n_name.back());
        if(c_n_name == end) break;
        for(auto itr : graph[c_n_name]) {
            node nn = {c_n.n_name+to_string(itr.first), h[itr.first]};
            open.push(nn);
        }
        print_open_closed_list(open, closed);
        closed.push_back(open.top());
        open.pop();
    }
    print_open_closed_list(open, closed);
}

int main() {
    vvpii graph;
    cout<<"Enter number of nodes in graph : ";
    int n; cin>>n;
    graph.resize(n);
    int heuristic[n];
    for(int i = 0; i<n; i++) {
        cout<<"Enter heuristic value of node "<<i<<" : ";
        cin>>heuristic[i];
    }
    cout<<endl;
    for(int i =0 ; i<n; i++) {
        cout<<"Number of childs for node "<<i<<" : ";
        int n_childs; cin>>n_childs;
        for(int j = 0; j<n_childs; j++) {
            cout<<"Enter node name and its distance : ";
            int c_n, c_d; cin>>c_n>>c_d;
            graph[i].push_back(make_pair(c_n,c_d));
        }
    }
    display_graph(graph);
    bfs(graph, heuristic, 0, 4);
    return 0;
}

// 5
// 8 6 2 1 0
// 2 1 1 2 4
// 3 2 2 3 5 4 12
// 1 3 2
// 1 4 3
// 0 