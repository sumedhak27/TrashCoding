#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main() {
    string s = "1234";
    // cout<<stoi(s.);
    queue<int> que;
    for(int i = 0 ; i < 20; i++) que.push(i%5);
    for(auto temp = que; !temp.empty(); temp.pop()) cout<<temp.front()<<" ";
    return 0;
}