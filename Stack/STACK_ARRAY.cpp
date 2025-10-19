//Stack using the array
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int stack[100],top=-1;

void push(int p)
{   
    top++;
    stack[top]=p;

}


int pop()
{
    int temp;
    if(top==-1)
    {
        return -1;
    }
    else{
        temp=stack[top];
        top--;
        return temp;
    }
   
}

int peek()
{
    int t;
    if(top==-1)
    {
        return -1;
    }
    else{
      
        t=stack[top];
    }
    return t;
}

int isempty()
{
    if(top==-1)
    {
        return 1;
    }
    else {
        return 0;
    }
}


int main() {
 int d,choice;
    cin>>d;
 for(int i=0;i<d;i++)
 { 
     cin>>choice;

switch(choice)
{
    case 1:
        int p;
        cin>>p;
        push(p);
        break;
            
    case 2 :
            cout<<pop()<<endl;
        break;
    case 3 :
            cout<<peek()<<endl;
        break;
    case 4: 
            cout<<isempty()<<endl;
                break;
}
}
    
    
    return 0;   
}
