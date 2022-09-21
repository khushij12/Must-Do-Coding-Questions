 //quicksort, mergesort, radixsort, heapsort, 
#include <iostream>
#define faio ios::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int partition(int a[],int st,int end,int n){
    int loc = st;
    
    while(1){
        while(loc!=end && a[loc]<=a[end]) end--;
        
        if(loc == end) return loc;
        
        int t = a[loc];
        a[loc]=a[end];
        a[end]=t;
        
        loc = end;
        
        while(loc!=st && a[st]<=a[loc]) st++;
        
        if(loc ==st) return loc;
        
        t = a[loc];
        a[loc]=a[st];
        a[st]=t;
        
        loc = st;
    }
    return 0;
}

void quicksort(int a[],int st,int end,int n){
    if(st<end){
        int pivot = partition(a,st,end,n);
        // for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
        
        quicksort(a,st,pivot,n);
        quicksort(a,pivot+1,end,n);
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
    
    quicksort(a,0,n-1,n);
    
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
