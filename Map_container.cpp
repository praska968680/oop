#include<iostream> 
#include<map> 
#include<string.h> 
using namespace std; 
int main() 
{ 
typedef map<string,int>mapType; 
mapType populationMap; 
string a; 
int b,n; 
cout<<"Enter the Number of values you want to add: "; 
cin>>n; 
for(int i=0;i<n;i++) 
{ 
cout<<"Enter key: "<<endl; 
getline(cin>>ws,a); 
cout<<"Enter Value: "<<endl; 
cin>>b; 
populationMap.insert(pair<string,int>(a,b)); 
} 
mapType::iterator iter; 
cout<<"The size of Population Map is: "<<populationMap.size()<<endl; 
string statename; 
cout<<"Enter name of the state: "; 
getline(cin>>ws,statename); 
iter=populationMap.find(statename); 
if (iter != populationMap.end()) 
cout<<statename<<"'s population is "<<iter->second<<endl; 
else 
cout<<"Key is not in the Populatin Map"<<endl; 
populationMap.clear(); 
return 0; 
} 
