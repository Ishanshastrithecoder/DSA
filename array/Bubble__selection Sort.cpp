/*
Problem statement :
Instructors have given one problem to students. Students have to solve and implement the program in maximum 60 minutes. After contest, Instructor has the submission time (in minutes) in which every student has submitted the correct solution.

Help the instructor to find the top 2 students who have submitted correct problem fastest.

Input for this program is roll number, roll_no and time to submit the solution in minutes, submissiontime for n students.

Explanation:

Input will be: n=5 (number of students)

roll_no: 1,4,5,7,10

submissiontime= 34,60,42,35,21

1 (for Bubble Sort)

2 (for Selection Sort)

Output can be:

case 1: Bubble Sort :

21,34,35,42,60

No of swaps : 7

case 2: Selection Sort :

21,34,35,42,60

No of swaps : 3

Top 2 students : roll no : 10 and 1

Input Format

First line contains the integer, the number of students n
next lines have two integers , roll_no and submission time for n students.
Third Line is interger, either 1. for bubble sort or 2 for selection sort
Constraints

1 < n < 50
1 < roll_no < 190 ; 1 < submission time < 60
Output Format

First line is sorted data according to time.
next line of output shows the number of comparisons required to sort data.
next line is number of swaps required to sort data.
Next line is top two performers' roll numbers.
*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//BUBBLE SORT
void bubble_sort(int n,int roll[],int subtime[])
{
    
    int swap=0,comparison=0;
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
                    comparison++;
            if(subtime[j]>subtime[j+1])
            {
                int temp=subtime[j];
                subtime[j]=subtime[j+1];
                subtime[j+1]=temp;
                
                int r=roll[j];
                roll[j]=roll[j+1];
                roll[j+1]=r;
                
                swap++;
            }
            
        }
        if(swap==0)
        {
            break;
        }
        
    }
    for(int i=0;i<n;i++)
    {
        cout<<roll[i]<<" "<<subtime[i]<<endl;
        
    }
    cout<<comparison<<endl<<swap<<endl<<roll[0]<<","<<roll[1];
}



//SELECTION SORT 
void selection(int n ,int roll[1000],int subtime[1000])
{
     int swap=0,comparison=0;
    
    for(int i=0;i<n-1;i++)
    {   
        int min=i;
        for(int j=i+1;j<n;j++)
        {
                    comparison++;
                        if(subtime[j]<subtime[min])
                        {
                            min=j;
                        }
        }
            if(min!=i)
            {
                int temp=subtime[i];
                subtime[i]=subtime[min];
                subtime[min]=temp;
                
                int r=roll[i];
                roll[i]=roll[min];
                roll[min]=r;
                
                swap++;
            }
            
        
    }
    for(int i=0;i<n;i++)
    {
        cout<<roll[i]<<" "<<subtime[i]<<endl;
        
    }
    cout<<comparison<<endl<<swap<<endl<<roll[0]<<","<<roll[1];

}
int main() {
    

    int n,roll[1000],sub_time[1000],choice;
    cin>>n;
    for(int i=0;i<n;i++){
    cin>>roll[i]>>sub_time[i];
    }
    cin>>choice;
    if(choice ==1){
    bubble_sort(n,roll,sub_time);
    }
    else {
        selection(n,roll,sub_time);
    }
    
    return 0;
    
}
