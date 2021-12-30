#include <iostream.h>
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
	cout<<"\n\tNhap tu so: ";
	is>>ps.t;
	cout<<"\n\tNhap mau so: "; 
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
	system("color 1E");
	phanso *p ;
	int n;
	cout<<"\nNhap so phan so: ";
	cin>>n;
	p= new phanso[n];
	cout<<"\tdanh sach phan so"<<endl;
	for(int i=0;i<n;i++)
		{
			cout<<"\nNhap phan so thu "<<i+1<<endl;
			cin>>p[i];
		} 
	for(int i=0;i<n;i++)
		{
	 			cout<<"\nPhan so thu "<<i+1<<":";
			 	cout<<p[i];
		}
	phanso p1 ;
	
	cout<<"\n chon 2 phan so: ";
	int a ,b ;
	cin>>a;
	cout<<" va ";
	cin>>b;
	cout<<"\ntong 2 phanso: ";
	for(int i=0;i<n;i++)
	{
		p1= p[a]+p[b];
		
	}
 	cout<<p1;
  	cout<<"\nHieu 2 phanso: ";
	for(int i=0;i<n;i++)
	{
		p1= p[a]-p[b];
		
	}
 	cout<<p1;
	cout<<"\nTich 2 phanso: ";
	for(int i=0;i<n;i++)
	{
		p1= p[a]*p[b];
		
	}
 	cout<<p1;
	cout<<"\nThuong 2 phanso: ";
	for(int i=0;i<n;i++)
	{
		p1= p[a]/p[b];
		
	}
 	cout<<p1;  	
	cout<<"\n\n______________end_____________";
	system("pause");
	return 0;		  
	
}