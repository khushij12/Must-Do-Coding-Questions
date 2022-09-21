//radixsort, heapsort, 
#include <bits/stdc++.h>
#define faio ios::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

void radixsort(int a[],int st,int end,int n){
    int mx = *max_element(a,a+n);
    
    int cnt = 0;
    
    for(int i = mx;i!=0;i/=10) cnt++;
    map<int,vector<int>> mp;
        
    int p=1;
    while(cnt--){
        mp.clear();
        
        for(int i=0;i<n;i++){
            mp[(a[i]/p)%10].push_back(a[i]);
        }
        
        p*=10;
        int k=0;
        for(int i=0;i<=9;i++)
        for(auto x:mp[i])
        a[k++]=x;
        
        
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
    
    radixsort(a,0,n-1,n);
    
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
