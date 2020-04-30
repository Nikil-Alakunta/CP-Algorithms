#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono; 

#define io                  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long
#define INTMAX 25000001

//problem link https://www.spoj.com/problems/ADDREV/

int main() {
  io;
  int t,a,b,sum;
  cin>>t;
  while(t--){
    cin>>a>>b;
    string a1=to_string(a);
    string b1=to_string(b);
    reverse(a1.begin(),a1.end());
    reverse(b1.begin(),b1.end());
    int a2=stoi(a1);
    int b2=stoi(b1);
    sum=a2+b2;
    string sum1=to_string(sum);
    reverse(sum1.begin(),sum1.end());
    int sum3=stoi(sum1);
    cout<<sum3<<"\n";
  }

    //auto start = high_resolution_clock::now(); 

    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start);
    //cout<<duration.count()<<"\n";

  


  return 0;
}
