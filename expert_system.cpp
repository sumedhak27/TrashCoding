#include <iostream>

using namespace std;

#define statement "Your Recomendations :\n"
#define line "_______________________________________________________________________________\n\n"

void find_your_timepass() {
    cout<<"We will help you find the activity that will suite you..\n";
    cout<<"Lets begin the quest...\n"<<line;

    char ans;
    int choice;
    
    cout<<"Do you like to spend time in  1.group  2.alone? \t"; cin>>choice;
    if(choice == 1) {
        cout<<"Do you like to play  1.outdoor or 2.indoor games? \t"; cin>>choice;
        if(choice == 1) {
            cout<<"Are you familiar with 1.rackets  2.bats  3.ball? \t"; cin>>choice;
            cout<<line<<statement;
            if(choice == 1) {
                cout<<"Tennis\n";
                cout<<"Badminton\n";
                cout<<"Squash\n";
                cout<<"Table Tennis\n";
            }
            else if(choice == 2) {
                cout<<"Cricket\nHockey\nGolf\nBaseball\n"; 
            }
            else if(choice == 3) {
                cout<<"Cricket\n";
                cout<<"Football\n";
                cout<<"Vollyball\n";
                cout<<"Handball\n";
            }
            cout<<line;
        }
        else if(choice == 2) {
            cout<<line<<statement;
            cout<<"Chess\nCarrom\nMonopoly\nCards\n"<<endl;
            cout<<line;
        }
    }
    else if(choice == 2) {
        cout<<"Do you like music ? (Y/N)\t"; cin>>ans;
        if(ans == 'Y') {
            cout<<"Do you like instruments ? (Y/N)\t"; cin>>ans; 
            if(ans == 'Y') {
                cout<<line<<statement;
                cout<<"Guitar\nFlute\nPiano\nDrum\nHarmonium\n";
                cout<<line;
            }
            else cout<<"singing\nlistening to music."<<endl;
        }
        else {
            cout<<"Do you like puzzles ? (Y/N)\t"; cin>>ans;
            if(ans == 'Y') {
                cout<<line<<statement<<"Rubics cube\n Sudoku\n Cross word\n Riddles"<<line;
            }
            else {
                cout<<"Do you like plying online games ?(Y/N)\t"<<endl; cin>>ans;
                if(ans == 'Y') {
                    cout<<"Do you have 1.PC  2.mobile ?\t"; cin>>choice;
                    if(choice == 1) {
                        cout<<statement;
                        cout<<"NFS\n";
                        cout<<"Modern Warfare\n";
                        cout<<"Fortnite\n";
                    }
                    if(choice == 2) {
                        cout<<statement;
                        cout<<"Pubg Mobile\n Asphalt8\n Call Of Duty \n Clash of Clan \n Class Royal\n";
                    }
                }
            }
        }
    }
    else {
        cout<<"Sorry we have got nothing for you get some work"<<endl;
    }
}

int main() {
    find_your_timepass();
    return 0;
}