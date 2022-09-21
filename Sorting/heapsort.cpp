//maxHeap - heapsort, 
#include <bits/stdc++.h>
#define faio ios::sync_with_stdio(false);cin.tie(NULL);
using namespace std;


//left child = 2i+1
//right child = 2i+2

void heapify(int a[],int i,int n){
    int l = 2*i+1;
    int r = 2*i+2;
    int large = i;
    
    if(r<n && a[l]<a[r]){
        large = r;
    }else if(l<n && a[l]>a[large]) large = l;
    
    if(large!=i){
        int t = a[large];
        a[large]=a[i];
        a[i]=t;
        heapify(a,large,n);
    }
    
}
void buildheap(int a[],int n){
    
    for(int i=0;i<n/2;i++)
    heapify(a,i,n);
    
    
}
void heapsort(int a[],int n){
    buildheap(a,n);
    
    // loop - buildheap
    
    int hl = n-1;
    
    while(hl>0){
        int t = a[hl];
        a[hl]=a[0];
        a[0]=t;
        hl--;
        heapify(a,0,hl);
    }
    
        
}

int main()
{
    faio
    int n;
    
    
    if(fopen("input.txt","r")){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    
    cin>>n;
    int a[n];
    
    
    for(int i=0;i<n;i++) cin>>a[i];
    
    heapsort(a,n);
    
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
