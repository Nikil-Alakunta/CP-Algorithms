//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#define ll long long int

using namespace std;

// segment tree implmentation O(nlogn)

void build(int left, int right, int index, vector<int> &tree){
    if(left == right){
        tree[index] = 1; 
        return;}
    else{
        int mid = (left+right)>>1; 
        build(left, mid, 2*index, tree); build(mid+1, right, 2*index+1, tree); 
        tree[index] = tree[2*index]+tree[2*index+1]; 
        return;
    }
}
int query(int left, int right, int index, vector<int> &tree, int ql, int qr){
    if(ql > right || qr < left || left > right){return 0; }
    else if(ql <= left && qr >= right){return tree[index];}
    else{
        int mid = (left+right)>>1; 
        return query(left,mid,2*index,tree,ql,qr)+query(mid+1, right,2*index+1,tree,ql,qr); 
    }
}
void update(int left, int right, int index, vector<int> &tree, int ql, int qr){
    if(ql > right || qr < left || left > right){return ; }
    else if(ql <= left && qr >= right){tree[index] = 0; return;}
    else{
        int mid = (left+right)>>1; 
        update(left,mid,2*index,tree,ql,qr); update(mid+1, right,2*index+1,tree,ql,qr); 
        tree[index] = tree[2*index]+tree[2*index+1]; 
        return;
    }
}
 
int bin(int left, int right, int start, vector<int> &tree, int n, int key){
    if(left == right){return left;}
    else if(right-left == 1){
        int nb = query(0, n-1,1,tree, start, left); 
        if(nb >= key){return left;}
        else{return right;}
    }
    else{
        int mid = (left+right)>>1; 
        int nb = query(0, n-1, 1, tree, start, mid);
        if(nb >= key){return bin(left, mid, start, tree, n, key); }
        else{return bin(mid+1, right, start, tree, n, key);}
    }
}
 
int main() {
    int t; cin >> t; 
    while(t-->0){
        int n; cin >> n; 
        if(n == 1){
            cout << 1 << endl; 
        }else{
            
        vector<int> tree(4*n+1), arr(n); 
        build(0, n-1, 1, tree); 
        
        update(0, n-1 ,1, tree, 1,1);
        
        arr[1] = 1; 
        int last = 1; 
        for(int i=2; i<=n; i++){
            int lb = query(0,n-1, 1, tree, last+1, n-1), rb = query(0,n-1, 1, tree, 0, last-1); 
           
            int rank = i%(lb+rb); 
            if(rank < lb){
                int index = bin(last+1, n-1, last+1, tree, n, rank+1); 
                arr[index] = i; update(0, n-1, 1, tree, index, index); 
                last = index; 
            }else{
                rank -= lb; 
                int index = bin(0, last-1, 0, tree, n, rank+1); 
                arr[index] = i; 
                update(0, n-1, 1, tree, index, index); 
                last = index;
            }
        }
        for(int i=0 ;i<n; i++){ cout << arr[i] << " "; } 
        cout << endl;
        }
    }
   return 0;
}
