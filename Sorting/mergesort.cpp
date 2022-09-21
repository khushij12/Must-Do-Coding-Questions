//mergesort, radixsort, heapsort, 
#include <iostream>
#define faio ios::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

void mergeArray(int a[],int st,int end,int n){
    if(st<end){
        int b[n];
        
        
        int md = st+(end-st)/2;
         int i=st,j=md+1,k=st;
        
        while(i<=md || j<=end){
            if(i<=md && j<=end){
                if(a[i]<a[j]){
                    b[k++]=a[i];
                i++;
                }else{
                    b[k++] = a[j];
                j++;
                }
                
            }else if(i<=md){
                b[k++]=a[i];
                i++;
            }else if(j<=end){
                b[k++] = a[j];
                j++;
            }
            else break;
        }
        
        for(i=st;i<=end;i++)
        a[i]=b[i];
    }
}
void mergesort(int a[],int st,int end,int n){
    if(st<end){
        int md = st+(end-st)/2;
        // for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
        
        mergesort(a,st,md,n);
        mergesort(a,md+1,end,n);
        mergeArray(a,st,end,n);
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
    
    mergesort(a,0,n-1,n);
    
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
