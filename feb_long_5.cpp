#include "bits/stdc++.h"
#include "chrono"
using namespace std;
// using namespace std::chrono; 
long long int ly(long long int n)
{
    if(n%400==0 || (n%4==0 && n%100!=0)){
        return 1;
    }else{
        return 0;
    }
}
long long int dayOfWeek(long long int y, long long int m, long long int d){
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  y -= m < 3;
  return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// auto start = high_resolution_clock::now(); 
	long long int t;
	cin>>t;
	while(t--){
        long long int m1,m2,y1,y2,i,j,c=0,s=0,f=0;
        cin>>m1>>y1;
        cin>>m2>>y2;
        if(y1==y2){
            if(m1<=2 && m2>=2){
                if(dayOfWeek(y1,2,1)==0){
                    if(ly(y1)!=1)
                        c++;
                }else if(dayOfWeek(y1,2,1)==6)
                    c++;
            }
            cout<<c<<endl;
        }

        if(y1!=y2){
            if(m1<=2){
                if(dayOfWeek(y1,2,1)==0){
                    if(ly(y1)!=1)
                        c++;
                }else if(dayOfWeek(y1,2,1)==6)
                    c++;
            }
            if(m2>=2){
                if(dayOfWeek(y2,2,1)==0){
                    if(ly(y2)!=1)
                        c++;
                
                }else if(dayOfWeek(y2,2,1)==6)
                    c++;
            }
            for(i=y1+1;i<=y2-1;i++){
                    if(dayOfWeek(i,2,1)==0){
                        if(ly(i)!=1){
                            // cout<<i<<endl;
                            c++;
                        }
                    }else if(dayOfWeek(i,2,1)==6){
                        // cout<<i<<endl;
                        c++;
                    }
            }
            cout<<c<<endl;
        }
	}
	return 0;
}