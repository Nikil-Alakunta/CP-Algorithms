#include <bits/stdc++.h>

#define io              ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;


int main(){
    io;
    int c,s,element;
    int cases=0;
    while(cin>>c>>s){
        vector<int> v(2*c);
        long double total_mass=0;
        for(int i=0;i<s;i++){
            cin>>v[i];
            total_mass+=v[i];
        }
        sort(v.begin(),v.end());
        long double avg_mass=total_mass/c;
        long double imbalance =0;

        cout<<"Set #"<< ++cases <<"\n";
        for(int i=0;i<c;i++){
            int j=2*c-1-i;
            imbalance+=fabs(v[i]+v[j]-avg_mass);
            cout<<" "<<i<<":";
            if (v[i]) cout << " " << v[i];
            if (v[j]) cout << " " << v[j];
            cout <<"\n";
        }
        cout << "IMBALANCE = " << setprecision(5) << fixed << imbalance <<"\n";

    }

    return 0;
}
