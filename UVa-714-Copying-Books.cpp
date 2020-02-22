#include <bits/stdc++.h>

using namespace std;

#define io              ios_base::sync_with_stdio(false);cin.tie(NULL);



int main(){
    int t;
    cin>>t;
    while(t--){
        int ar_size,num,element,k=0;
        long double s=0;
        cin>>ar_size>>num;
        vector<int> a(ar_size);
        vector<long double> p;
        for(int i=0;i<ar_size;i++){
            cin>>a[i];
            s+=a[i];
        }
        s/=num;
        p.assign(num,s);
        a.push_back(0);

        for(int i=0;i<ar_size;i++){
            cout<<a[i]<<" ";
            p[k]-=a[i];
            if(p[k]<a[i+1]){
                k=k+1;
                p[k]+=p[k-1];
                cout<<" / "<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
