#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class phanso{
	private:
		int t;
		int m;
	public:
		phanso(int ts=0, int ms=1){
			t=ts;
			m=ms;	
		};
		~phanso(){
			
		};
		void nhap();
		void in();
		int Getts();
		int Getms();
		int ucln(int t, int m);
		phanso tong(phanso p2)
			{
			phanso p;
			int k;
			p.t=this->t*p2.m+this->m*p2.t;
			p.m=this->m*p2.m;
			k=ucln(p.Getts(),p.Getms());
			p.t=p.t/k;
			p.m=p.m/k;
			return p;
			};	
};
int phanso::ucln(int t,int m){
	t=abs(t);
	m=abs(m);
	if(t*m==0) return 1;
	while(t!=m){
		if(t>m) t-=m;
		else m-=t;
	}
	return t;
}
void phanso::nhap(){
	cout<<"\nNhap tu so :";
	cin>>t;
	do{
		cout<<"\nNhap mau so:";
		cin>>m;
		if(m==0)
		cout<<"\nban da nhap sai so!!! :)";
		}while(m==0);
}
int phanso::Getts(){
	return t;
}
int phanso::Getms(){
	return m;
}	
void phanso::in(){
	cout<<t<<"/"<<m<<endl; 
} 
int main()
{
	phanso p1, p2, tong;
	p1.nhap();
	p2.nhap();
	tong=p1.tong(p1);
	cout<<"\nTong hai phan so da nhap la: ";
	tong.in();
	return 0;	
}
	