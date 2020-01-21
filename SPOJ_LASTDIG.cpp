#include <iostream>


using namespace std;

int binpow(long long a, long long b)
{
    if(a == 0 && b == 0)    return 0;
    int ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
            ans *= a;
        a *= a;
        a %= 10;
        ans %= 10;
        b /= 2;
        if(ans == 0)    break;
    }
    return ans;
}
 

int main() 
{ 
	int c;
	long long x,y;
	cin>>c;
	for(int i=0;i<c;++i){
		cin>>x>>y;
		if (y==0){
			cout<<1<<endl;
		}
		else{
            cout<<binpow(x,y)<<endl;
        }
	}
	return 0; 
} 
