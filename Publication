#include <iostream> 
#include <fstream>  // file handling class 
using namespace std; 
class Employee 
{ 
string name; 
int ID; 
double salary; 
public: 
void accept() 
{ 
cout<<"Enter name : "; 
getline(cin >> ws, name); 
cout<<"Enter ID : "; 
cin>>ID; 
cout<<"Enter salary : "; 
cin>>salary; 
} 
void display() 
{ 
cout<<"Name : "<<name<<endl; 
cout<<"ID : "<<ID<<endl; 
cout<<"Salary : "<<salary<<endl; 
} 
}; 
int main() 
{ 
Employee o[5]; 
fstream f; 
int i, n; 
f.open("demo1.txt", ios::out); 
cout<<"Enter the number of employees you want to store : "; 
cin>>n; 
for(i=0; i<n; i++) 
{ 
cout<<"Enter the information of employee: "<<i+1<<endl; 
o[i].accept(); 
f.write((char*)&o[i], sizeof o[i]); 
} 
f.close(); 
f.open("demo1.txt", ios::in); 
cout<<"Information of employee is as follows"<<endl; 
for(i=0; i<n; i++) 
{ 
cout<<"Employee"<<i+1<<endl; 
f.write((char*)&o[i], sizeof o[i]); 
o[i].display(); 
} 
f.close(); 
return 0; 
}
