#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for(int i=1;i<n;i++)
    {
       int key=a[i];
       int j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    
    for(int i=0;i<n;i++)
    {
       cout<<a[i]<<" ";
    }
       
    return 0;
}
