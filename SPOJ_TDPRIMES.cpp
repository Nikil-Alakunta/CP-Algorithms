#include<iostream> 
#include<iterator>  
#include<vector>  
#include <cmath>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std; 



//using block sieving

const int SQRT_MAXN = 100000;
const int S = 10000;
bool nprime[SQRT_MAXN], bl[S];
int primes[SQRT_MAXN], cnt=0;

int main() {
    int n;
    cin >> n;
    int a=100;
    int b=0;
    int result = 0;
    vector<int> prime_numbers;
    vector<int>::iterator ptr;
    int interval=0;
    int nsqrt = (int) sqrt (n + .0);

    for (int i=2; i<=nsqrt; ++i)
        if (!nprime[i]) {
            primes[cnt++] = i;
            if (i * 1ll * i <= nsqrt)
                for (int j=i*i; j<=nsqrt; j+=i)
                    nprime[j] = true;
        }

    
    for (int k=0, maxk=n/S; k<=maxk; ++k) {
        memset (bl, 0, sizeof bl);
        int start = k * S;
        interval=start;
        for (int i=0; i<cnt; ++i) {
            int start_idx = (start + primes[i] - 1) / primes[i];
            int j = max(start_idx,2) * primes[i] - start;
            for (; j<S; j+=primes[i])
                bl[j] = true;
        }
        if (k == 0)
            bl[0] = bl[1] = true;
        for (int i=0; i<S && start+i<=n; ++i)
            if (!bl[i]){
                ++result;
                prime_numbers.push_back(start+i);
                }
    }

    for(int i=0;i<prime_numbers.size();i++){
    	if(i==b){
    	cout<<prime_numbers[i]<<endl;
    	b+=a;
        }

    }

}
