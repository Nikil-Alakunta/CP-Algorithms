#include <iostream>


using namespace std;

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}

int main() 
{ 
	int c,a,b;
	cin>>c;
	for(int i=0;i<c;i++){
		cin>>a>>b;
		cout<<gcd(a,b)<<" ";
		cout<<lcm(a,b)<<endl;
	}
	return 0; 
} 
