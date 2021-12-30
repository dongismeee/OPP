#include <iostream>
#include <math.h>
using namespace std;
class DaThuc3
{
	private:
		int a, b, c ,d;
	public:
		DaThuc3(int da=0, int db=0, int dc=0, int dd=0)
		{
			a=da;
			b=db;
			c=dc;
			d=dd;
		};
		friend istream& operator >>(istream & ,DaThuc3 &);
		friend ostream& operator <<(ostream & ,DaThuc3 );
		DaThuc3 operator + (DaThuc3 &p2){
		DaThuc3 p3;
		p3.a = this->a + p2.a;
		p3.b = this->b + p2.b;
		p3.c = this->c + p2.c;
		p3.d = this->c + p2.d;
		return p3;
	}
	
	DaThuc3 operator - (DaThuc3 &p2){
		DaThuc3 p3;
		p3.a = this->a - p2.a;
		p3.b = this->b - p2.b;
		p3.c = this->c - p2.c;
		p3.d = this->c - p2.d;
		return p3;
	}		
};
istream& operator>>(istream & is, DaThuc3 & dt)
{
	cout<<"\nNhap a: ";
	is>>dt.a;
	cout<<"\nNhap b: ";
	is>>dt.b;
	cout<<"\nNhap c: ";
	is>>dt.c;
	cout<<"\nNhap d: ";
	is>>dt.d; 
	return is;
};
ostream& operator<<(ostream & os ,DaThuc3 dt)
{
	os<<"("<<dt.a<<"x^3)"<<"+"<<"("<<dt.b<<"x^2)"<<"+"<<"("<<dt.c<<"x)"<<"+"<<"("<<dt.d<<")"<<endl;
	return os; 		 
};
int main()
{
	DaThuc3 p1,p2,p3;
	
	cout<<"\n\tNhap vao da thuc bac 3"<<endl;
	cout<<"\nNhap vao da thuc 1: "<<endl; cin>>p1;
	cout<<"\nNhap vao da thuc 2: "<<endl;; cin>>p2;
	
	cout<<"\nDa thuc 1: "<<p1;
	cout<<"\nDa thuc 2: "<<p2;
	p3 = p1 + p2;
	cout<<"\nTong 2 da thuc: "<<p3;
	p3 = p1 - p2;
	cout<<"\nHieu 2 da thuc: "<<p3<<endl;
	
	cout<<endl;
}