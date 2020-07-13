#include <iostream>
using namespace std;

void printmoves() {
    cout<<8<<" "<<8<<endl;
    cout<<5<<" "<<5<<endl;
    cout<<2<<" "<<8<<endl;
    cout<<8<<" "<<2<<endl;
    cout<<7<<" "<<1<<endl;
    cout<<1<<" "<<7<<endl;
    cout<<3<<" "<<5<<endl;
    cout<<1<<" "<<3<<endl;
    cout<<6<<" "<<8<<endl;
    cout<<8<<" "<<6<<endl;
    cout<<3<<" "<<1<<endl;
    cout<<4<<" "<<2<<endl;
    cout<<1<<" "<<5<<endl;
    cout<<5<<" "<<1<<endl;
    cout<<8<<" "<<4<<endl;
    cout<<4<<" "<<8<<endl;

}

void solve() {
    int ro, co; cin>>ro>>co;
    if(ro == co && co == 1) {
        cout<<16<<endl;
        printmoves();
    }
    else if(ro == co) {
        cout<<17<<endl;
        cout<<1<<" "<<1<<endl;
        printmoves();
    }
    else {
        cout<<18<<endl;
        cout<<(ro+co)/2<<" "<<(ro+co)/2<<endl;
        cout<<1<<" "<<1<<endl;
        printmoves();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}