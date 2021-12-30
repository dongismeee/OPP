#include <iostream>
#include <math.h>
using namespace std;
class Shape {
	public:
		Shape(){
		};
		virtual void nhap() = 0;
		virtual void xuat() = 0;
		virtual float chuvi()= 0;
		virtual float dientich() = 0;
		friend float sumcv();
		friend float sumdt();
};
class Round:public Shape {
	private:
		float r;
	public:
		Round(){
			r=0;
		};
		void nhap(){
			fflush(stdin);
			cout<<"\nNhap ban kinh hinh tron: ";
			cin>>r;
		};
		void xuat(){
			cout<<"\nBan kinh: "<<r;
			cout<<"\nChu vi hinh tron: "<<chuvi();
			cout<<"\nDien tich hinh tron: "<<dientich();
		};
		float chuvi(){
			return 2*3.14*r;
		};
		float dientich(){
			return 3.14*r*r;	
		};			
};
class rec:public Shape {
	private:
		float a;
		float b;
	public:
		rec(){
			a=0;
			b=0;
		};
		void nhap(){
			cout<<"\nNhap chieu rong hcn: ";
			cin>>a;
			cout<<"\nNhap chieu dai hcn: ";
			cin>>b;
		};
		void xuat(){
			cout<<"\nChieu rong: "<<a;
			cout<<"\nChieu dai; "<<b;
			cout<<"\nChu vi hinh hcn: "<<chuvi();
			cout<<"\nDien tich hinh hcn: "<<dientich();
		};
		float chuvi(){
			return 2*(a+b);
		};
		float dientich(){
			return a*b;	
		};			
};
class tri:public Shape {
	private:
		float x, y, z;
	public:
		tri(){
			x=0;
			y=0;
			z=0;
		};
		void nhap(){
			cout<<"\nNhap canh thu 1 cua tam giac: ";
			cin>>x;
			cout<<"\nNhap canh thu 2 cua tam giac: ";
			cin>>y;
			cout<<"\nNhap canh thu 3 cua tam giac: ";
			cin>>z;
		};
		void xuat(){
			cout<<"\nCanh thu 1: "<<x;
			cout<<"\nCanh thu 2: "<<y;
			cout<<"\nCanh thu 3: "<<z;
			cout<<"\nChu vi hinh tam giac: "<<chuvi();
			cout<<"\nDien tich hinh tam giac: "<<dientich();
		};
		float chuvi(){
			return x+y+z;
		};
		float ncv(){
			return chuvi()/2;
		};
		float dientich(){
			return sqrt((ncv())*(ncv()-x)*(ncv()-y)*(ncv()-z));	
		};			
};
void sumcv(Shape * a[], int n){
	float sum1=0;
	for(int i=0;i<n;i++){
		sum1 += a[i]->chuvi();
	};
	cout<<"\nTong chu vi cua cac hinh la: "<<sum1<<endl;	
};
void sumdt(Shape * a[], int n){
	float sum2=0;
	for(int i=0;i<n;i++){
		sum2 += a[i]->dientich();
	}
	cout<<"\nTong dien tich cac hinh la: "<<sum2<<endl;
};
int main(){
	Shape *a[100];
	int n, i, chon;
	cout<<"\nNhap so luong hinh: ";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"\n1.Hinh tron--";
		cout<<"\n2.Hinh chu nhat--";
		cout<<"\n3.Hinh tam giac--";
		cout<<"\n4.Thoat!"<<endl;
		cout<<"\nNhap sua lua chon: ";
		cin>>chon;
		if(chon==1){
		a[i]= new Round();	
		}
		if(chon==2){
		a[i]= new rec();	
		}
		if(chon==3){
		a[i]= new tri();	
		}
		a[i]->nhap();
	};
	for(i=0;i<n;i++){
		cout<<"\nThong tin hinh thu "<<i+1<<endl;
		a[i]->xuat();
	};
	sumcv(a,n);
	sumdt(a,n);
	cout<<endl;
	return 0;
} 
