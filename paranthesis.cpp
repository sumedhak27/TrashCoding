#include<iostream>
#include<stack>
using namespace std;

int rec_func(int b, int e, int end_p[]) {
    if(b+1 == e) return 1;
    int mid = end_p[b];
    if(mid == e) return 2*rec_func(b+1, e-1, end_p);
    return rec_func(b, mid, end_p)+ rec_func(mid+1, e, end_p);
}

void go(string s) {
    stack<int> st;
    int end_p[s.length()] = {};
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '(') st.push(i);
        else {
            end_p[st.top()] = i; 
            st.pop();
        } 
    }
    for(int i : end_p) cout<<i<<" ";
    cout<<endl;
    int sum = rec_func(0,s.length()-1, end_p);
    cout<<sum<<endl;
}

int main() {
    string s = "(()(())(()))()";
    go(s);
    return 0;
}