#include <iostream>


using namespace std;


long long binpow(long long x,long long y,long long n){
	x%=n;
    long long res=1;
    while(y>0){
    	if (y&1){
    		res=res*x%n;
    	}
    	x=x * x % n;
    	y>>=1;
    }
    return res;
}
 

int main() 
{ 
	int c,end;
	long long x,y,n;
	cin>>c;
	for(int i=0;i<c;++i){
		cin>>x>>y>>n;
		cout<<binpow(x,y,n)<<endl;
	}
	cin>>end;
	return 0; 
} 
