#include <bits/stdc++.h>

using namespace std;

#define io              ios_base::sync_with_stdio(false);cin.tie(NULL);


//kanpsack problem

int main(){
    io;
    int t,size,element;
    vector<int> arr;
    cin>>t;
    for(int i=0;i<t;i++){
      cin>>size;
      int sum=0;
      vector<int> arr;
      for(int j=0;j<size;j++){
        cin>>element;
        sum+=element;
        arr.push_back(element);
      }
      vector<int> w;
      w.assign(sum+1,false);
      w.at(0)=true;

      for(int i=0;i<arr.size();i++){
        for(int j=sum;j>=0;j--){
          if(w[j]) w.at(j+arr[i])=true;
        }
      }
      int diff=0;
      vector<int> mi;
      for(int i=0;i<w.size();i++){
        if(w[i]){
          diff=sum-i;
          int o=abs(diff-i);
          mi.push_back(o);
        }
      }
      cout << *min_element(mi.begin(), mi.end())<<"\n"; 
    }
    
  return 0;  
}
