#include<iostream>
using namespace std;

class student
{
    private:
     string name;
     string Class;
     string div;
     string rollno;
     int age;
     string dob;
     string bg;
     string gender;
     long int mobileno;
     long int lisenno;

     public:
    student() //default constructor
    {
        cout<<"constructor is invoked"<<endl;
    }
    student( student& ptr) //copy constructor;
    {
        name=ptr.name;
    }
    ~student() //distructor
    {
        cout<<"distructor is invoked"<<endl;   
    }
     static int count;
     //ount=10;
     static void counting() //static data member function
     {
        count++;
        cout<<"static count is"<<count<<endl;

     }
    
     void dynamic() //dyanamic memory allocation
     {
        int *value=new int(10);
        cout<<"output value"<<value<<endl;
        cout<<"This point adrres: "<<this<<endl;

     }

     inline void getdata(); //inline function
     friend class Display; //friend class
     //void display();

};

int student::count=10;
inline void student::getdata()
{
    cout<<"Enter the name: ";
    getline(cin>>ws,name);
    cout<<"Enter class: ";
    getline(cin>>ws,Class);
    cout<<"Enter Division: ";
    getline(cin>>ws,div);
    cout<<"Enter roll number: ";
    getline(cin>>ws,rollno);
    cout<<"enter age: ";
    cin>>age;
    cout<<"Enter the date of birth: ";
    getline(cin>>ws,dob);
    cout<<"Enter blood group: ";
    getline(cin>>ws,bg);
    cout<<"Enter gender: ";
    getline(cin>>ws,gender);
    cout<<"Enter mobile number: ";
    cin>>mobileno;
    cout<<"Enter lisen number: ";
    cin>>lisenno;
}

class Display
{
public:

 void display(student & x)
 {
  cout<<"Student information"<<endl;
  cout<<"Student name: "<<x.name<<endl;
  cout<<"Class: "<<x.Class<<endl;
  cout<<"Division: "<<x.div<<endl;
  cout<<"ROLL number: "<<x.rollno<<endl;
  cout<<"Age: "<<x.age<<endl;
  cout<<"Date of birth: "<<x.dob<<endl;
  cout<<"Blood Group: "<<x.bg<<endl;
  cout<<"Gender: "<<x.gender<<endl;
  cout<<"Mobile Number: "<<x.mobileno<<endl;
  cout<<"Lisen number: "<<x.lisenno<<endl;
 }
};

int main()
{
    student obj;
   Display obj2;
    obj.getdata();
    obj.counting();
    obj2.display(obj);
    obj.dynamic();
return 0;
    }
