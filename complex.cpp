#include<iostream>
using namespace std;
class Complex
{   
     public:
     	double real;
	    double image;
	    double temp;
	    Complex();
		friend istream & operator >>(istream & , Complex &);
		friend ostream & operator <<(ostream & , const Complex &);
		Complex operator+(const Complex&); // Addition
        Complex operator*(const Complex&);//multiplication
};
Complex :: Complex()
{
	real=0;
	image=0;
}
istream & operator >>(istream & in , Complex & c)
{
	in>>c.real>>c.image;
	return in;
}
ostream & operator <<(ostream & out, const Complex &c)
{
	out<<c.real<<"+"<<c.image<<"i"<<endl;
	return out;
}
Complex Complex::operator+(const Complex& other)
 {
    Complex temp;
    temp.real = real + other.real;
    temp.image = image + other.image;
    return temp;
}

Complex Complex::operator*(const Complex& other) {
    Complex temp;
    temp.real = (real * other.real) - (image * other.image);
    temp.image = (real * other.image) + (image * other.real);
    return temp;
}
int main(void)
{
	Complex n1,n2;
	cout<<"Enter the values for real and imaginary part 1 :"<<endl;
	cin>>n1;
	cout<<"Enter the values for real and imaginary part 2 :"<<endl;
	cin>>n2;
	
	Complex sum = n1 +n2;
	Complex mul = n1 * n2;
	
	cout<<"Sum :"<<sum<<endl;
	cout<<"Multiplication :"<<mul;
	return 0;
}

