#include <bits/stdc++.h>


#define io           ios::sync_with_stdio(false); cin.tie(0);
 
using namespace std;

int main(){
    io;
    string input;
    while(cin>>input,input!="#"){
    	if(next_permutation(input.begin(),input.end()))
    		cout<<input<<"\n";
    	else
    		cout<<"No Successor\n";
    }

	return 0;
}
