#include <bits/stdc++.h>

#define io              ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int build_tree(vector<int> freq,vector<int> &tree,int v,int l,int r){
    if(l==r)
    {
        tree.at(v)=freq[l];
        return freq[l];
    }
        
    else{
        int m=(l+r)/2;
        tree.at(v)=max(build_tree(freq,tree,v*2+1,l,m),build_tree(freq,tree,v*2+2,m+1,r));
        return tree[v];
    }

}
int RMQ(vector<int> tree,int l,int r,int ql,int qr,int index){
    if(ql<=l && qr>=r){
        return tree[index];
    }
    if(ql>r || qr<l){
        return 0;
    }
    int mid=(l+r)/2;
    return max(RMQ(tree,l,mid,ql,qr,2*index+1),RMQ(tree,mid+1,r,ql,qr,2*index+2));
}
int query(vector<int> tree,vector<int> arr,int n,int ql,int qr){
    int maxOcc;

    if(arr[ql]==arr[qr]){
        maxOcc=(qr-ql+1);
    }
    else{
        int left_most=0,right_most=0;

        while(ql>0 && ql<=qr && arr[ql]==arr[ql-1]){
            ql++;
            left_most++;
        }

        while(qr>=ql && qr<n-1 && arr[qr]==arr[qr+1]){
            qr--;
            right_most++;
        }
        maxOcc=max({left_most,right_most,RMQ(tree,0,n,ql,qr,0)});
    }
    return maxOcc;
    
}
int main(){
    io;
    int ar_size,q,element;
    cin>>ar_size>>q;
    int x=int(ceil(log2(ar_size)));
    int max_size=2*(int)pow(2,x)-1;
    
    vector<int> arr;
    vector<int> tree(max_size);
    unordered_map<int,int> cnt;
    vector<int> freq;

    for(int i=0;i<ar_size;i++){
        cin>>element;
        arr.push_back(element);
    }
    for(int i=0;i<ar_size;i++){
        cnt[arr[i]]++;
    }
    for(int i=0;i<ar_size;i++){
        freq.push_back(cnt[arr[i]]);
    }
    
    build_tree(freq,tree,0,0,int(ar_size-1));
    
    for(int i=0;i<q;i++){
        int a,b,ans;
        cin>>a>>b;
        ans=query(tree,arr,ar_size-1,a-1,b-1);
        cout<<ans<<"\n";
    }
    return 0;
}
