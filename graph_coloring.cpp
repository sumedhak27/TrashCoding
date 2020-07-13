#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;

struct node {
    int name;
    bool* colors;
    int n_colors;
    node(int name, int n) : name(name), n_colors(n) {
        colors = new bool[n];
        for(int i = 0 ; i<n; i++) colors[i] = 1; 
    }
};

void printsol(vector<int> n_c) {
    for(int i = 0; i<n_c.size(); i++)
        cout<<i<<" : "<<(char)(n_c[i]+'a')<<endl;
}

void rec_helper(node sn, vvi graph, int c_color, vector<int> n_c) {
    if(graph.empty()){
        printsol(n_c);
        return;
    }
    if(sn.colors[c_color] == false) return;
    for(int i = 0; i<sn.n_colors; i++) {
        if(i!=c_color) {
            sn.colors[i] = 0; 
        }
    }
    n_c[sn.name] = c_color;
    for(int e : graph[c_color]) {
        for(int i = 0 ; i<sn.n_colors; i++) {
            vvi tempg(graph.begin(), graph.end());
            tempg.erase(tempg.begin()+c_color);
            rec_helper(sn, tempg, i);
        }
    }
}

void color_graph(int n_colors, vvi graph) {
    int start_node = 0;
    node sn(0, n_colors);
    vector<int> node_colors(graph.size());
    rec_helper(sn, graph, 0, node_colors);
}

int main() {
    vvi graph;
    cout<<"Enter number of nodes : ";
    int n; cin>>n;
    cout<<"Enter number of edges : ";
    int e_c; cin>>e_c;
    for(int i = 0; i<e_c; i++) {
        cout<<"Enter two nodes forming an edge : ";
        int e1,e2; cin>>e1>>e2;
        graph[e1].push_back(e2);
        graph[e2].push_back(e1);
    }
    int max_deg = 0;
    for(auto e : graph) max_deg = max(max_deg, (int)e.size());
    cout<<"Enter number of colors you want to assign : ";
    int colors; cin>>colors;
    if(colors < max_deg) { cout<<"Colors are not sufficient!!\n"; return 0;}
    color_graph(colors, graph);
    return 0;
}