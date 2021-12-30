#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <iomanip.h>
using namespace std;
int ucln(int a,int b){
	a=abs(a);
	b=abs(b);
	while(a!=b)
		{
		if(a>b)
			a=a-b;
		else
			b=b-a;	
	    }
	return a;
}
class phanso 
{
	private:
	 	float t ,m ;
	public:
		phanso(float tu=0, float mau=1)
		{
			t=tu;
			m=mau;
		}
		~phanso(){
			
		};
		friend istream& operator >>(istream & is ,phanso &);
		friend ostream& operator <<(ostream & os ,phanso );
		phanso operator +(phanso & p)
		{
			phanso ps;
			ps.t=this->t*p.m +p.t*this->m;
			ps.m=this->m*p.m;
			return ps.toigian();
		};
		phanso operator -(phanso & p)
		{
			phanso ps;
			ps.t=this->t*p.m -p.t*this->m;
			ps.m=this->m*p.m;
			return ps.toigian();
		}
		phanso operator *(phanso & p)
		{
			phanso ps;
			ps.t=this->t*p.t;
			ps.m=this->t*p.m;
			return ps.toigian();
		}	
		phanso operator /(phanso & p)
		{
			phanso ps;
			ps.t=this->t*ps.m;
			ps.m=this->m*ps.t;
			return ps.toigian();
		}
		phanso toigian(){
			phanso p;
			p.t=t/ucln(t,m);
			p.m=m/ucln(t,m);
			return p;
		}
};
istream& operator >>(istream & is , phanso & ps)
{
	fflush(stdin);
	cout<<"\nNhap tu so: ";
	is>>ps.t;
	cout<<"\Nhap mau so: ";
	is>>ps.m;
	return is;
}
ostream& operator <<(ostream & os ,phanso ps)
{
	os<<ps.t<<"/"<<ps.m;
	return os;
}
int main()
{
	phanso p ,p1,p2;
	cout<<"\nNhap phan so thu nhat:"<<endl;
	cin>>p1;
	cout<<"\nNhap phan so thu hai: "<<endl;
	cin>>p2;
	cout<<"\n\n\nCac phan so vua nhap la:"<<endl;
	cout<<p1;
	cout<<" va ";
	cout<<p2;
	p=p1+p2;
	 cout<<"\nTong 2 ps la: ";
	 cout<<p;
	p=p1-p2;
	 cout<<"\nHieu 2 ps la: ";
	 cout<<p;
	p=p1*p2;
		cout<<"\nTich 2 ps la: ";
		cout<<p;
	p=p1/p2;
		cout<<"\nThuong 2 ps la: ";
		cout<<p;
	cout<<"\n\n______________end_____________";
	getch();
	return 0;		  
	
}