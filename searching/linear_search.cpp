#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a[100],n,k;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
}
    cin>>k;
    
      int cmp=0;
    for(int i=0;i<n;i++)
    {
        cmp++;
        if(a[i]==k)
        {
            cout<<i<<endl;
            cout<<cmp;  
            return 0;
        }
          
    }
      cout<<"Element "<<k<< " is not present in the array"<<endl;
        cout<<cmp;
    return 0;
}
