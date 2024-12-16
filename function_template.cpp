#include<iostream> 
using namespace std; 
int n; 
#define size 10 
template<class T> 
void set(T A[size]) 
{ 
int i,j,min; 
T temp; 
for (i=0;i<n-1;i++) 
{ 
min=i; 
for (j=i+1;j<n;j++) 
{ 
if (A[j]<A[min]) 
{ 
min=j; 
} 
temp =A[i]; 
A[i]=A[min]; 
A[min]=temp; 
}} 
cout<<"Sorted array : "<<endl; 
for (i=0;i<n;i++) 
{ 
cout<<A[i]<<"\t"; 
} 
}; 
int main() 
{ 
int A[size]; 
float B[size]; 
int i; 
int ch; 
do 
{ 
cout<<"\n1.Integer value"; 
cout<<"\n2.Float value"; 
cout<<"\n3.Exit"; 
cout<<"\nEnter your choice:"<<endl; 
cin>>ch; 
switch (ch) 
{ 
case 1: 
cout<<"Enter total no. of integer elements:"; 
cin>>n; 
cout<<"Enter integer elements:"; 
for (i=0;i<n;i++) 
{ 
cin>>A[i]; 
} 
set(A); 
break; 
case 2: 
cout<<"Enter total no. of float elements: "; 
cin>>n; 
cout<<"Enter float elements: "; 
for (i=0;i<n;i++) 
{ 
cin>>B[i]; 
} 
set(B); 
break; 
case 3: 
exit (0); 
} 
} 
while (ch!=3); 
return 0; 
} 
