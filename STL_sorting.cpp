#include<iostream> 
#include<algorithm> 
#include<vector> 
using namespace std; 
class item 
{ 
public: 
char name[50]; 
int quantity,cost,code; 
bool operator==(const item &i1) 
{ 
if (code==i1.code) 
return 1; 
return 0; 
} 
bool operator<(const item &i1) 
{ 
if (code<i1.code) 
return 1; 
return 0; 
} 
}; 
vector<item>o1; 
void print(item &i1); 
void display(); 
void search(); 
void sort(); 
void dlt(); 
void insert(); 
bool compare(const item &i1,const item &i2) 
{ 
return i1.cost<i2.cost; 
} 
int main() 
{ 
int ch; 
do 
{ 
cout<<"1.Insert \n2.Display \n3.Search \n4.Sort \n5.Delete \n6.EXIT"; 
cout<<"\nEnter your choice:"; 
cin>>ch; 
switch(ch) 
{ 
case 1:insert(); 
break; 
case 2:display(); 
break; 
case 3:search(); 
break; 
case 4:sort(o1.begin(),o1.end(),compare); 
cout<<"Sorted on cost\n"; 
display(); 
break; 
case 5:dlt(); 
break; 
case 6:exit(0); 
} 
} 
while(ch!=7); 
{ 
return 0; 
} 
} 
void insert() 
{ 
item i1; 
cout<<"Enter item Name:"; 
cin>>i1.name; 
cout<<"Enter item quantity:"; 
cin>>i1.quantity; 
cout<<"Enter item cost:"; 
cin>>i1.cost; 
cout<<"Enter item code:"; 
cin>>i1.code; 
o1.push_back(i1); 
} 
void display() 
{ 
for_each(o1.begin(),o1.end(),print); 
} 
void print(item &i1) 
{ 
cout<<"Item Name:"<<i1.name; 
cout<<"\nItem quanity:"<<i1.quantity; 
cout<<"\nItem cost:"<<i1.cost; 
cout<<"\nItem code:"<<i1.code<<endl; 
} 
void search() 
{ 
vector<item>::iterator P; 
item i1; 
cout<<"Enter Item code is search:\n"; 
cin>>i1.code; 
P=find(o1.begin(),o1.end(),i1); 
if(P==o1.end()) 
{ 
cout<<"Not found\n"; 
} 
else 
{ 
cout<<"Found\n"; 
} 
} 
void dlt(){ 
vector<item>::iterator P; 
item i1; 
cout<<"Enter Item code to delete:"; 
cin>>i1.code; 
P=find(o1.begin(),o1.end(),i1); 
if(P==o1.end()) 
{ 
cout<<"Not found\n"; 
} 
else 
{ 
o1.erase(P); 
cout<<"delete\n"; 
} 
} 
