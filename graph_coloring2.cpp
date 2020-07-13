#include <bits/stdc++.h>
using namespace std;

struct Node {
    int name;
    bool * colors;
    int ncp;
    Node(int name, int n_colors) : name(name), ncp(n_colors) {
        colors = new bool[n_colors]; 
        for(int i = 0; i<n_colors; i++) colors[i] = 1;
    }
};

bool operator <(const Node& n1, Node const& n2) {
    return n1.name<n2.name;
}

void printsol(vector<int> n_c) {
    for(int i = 0; i<n_c.size(); i++)
        cout<<i<<" : "<<(char)(n_c[i]+'a')<<endl;
}

void colorgraph(vector<vector<int>>graph, vector<Node> nodeinfo, vector<int> node_colors, int c_ind,int nnodes, int ncolors) {
    static bool solutiondone = false;
    if(c_ind == graph.size()) {
        printsol(node_colors);
        solutiondone = 1;
        return;
    }
    if(nodeinfo[c_ind].ncp <= 0) return;
    for(int i = 0; i<ncolors; i++) {
        if(nodeinfo[c_ind].colors[i] == 1 && nodeinfo[c_ind].ncp>0) {nodeinfo[c_ind].ncp = 0; node_colors[c_ind] = i;}
        else nodeinfo[c_ind].colors[i] = 0;
    }
    for(int i : graph[c_ind]) {
        nodeinfo[i].colors[node_colors[c_ind]] = 0;
        nodeinfo[i].ncp--;
    }

    colorgraph(graph,nodeinfo, node_colors, c_ind+1, nnodes, ncolors);
}

int main() {
    int nnodes; cin>>nnodes;
    int nedges; cin>>nedges;
    int ncolors; cin>>ncolors;
    vector<vector<int>> graph(nnodes);
    vector<Node> nodeinfo;
    vector<int> node_colors(nnodes);
    for(int i = 0; i<nedges; i++) {
        // cout<<"Enter two nodes forming an edge : ";
        int e1,e2; cin>>e1>>e2;
        graph[e1].push_back(e2);
        graph[e2].push_back(e1);
    }
    for(int i = 0 ; i<nnodes; i++) {
        Node temp(i, ncolors);
        nodeinfo.emplace_back(temp);
    }
    colorgraph(graph, nodeinfo, node_colors, 0, nnodes, ncolors );
    return 0;
}

// 6 10 3
// 0 1
// 0 2
// 0 3
// 1 2
// 2 3
// 2 4
// 2 5
// 1 5
// 3 5
// 4 5
