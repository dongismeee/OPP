#include <iostream>
#include <math.h>
using namespace std;
class Sophuc {
	public:
		Sophuc();
		friend istream& operator >>(istream & ,Sophuc &);
		friend ostream& operator <<(ostream &,Sophuc );
	private:
		int pt;
		int pa;		
};
 Sophuc::Sophuc(){
 	pt=0;
 	pa=0;	
 }
 istream& operator>>(istream & is, Sophuc & a){
 	cout<<"\nNhap phan thuc: ";
	is>>a.pt;
	cout<<"\nNhap phan ao: ";
	is>>a.pa;
	return is;		
 }
 ostream& operator<<(ostream &os, Sophuc a)
 {
 	if(a.pa>=0)
 		os<<a.pt<<"+j*"<<a.pa<<endl;
 	else
	 	os<<a.pt<<"-j*"<<fabs(a.pa)<<endl;	
	 	return os;
 }
int main()
{
	Sophuc a;
	cin>>a;
	cout<<a;
	return 0;
}		