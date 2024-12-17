#include<iostream> 
using namespace std; 
class publication 
{ 
public: 
string title; 
float price; 
}; 
class book:public publication 
{ 
public: 
int pagecount; 
void info() 
{ 
cout<<"\nDetails of book publication"<<endl; 
cout<<"Enter the title: "<<endl; 
getline(cin,title); 
cout<<"Enter the price: "<<endl; 
cin>>price; 
cout<<"Enter page count: "<<endl; 
cin>>pagecount; 
if(title==" " || price<=0 || pagecount<=0) 
{ 
title="Empty"; 
price=0.0; 
pagecount=0; 
} 
} 
void display() 
{ 
cout<<"\nDetails of Book publication"<<endl; 
cout<<"The title of the book publication is: "<<title<<endl; 
cout<<"The price of the book publication is: "<<price<<endl; 
cout<<"The page count of the book is: "<<pagecount<<endl; 
} 
}; 
class tape:public publication 
{ 
public: 
float play_time; 
void details() 
{ 
cout<<"\nDetails of audio tape publication"<<endl; 
cout<<"Enter the title: "<<endl; 
cin>>title; 
cout<<"Enter the price: "<<endl; 
cin>>price; 
cout<<"Enter audio play time in minutes: "<<endl; 
cin>>play_time; 
if(title==" " || price<=0 || play_time<=0) 
{ 
title="Empty"; 
price=0.0; 
play_time=0; 
} 
} 
void display() 
{ 
cout<<"\nDetails of audio tape "<<endl; 
cout<<"The title of the audio tape publication is: "<<title<<endl; 
cout<<"The price of audio tape is: "<<price<<endl; 
cout<<"The audio play time is: "<<play_time<<" minutes"<<endl; 
} 
}; 
int main() 
{ 
book b; 
tape t; 
b.info(); 
t.details(); 
b.display(); 
t.display(); 
return 0; 
} 
 
